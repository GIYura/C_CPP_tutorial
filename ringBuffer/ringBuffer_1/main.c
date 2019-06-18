/// RING BUFFER
#define EXAMPLE_BUFFER_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct{
    uint8_t* buffer;
    size_t head;
    size_t tail;
    size_t max;
    bool full;
}circular_buf_t;

typedef circular_buf_t* cbuf_handle_t;

///First, we should think about how users will interact with a circular buffer:
/*
They need to initialize the circular buffer container with a buffer and size
They need to destroy a circular buffer container
They need to reset the circular buffer container
They need to be able to add data to the buffer
They need to be able to get the next value from the buffer
They need to know whether the buffer is full or empty
They need to know the current number of elements in the buffer
They need to know the max capacity of the buffer
*/

//void circular_buf_reset(cbuf_handle_t cbuf);
/// Pass in a storage buffer and size
/// Returns a circular buffer handle
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size);

/// Free a circular buffer structure.
/// Does not free data buffer; owner is responsible for that
void circular_buf_free(cbuf_handle_t cbuf);

/// Reset the circular buffer to empty, head == tail
void circular_buf_reset(cbuf_handle_t cbuf);

/// Put version 1 continues to add data if the buffer is full
/// Old data is overwritten
void circular_buf_put(cbuf_handle_t cbuf, uint8_t data);

/// Put Version 2 rejects new data if the buffer is full
/// Returns 0 on success, -1 if buffer is full
int circular_buf_put2(cbuf_handle_t cbuf, uint8_t data);

/// Retrieve a value from the buffer
/// Returns 0 on success, -1 if the buffer is empty
int circular_buf_get(cbuf_handle_t cbuf, uint8_t * data);

/// Returns true if the buffer is empty
bool circular_buf_empty(cbuf_handle_t cbuf);

/// Returns true if the buffer is full
bool circular_buf_full(cbuf_handle_t cbuf);

/// Returns the maximum capacity of the buffer
size_t circular_buf_capacity(cbuf_handle_t cbuf);

/// Returns the current number of elements in the buffer
size_t circular_buf_size(cbuf_handle_t cbuf);

///
void print_buffer_status(cbuf_handle_t cbuf);

/**/
/**/
/**/
int main()
{
    uint8_t* buffer = malloc(EXAMPLE_BUFFER_SIZE * sizeof(uint8_t));

	printf("\n=== C Circular Buffer Check ===\n");

	cbuf_handle_t cbuf = circular_buf_init(buffer, EXAMPLE_BUFFER_SIZE);

	printf("Buffer initialized. ");
	print_buffer_status(cbuf);

	printf("\n******\nAdding %d values\n", EXAMPLE_BUFFER_SIZE - 1);
	for(uint8_t i = 0; i < (EXAMPLE_BUFFER_SIZE - 1); i++)
	{
		circular_buf_put(cbuf, i);
		printf("Added %u, Size now: %zu\n", i, circular_buf_size(cbuf));
	}
	print_buffer_status(cbuf);

	printf("\n******\nAdding %d values\n", EXAMPLE_BUFFER_SIZE);
	for(uint8_t i = 0; i < EXAMPLE_BUFFER_SIZE; i++)
	{
		circular_buf_put(cbuf, i);
		printf("Added %u, Size now: %zu\n", i, circular_buf_size(cbuf));
	}
	print_buffer_status(cbuf);

    return 0;
}
/**/
/**/
/**/
///
cbuf_handle_t circular_buf_init(uint8_t* buffer, size_t size){
    assert(buffer && size);

    cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));
    assert(cbuf);

    cbuf->buffer = buffer;
    cbuf->max = size;
    //circular_buf_reset(cbuf);
    cbuf->full = false;
    cbuf->head = 0;
    cbuf->tail = 0;

    assert(circular_buf_empty(cbuf));

    return cbuf;
}

///
/*
void circular_buf_reset(cbuf_handle_t cbuf)
{
    assert(cbuf);

    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->full = false;
}*/

///
void circular_buf_free(cbuf_handle_t cbuf)
{
    assert(cbuf);
    free(cbuf);
}

///
bool circular_buf_full(cbuf_handle_t cbuf)
{
    assert(cbuf);

    return cbuf->full;
}

///
bool circular_buf_empty(cbuf_handle_t cbuf)
{
    assert(cbuf);

    return (!cbuf->full && (cbuf->head == cbuf->tail));
}

///
size_t circular_buf_capacity(cbuf_handle_t cbuf)
{
    assert(cbuf);

    return cbuf->max;
}

///
size_t circular_buf_size(cbuf_handle_t cbuf)
{
    assert(cbuf);

    size_t size = cbuf->max;

    if(!cbuf->full)
    {
        if(cbuf->head >= cbuf->tail)
        {
            size = (cbuf->head - cbuf->tail);
        }
        else
        {
            size = (cbuf->max + cbuf->head - cbuf->tail);
        }
    }

    return size;
}

///
static void advance_pointer(cbuf_handle_t cbuf)
{
    assert(cbuf);

    if(cbuf->full)
    {
        cbuf->tail = (cbuf->tail + 1) % cbuf->max;
    }

    cbuf->head = (cbuf->head + 1) % cbuf->max;
    cbuf->full = (cbuf->head == cbuf->tail);
}

///
static void retreat_pointer(cbuf_handle_t cbuf)
{
    assert(cbuf);

    cbuf->full = false;
    cbuf->tail = (cbuf->tail + 1) % cbuf->max;
}

///
void circular_buf_put(cbuf_handle_t cbuf, uint8_t data)
{
    assert(cbuf && cbuf->buffer);

    cbuf->buffer[cbuf->head] = data;

    advance_pointer(cbuf);
}

///
int circular_buf_put2(cbuf_handle_t cbuf, uint8_t data)
{
    int r = -1;

    assert(cbuf && cbuf->buffer);

    if(!circular_buf_full(cbuf))
    {
        cbuf->buffer[cbuf->head] = data;
        advance_pointer(cbuf);
        r = 0;
    }

    return r;
}

///
int circular_buf_get(cbuf_handle_t cbuf, uint8_t * data)
{
    assert(cbuf && data && cbuf->buffer);

    int r = -1;

    if(!circular_buf_empty(cbuf))
    {
        *data = cbuf->buffer[cbuf->tail];
        retreat_pointer(cbuf);

        r = 0;
    }

    return r;
}


void print_buffer_status(cbuf_handle_t cbuf)
{
	printf("Full: %d, empty: %d, size: %zu\n",
		circular_buf_full(cbuf),
		circular_buf_empty(cbuf),
		circular_buf_size(cbuf));
}

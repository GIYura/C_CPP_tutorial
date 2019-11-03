#include <stdio.h>
#include "Fifo.h"

//
int main(int argc, char **argv)
{
	PRINTF("Application started...\r\n");
	fifo_t m_fifo;
	fifo_status_t m_fifo_status;
	uint8_t m_received;
	
	m_fifo_status = fifo_init(&m_fifo, FIFO_SIZE);
	
	if(m_fifo_status){ ERROR_HANDLER(); }
	
	m_fifo_status = fifo_clear(&m_fifo);
	
	if(m_fifo_status){ ERROR_HANDLER(); }
	
	for(int i = 0; i < 20; i++){
		uint8_t l_t[1];
		l_t[0] = i;
		m_fifo_status = fifo_push(&m_fifo, l_t);
		if(m_fifo_status){ break; }
	}
	
	for(int i = 0; i < 20; i++){
		m_fifo_status = fifo_pop(&m_fifo, &m_received);
		if(m_fifo_status){ break; }
		PRINTF("Received data: %d\r\n", m_received);
	}
	
	return 0;
}

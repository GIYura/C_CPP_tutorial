#include <stdio.h>
#include "Ring.h"

//
int main(int argc, char **argv)
{
	ring_t m_ring;
	ring_status_t m_ring_status;
	uint8_t m_received;
	
	PRINTF("Application started...\r\n");
	
	m_ring_status = ring_init(&m_ring, 16);
	if(m_ring_status){ ERROR_HANDLER(); }
	
	m_ring_status = ring_clear(&m_ring);
	if(m_ring_status){ ERROR_HANDLER(); }
	
	for(int i = 0; i < 20; i++){
		uint8_t l_t[1];
		l_t[0] = i;
		m_ring_status = ring_push(&m_ring, l_t);
		if(m_ring_status){
			break;
		}
	}
	
	for(int i = 0; i < 20; i++){
		m_ring_status = ring_pop(&m_ring, &m_received);
		if(m_ring_status){
			break;
		}
		PRINTF("Received data: %d\n", m_received);
	}
	
	return 0;
}

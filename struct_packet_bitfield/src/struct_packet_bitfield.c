#include <stdio.h>
#include <stdlib.h>

struct Packet {
	uint32_t  crc             :2;
	uint32_t  status          :1;
	uint32_t  payload         :12;
	uint32_t  bat             :3;
	uint32_t  sensor          :3;
	uint32_t  long_addr       :8;
	uint32_t  short_addr      :2;
	uint32_t  addr_mode       :1;
};


int main(void)
{



	return EXIT_SUCCESS;
}

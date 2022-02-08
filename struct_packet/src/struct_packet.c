#include <stdio.h>
#include <stdlib.h>

struct Packet {
	uint8_t  crc;
	uint8_t  status;
	uint16_t payload;
	uint8_t  bat;
	uint8_t  sensor;
	uint8_t  long_addr;
	uint8_t  short_addr;
	uint8_t  addr_mode;
};

int main(void)
{

	// @program run instruction
	// When program starts
	// Enter any 32 bit hex into terminal i.e. 0xFF23DC89

	uint32_t packet_value = 0;
	printf("Enter the 32bit packet value\n");
	scanf("%X", &packet_value);

	struct Packet packet;

	packet.crc        = (uint8_t) (packet_value & 0x3);
	packet.status     = (uint8_t) ((packet_value >> 2) & 0x1);
	packet.payload    = (uint16_t) ((packet_value >> 3) & 0xFFF );
	packet.bat        = (uint8_t) ((packet_value >> 15) & 0x7);
	packet.sensor     = (uint8_t) ((packet_value >> 18) & 0x7);
	packet.long_addr  = (uint8_t) ((packet_value >> 21) & 0xFF);
	packet.short_addr = (uint8_t) ((packet_value >> 29) & 0x3);
	packet.addr_mode  = (uint8_t) ((packet_value >> 31) & 0x1);

	printf("crc          : %#X\n", packet.crc);
	printf("status       : %#X\n", packet.status);
	printf("playload     : %#X\n", packet.payload);
	printf("bat          : %#X\n", packet.bat);
	printf("sensor       : %#X\n", packet.sensor);
	printf("long_addr    : %#X\n", packet.long_addr);
	printf("short_addr   : %#X\n", packet.short_addr);
	printf("addr_mode    : %#X\n", packet.addr_mode);

	printf("Size of struct is %llu\n", sizeof(packet));

	while(getchar() != '\n');
	getchar();


	return EXIT_SUCCESS;
}

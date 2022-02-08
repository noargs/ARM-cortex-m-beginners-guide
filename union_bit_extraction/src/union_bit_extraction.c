#include <stdio.h>
#include <stdlib.h>

union Packet
{
	uint32_t packet_value;

	struct
	{
		uint32_t  crc             :2;
		uint32_t  status          :1;
		uint32_t  payload         :12;
		uint32_t  bat             :3;
		uint32_t  sensor          :3;
		uint32_t  long_addr       :8;
		uint32_t  short_addr      :2;
		uint32_t  addr_mode       :1;
	}packet_fields;

};


int main(void)
{
	union Packet packet;
	printf("Enter the 32bit packet value\n");
	scanf("%X", &packet.packet_value);

	printf("crc          : %#X\n", packet.packet_fields.crc);
	printf("status       : %#X\n", packet.packet_fields.status);
	printf("playload     : %#X\n", packet.packet_fields.payload);
	printf("bat          : %#X\n", packet.packet_fields.bat);
	printf("sensor       : %#X\n", packet.packet_fields.sensor);
	printf("long_addr    : %#X\n", packet.packet_fields.long_addr);
	printf("short_addr   : %#X\n", packet.packet_fields.short_addr);
	printf("addr_mode    : %#X\n", packet.packet_fields.addr_mode);


	printf("Size of struct is %lu\n", sizeof(packet));

	while(getchar() != '\n');
	getchar();


	return EXIT_SUCCESS;
}

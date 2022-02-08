#include <stdio.h>
#include <stdint.h>

struct DataSet
{
	char  data1;
	int   data2;
	char  data3;
	short data4;
}__attribute__((packed));

struct DataSet data; // this consumes 12 bytes in memory(RAM)

int main(void)
{

	data.data1 = 0x11;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	printf("data.data1 = %d\n", data.data1);
	printf("data.data2 = %d\n", data.data2);
	printf("data.data3 = %d\n", data.data3);
	printf("data.data4 = %d\n", data.data4);

    /* Loop forever */
	for(;;);
}

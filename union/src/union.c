#include <stdio.h>
#include <stdlib.h>

union Address {
	uint16_t short_addr;
	uint32_t long_addr;
};

int main(void) {

	union Address addr;

	addr.short_addr = 0xFFCD;
	addr.long_addr  = 0xEEEECCCC;

	printf("short addr = %#X\n", addr.short_addr);
	printf("long addr   = %#X\n", addr.long_addr);

	getchar();

	return 0;
}

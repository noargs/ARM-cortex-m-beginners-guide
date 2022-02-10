#include <stdio.h>
#include <stdint.h>

void array_display(uint8_t const * const p_array, uint32_t n_items);

int main(void)
{
	uint8_t some_data[10] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

	uint32_t n_items = sizeof(some_data) / sizeof(uint8_t);
	array_display(some_data, n_items);

	return 0;
}

void array_display(uint8_t const * const p_array, uint32_t n_items)
{
	// lets display the contents of the received array
	for(uint32_t i = 0; i < n_items; i++)
	{
		printf("%x\t", *(p_array + i));
	}
}

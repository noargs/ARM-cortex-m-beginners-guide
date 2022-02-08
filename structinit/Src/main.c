#include <stdint.h>
#include <stdio.h>

struct carModel
{
	uint32_t carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float    carWeight;
};

int main(void)
{

	// create and initialise variable
	struct carModel car_bmw = {2021, 15000, 220, 1330};
	printf("Sizeof struct car_bmw is %l64u\n", sizeof(uint32_t));
	printf("Sizeof struct car_bmw is %l64u\n", sizeof(uint16_t));
	printf("Sizeof struct car_bmw is %l64u\n", sizeof(float));


	for(;;);
}

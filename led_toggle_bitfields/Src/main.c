#include <stdint.h>

#include "main.h"


int main(void)
{

	RCC_AHB1ENR_t volatile * const p_clock_control_reg    = (RCC_AHB1ENR_t*) 0x40023830;
	GPIOx_MODE_t volatile * const p_gpiod_mode_reg        = (GPIOx_MODE_t*) 0x40020C00;
	GPIOx_ODR_t volatile * const p_gpiod_output_data_reg  = (GPIOx_ODR_t*) 0x40020C14;

	//1. enable the control register for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
	p_clock_control_reg->gpiod_en = 1;

	//2. configure the mode register of IO pin as Output
	p_gpiod_mode_reg->pin_12 = 1;

	while(1)
	{
		// 3. SET the 12th bit of the output data register to make I/O pin-12 HIGH
		p_gpiod_output_data_reg->pin_12 = 1;

		for(uint32_t i=0; i < 300000; i++);

		// Turn OFF the LED
		p_gpiod_output_data_reg->pin_12 = 0;

		for(uint32_t i=0; i < 300000; i++);
	}
}

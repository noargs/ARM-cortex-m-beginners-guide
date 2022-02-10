#include <stdint.h>

#include "main.h"


int main(void)
{

	RCC_AHB1ENR_t volatile * const p_clock_control_reg    = ADDR_REG_AHB1ENR;
	GPIOx_MODE_t volatile * const p_gpiod_mode_reg        = ADDR_REG_GPIOD_MODE;
	GPIOx_ODR_t volatile * const p_gpiod_output_data_reg  = ADDR_REG_GPIOD_ODR;

	//1. enable the control register for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
	p_clock_control_reg->gpiod_en = CLOCK_ENABLE;

	//2. configure the mode register of IO pin as Output
	p_gpiod_mode_reg->pin_12 = MODE_CONF_OUTPUT;

	while(1)
	{
		// 3. SET the 12th bit of the output data register to make I/O pin-12 HIGH
		p_gpiod_output_data_reg->pin_12 = PIN_STATE_HIGH;

		for(uint32_t i=0; i < DELAY_COUNT; i++);

		// Turn OFF the LED
		p_gpiod_output_data_reg->pin_12 = PIN_STATE_LOW;

		for(uint32_t i=0; i < DELAY_COUNT; i++);
	}
}

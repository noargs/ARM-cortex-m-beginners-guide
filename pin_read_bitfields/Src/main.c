#include "main.h"

int main(void)
{

	RCC_AHB1ENR_t volatile * const p_clock_control_reg         = (RCC_AHB1ENR_t*) 0x40023830;

	GPIOx_MODE_t volatile * const p_gpiod_mode_reg             = (GPIOx_MODE_t*) 0x40020C00;
	GPIOx_ODR_t volatile * const p_gpiod_output_data_reg       = (GPIOx_ODR_t*) 0x40020C14;

	GPIOx_MODE_t volatile * const p_gpioa_mode_reg             = (GPIOx_MODE_t*) 0x40020000;
	GPIOx_IDR_t volatile const * const p_gpioa_input_data_reg  = (GPIOx_IDR_t*) 0x40020010;

	//1. enable the control clock register for GPIOD, GPIOA peripherals in the AHB1ENR
	p_clock_control_reg->gpioa_en = 1;
	p_clock_control_reg->gpiod_en = 1;

	//2a. configure the mode register of GPIOA PA1 pin as Input
	p_gpioa_mode_reg->pin_1 = 0;

	//2b. configure the mode register of GPIOD PD12 pin as Output
	p_gpiod_mode_reg->pin_12 = 1;



	while(1)
	{
		// read the pin status of the pin PA1 (GPIOA Input data register)
		uint8_t pin_status = (uint8_t) p_gpioa_input_data_reg->pin_1;

		if(pin_status){
			// turn ON PD12 on-board LED
			p_gpiod_output_data_reg->pin_12 = 1;
		} else {
			// turn OFF PD12 on-board LED
			p_gpiod_output_data_reg->pin_12 = 0;
		}
	}
}

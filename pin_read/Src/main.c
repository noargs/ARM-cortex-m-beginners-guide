#include <stdint.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

int main(void)
{
	uint32_t volatile * const p_clock_control_reg      = (uint32_t*)0x40023830;

	uint32_t volatile * const p_gpiod_mode_reg         = (uint32_t*)0x40020C00;
	uint32_t volatile * const p_gpiod_output_data_reg  = (uint32_t*)0x40020C14;

	uint32_t volatile * const p_gpioa_mode_reg         = (uint32_t*)0x40020000;
	uint32_t volatile const * const p_gpioa_input_data_reg   = (uint32_t*)0x40020010;

	//1. enable the control clock register (RCC) for GPIOD, GPIOA peripherals in the AHB1ENR
	// GPIOD (SET the 3rd bit position)
	*p_clock_control_reg |= (1 << 3);

	// GPIOA (SET the 0th bit position)
	*p_clock_control_reg |= (1 << 0);


	//2a. configure the mode register of the GPIOD (PD12 pin) as Output
	// a. clear the 24th and 25th positions (CLEAR)
	*p_gpiod_mode_reg &= ~(3 << 24);
	// b. make the 24th bit position as 1 (SET)
	*p_gpiod_mode_reg |= (1 << 24);

	//2b. Configure the mode register of the GPIOA (PA1 pin) as Input
	// a. clear the 3rd and 4th bit positions (CLEAR)
	*p_gpioa_mode_reg &= ~(3 << 1);


	while(1)
	{
		// read the pin status of the pin PA1 (GPIOA Input data register)
		uint8_t pin_status = (uint8_t)(*p_gpioa_input_data_reg & 0x2); // zero out all other bits except bit 1

		if(pin_status){
			// turn ON PD12 on-board LED
			*p_gpiod_output_data_reg |= (1 << 12);
		} else {
			// turn OFF PD12 on-board LED
			*p_gpiod_output_data_reg &= ~(1 << 12);
		}

	}

}

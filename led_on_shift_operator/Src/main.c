#include <stdint.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

int main(void)
{
	uint32_t *p_clock_control_reg = (uint32_t*)0x40023830;
	uint32_t *p_gpiod_mode_reg = (uint32_t*)0x40020C00;
	uint32_t *p_gpiod_output_data_reg = (uint32_t*)0x40020C14;

	//1. enable the control clock register for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
	*p_clock_control_reg |= (1 << 3);

	//2. configure the mode register of the IO pin as Output
	// a. clear the 24th and 25th positions (CLEAR)
	*p_gpiod_mode_reg &= ~(3 << 24);
	// b. make the 24th bit position as 1 (SET)
	*p_gpiod_mode_reg |= (1 << 24);

	//3. SET the 12th bit of the output data register to make I/O pin-12 HIGH
	*p_gpiod_output_data_reg |= (1 << 12);

	while(1);
}

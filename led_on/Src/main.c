#include <stdint.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

int main(void)
{
	uint32_t *p_clock_control_reg = (uint32_t*)0x40023830;
	uint32_t *p_gpiod_mode_reg = (uint32_t*)0x40020C00;
	uint32_t *p_gpiod_output_data_reg = (uint32_t*)0x40020C14;

	// 1. enable the control clock register for GPIOD peripheral in the AHB1ENR
//	uint32_t temp = *p_clock_control_reg; // read operation
//	temp = temp | 0x08; // modify
//	*p_clock_control_reg = temp; // write back

	*p_clock_control_reg |= 0x08;


	// 2. configure the mode register of the IO pin as output
	// a. clear the 24th and 25th positions (CLEAR)
	*p_gpiod_mode_reg &= 0xFCFFFFFF;
	// b. make the 24th bit position as 1 (SET)
	*p_gpiod_mode_reg |= 0x01000000;

	// 3. SET 12th bit of the output data register to make I/O pin-12 HIGH
	*p_gpiod_output_data_reg |= 0x1000;


	while(1);
}

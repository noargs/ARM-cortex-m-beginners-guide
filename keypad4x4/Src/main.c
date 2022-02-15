#include <stdint.h>
#include <stdio.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

/**
 *    [Free I/O available on port D] -[User manual Page: 29]-
 *    PD0, PD1, PD2, PD3, PD6, PD7, PD8, ... PD11
 *
 *
 *    -[Reference Manual Page: 64]-
 *    Base Address GPIO(D)  0x4002 0C00
 *    Base Address RCC      0x4002 3800
 *
 *
 *    [Addresses Offset]
 *	       - Mode register (GPIOD)                      0x00   -[Reference Manual Page: 281]-
 *	       - Input data register (GPIOD) 	            0x10   -[Reference Manual Page: 283]-
 *	       - Output data register (GPIOD)               0x14   -[Reference Manual Page: 283]-
 *	       - Pull-up/down register (GPIOD)              0x0C   -[Reference Manual Page: 282]-
 *	       - Clock enable register (RCC_AHB1ENR)        0x30   -[Reference Manual Page: 242]-
 */

void delay(void)
{
	for(uint32_t i = 0; i < 300000; i++);
}

int main(void)
{

	// Peripheral Register Addresses
	uint32_t volatile * p_gpiod_mode_reg         = (uint32_t*) (0x40020C00 + 0x00);
	uint32_t volatile * p_gpiod_input_data_reg   = (uint32_t*) (0x40020C00 + 0x10);
	uint32_t volatile * p_gpiod_output_data_reg  = (uint32_t*) (0x40020C00 + 0x14);
	uint32_t volatile * p_clock_control_reg      = (uint32_t*) (0x40023800 + 0x30);
	uint32_t volatile * p_gpiod_pullup_reg       = (uint32_t*) (0x40020C00 + 0x0C);


	//1. ENABLE peripheral clock of GPIOD peripheral
	*p_clock_control_reg |= (1 << 3);


	//2. Configure PD0,PD1,PD2, and PD3 as OUTPUT (keypad rows)
	*p_gpiod_mode_reg &= ~(0xFF);       // clear bits before setting
	*p_gpiod_mode_reg |= 0x55;

	//3. Configure PD8,PD9,PD10 and PD11 as INPUT (keypad columns)
	*p_gpiod_mode_reg &= ~(0xFF << 16);

	//4. Enable internal pull-up resistors for PD8 PD9 PD10 PD11
	*p_gpiod_pullup_reg &= ~(0xFF << 16); // Clear bits before setting
	*p_gpiod_pullup_reg |= (0x55 << 16);




	while(1)
	{

		// make all Rows HIGH (PD0 to PD3)
		*p_gpiod_output_data_reg |= 0x0F;

		// make R1 LOW (PD0)
		*p_gpiod_output_data_reg &= ~(1 << 0);

		//Scan the columns
		// Check C1(PD8) low or high
		if(	 ! (*p_gpiod_input_data_reg & (1 << 8))	){
			// key is pressed (LOW)
			delay();
			printf("1\n");
		}

		// Check C2(PD9) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 9))	){
			// key is pressed (LOW)
			delay();
			printf("2\n");
		}

		// Check C3(PD10) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 10))	){
			// key is pressed (LOW)
			delay();
			printf("3\n");
		}

		// Check C4(PD11) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 11))	){
			// key is pressed (LOW)
			delay();
			printf("A\n");
		}





		// make all Rows HIGH (PD0 to PD3)
		*p_gpiod_output_data_reg |= 0x0F;

		// make R2 LOW (PD1)
		*p_gpiod_output_data_reg &= ~(1 << 1);

		//Scan the columns
		// Check C1(PD8) low or high
		if(	 ! (*p_gpiod_input_data_reg & (1 << 8))	){
			// key is pressed (LOW)
			delay();
			printf("4\n");
		}

		// Check C2(PD9) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 9))	){
			// key is pressed (LOW)
			delay();
			printf("5\n");
		}

		// Check C3(PD10) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 10))	){
			// key is pressed (LOW)
			delay();
			printf("6\n");
		}

		// Check C4(PD11) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 11))	){
			// key is pressed (LOW)
			delay();
			printf("B\n");
		}





		// make all Rows HIGH (PD0 to PD3)
		*p_gpiod_output_data_reg |= 0x0F;

		// make R3 LOW (PD2)
		*p_gpiod_output_data_reg &= ~(1 << 2);

		//Scan the columns
		// Check C1(PD8) low or high
		if(	 ! (*p_gpiod_input_data_reg & (1 << 8))	){
			// key is pressed (LOW)
			delay();
			printf("7\n");
		}

		// Check C2(PD9) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 9))	){
			// key is pressed (LOW)
			delay();
			printf("8\n");
		}

		// Check C3(PD10) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 10))	){
			// key is pressed (LOW)
			delay();
			printf("9\n");
		}

		// Check C4(PD11) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 11))	){
			// key is pressed (LOW)
			delay();
			printf("C\n");
		}





		// make all Rows HIGH (PD0 to PD3)
		*p_gpiod_output_data_reg |= 0x0F;

		// make R4 LOW (PD3)
		*p_gpiod_output_data_reg &= ~(1 << 3);

		//Scan the columns
		// Check C1(PD8) low or high
		if(	 ! (*p_gpiod_input_data_reg & (1 << 8))	){
			// key is pressed (LOW)
			delay();
			printf("*\n");
		}

		// Check C2(PD9) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 9))	){
			// key is pressed (LOW)
			delay();
			printf("0\n");
		}

		// Check C3(PD10) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 10))	){
			// key is pressed (LOW)
			delay();
			printf("#\n");
		}

		// Check C4(PD11) low or high
		if (	! (*p_gpiod_input_data_reg & (1 << 11))	){
			// key is pressed (LOW)
			delay();
			printf("D\n");
		}


	} // while end

}





















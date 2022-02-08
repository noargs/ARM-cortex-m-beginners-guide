#include <stdio.h>

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif

int main(void)
{
    printf("Size of char data type is %u\n", sizeof(char));
    printf("Size of short data type is %u\n", sizeof(short));
    printf("Size of int data type is %u\n", sizeof(int));
    printf("Size of long data type is %u\n", sizeof(long));
    printf("Size of long long data type is %u\n", sizeof(long long));
    printf("Size of double data type is %u\n", sizeof(double));

	for(;;);
}

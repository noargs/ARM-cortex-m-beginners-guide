#include <stdio.h>

#define PI_VALUE (3.1415f)

#define AREA_OF_CIRCLE(x)     ((PI_VALUE) * (x) * (x))

#define AREA_TRI

int main(void) {


#ifdef AREA_CIR
	// run code block
#endif

#ifdef AREA_TRI
	// run code block
#endif

	float area_circle;

	area_circle = AREA_OF_CIRCLE(2);

	area_circle = 3.1415f * 2+2 * 2+2;

	printf("Area = %f\n", area_circle);

	return 0;
}

#include <stdio.h>
#include <stdint.h>

void display_array(int32_t *p_array, uint32_t nitem);
void swap_arrays(int32_t* array1, int32_t* array2, uint32_t item1, uint32_t item2);

int main(void) {

	printf("Array swapping program\n");
	printf("Enter no. of elements of Array-1 and Array-2:");

	int32_t item1, item2;

	scanf("%d %d", &item1, &item2);

	//printf("array1 is %d, and array2 is %d", array1, array2);

	int array1[item1];
	int array2[item2];

	printf("\n");

	for(uint32_t i = 0; i < item1; i++)
	{
		printf("Enter element %d of Array-1:", i);
		scanf("%d", &array1[i]);
		printf("\n");
	}

	for(uint32_t i = 0; i < item2; i++)
	{
		printf("Enter element %d of Array-2:", i);
		scanf("%d", &array2[i]);
		printf("\n");
	}

	printf("Contents of array before swap\n");

	display_array(array1, item1);

	printf("\n");

	display_array(array2, item2);

	printf("\n");

	printf("Contents of arrays after swap\n");

	swap_arrays(array1, array2, item1, item2);

	display_array(array1, item1);

	printf("\n");

	display_array(array2, item2);

	return 0;
}

void display_array(int32_t *p_array, uint32_t nitem)
{
	for (uint32_t i = 0; i < nitem; i++)
	{
		printf("%4d ", p_array[i]);
	}
}

void swap_arrays(int32_t* array1, int32_t* array2, uint32_t item1, uint32_t item2)
{
	uint32_t len = item1 < item2 ? item1 : item2;

	for(uint32_t i = 0; i < len; i++)
	{
		int32_t temp = array1[i];
		array1[i] = array2[i];
		array2[i] = temp;
	}
}

















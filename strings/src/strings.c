#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char msg[] = "A"; // called as string definition
	char msg[] = 'A'; // not string but 'A' is a character here

	char msg[10] = "hello"; // compiler convert this to hello0000000000
	char msg2[] = "hello";

	sizeof(msg1); // 10
	sizeof(msg2); // 6

	strlen(msg1); // 5
	strlen(msg2); // 5

	char * msg = "hello";

	return EXIT_SUCCESS;
}

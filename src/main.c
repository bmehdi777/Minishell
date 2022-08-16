#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"
#include "utils.h"
#include "input.h"


int main(int argc, char *argv[]) {
	int exit = 0;
	char *input;
	clean_screen();

	do {
		input = get_input(stdin, BUFFER_LENGTH);

		if (strcmp(input, "exit") == 0) {
			exit = 1;
		}
	} while(exit != 1);

	free(input);
	return 0;
}

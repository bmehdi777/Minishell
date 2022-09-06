#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"
#include "utils.h"
#include "input.h"
#include "parse.h"
#include "program.h"


int main() {
	int exit = 0;
	//char input[] = "test  a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a && test2 kl k k k kk k k k k k k";

	char *input;
	//clean_screen();

	do {
		input = get_input(stdin, BUFFER_LENGTH);

		if (strcmp(input, "exit") == 0) {
			exit = 1;
		} else if (strcmp(input, "") == 0) {

		} else {
			struct word_command *commands = input_to_wc(input);
			char path_program[1024];
			search_program_path("ls", path_program);

			printf("%s\n", path_program);
			debug_wc(commands);
			free_wc(&commands);
		}
		free(input);
	} while(exit != 1);

	return 0;
}

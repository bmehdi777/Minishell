#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

int search_in_folder(char *path, char *filename) {
	if (fopen(strcat(path, filename), "r") != NULL) {
		// The file does actually exist
		return 1;
	} else {
		return 0;
	}
}

void search_program_path(char *program_name, char *path_program) {
	char *path_variable = getenv("PATH");
	char *path = malloc(strlen(path_variable)+1);
	strcpy(path, path_variable);

	char *folder_path = strtok(path, ":");
	char buffer[1024];
	while (folder_path != NULL) {
		strcat(buffer, folder_path);
		strcat(buffer, "/");
		if(search_in_folder(buffer, program_name) == 1) {
			// search_in_folder already concatenated the string
			strcpy(path_program, buffer);
			free(path);
			return;
		}
		memset(buffer, 0,strlen(buffer)+1);
		folder_path = strtok(NULL, ":");
	}
	free(path);
}

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char *get_input(FILE* file_input, size_t size) {
	int character;
	size_t len = 0;
	char *str = malloc(sizeof(size));
	if (!str) return str;
	while (EOF != (character = fgetc(file_input)) && character != '\n') {
		len++;
		str[len] = character;
		if (len == size) {
			size += BUFFER_LENGTH;
			str = realloc(str, sizeof(*str)*(size));
			if(!str) return str;
		}
	}
	len++;
	str[len] ='\0';

	return realloc(str, sizeof(*str)*len);
}

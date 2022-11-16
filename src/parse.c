#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "program.h"
#include "dbg.h"

int special_char(char *input) {
	if (strcmp(input, "&&") == 0 ||
			strcmp(input, "|") == 0 ||
			strcmp(input, ">") == 0 ||
			strcmp(input, ">>") == 0 ||
			strcmp(input, "<") == 0  ||
			strcmp(input, "<<") == 0) {
		return 0;
	}
	return -1;
}

struct word_command *input_to_wc(char *input) {
	// Initialize word_command struct
	struct word_command *head = malloc(sizeof(struct word_command));
	struct word_command *current = head;

	// Initialize word_args struct
	size_t max_size_args = sizeof(char*)*SIZE_ARGS_PAGE;
	current->w_args = malloc(sizeof(struct word_args)+max_size_args);
	current->w_args->size_args = 0;
	
	char buffer_input[10000];
	strcpy(buffer_input, input);
	char *token = strtok(buffer_input, " ");

	while (token != NULL) {
		if (current->w_args->size_args == 0) {
			log_info("token : %s", token);
			strcpy(current->command, token);
		} else {
			// special characters - other command
			if (special_char(token) == 0) {
				current->next = malloc(sizeof(struct word_command));
				current = current->next;

				max_size_args = sizeof(char*)*SIZE_ARGS_PAGE;
				current->w_args = malloc(sizeof(struct word_args)+max_size_args);
				current->w_args->size_args = 0;
				token = strtok(NULL, " ");
				continue;
			}

			if ((size_t)current->w_args->size_args * sizeof(char*) >= max_size_args) {
				max_size_args += sizeof(char*)*SIZE_ARGS_PAGE;
				current->w_args = realloc(current->w_args, sizeof(struct word_args)+max_size_args);
			}

			current->w_args->args[current->w_args->size_args-1] = token;
		}
		current->w_args->size_args++;
		token = strtok(NULL, " ");
	}

	return head;
}

void path_to_wc(struct word_command *head) {
	struct word_command *current = head;
	while (current != NULL) {
		search_program_path(current->command, current->path_commands);
		current = current->next;
	}
}

void debug_wc(struct word_command *head) {
	struct word_command *current = head;
	while (current != NULL) {
		log_info("Command : %s", current->command);
		//log_info("Path : %s", current->path_commands);
		log_info("Arguments : ");
		for (size_t i = 0; i < current->w_args->size_args-1; i++) {
			log_info("- %li : %s", i, current->w_args->args[i]);
		}
		current = current->next;
	}
}

void free_wc(struct word_command **head) {
	struct word_command *previous = *head;
	while (*head) {
		*head = (*head)->next;
		free(previous->w_args);
		free(previous);
		previous = *head;
	}
}
//TODO : rewrite debug_wc

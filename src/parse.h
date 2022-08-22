#ifndef __parse_h
#define __parse_h

#define SIZE_ARGS_PAGE 64

// Cannot put a flexible array alone 
struct word_args {
	size_t size_args;
	char *args[];
};

struct word_command {
	char *command;
	struct word_args *w_args;
	struct word_command *next;
};

struct word_command *input_to_wc(char *input);
void debug_wc(struct word_command *head);
void free_wc(struct word_command **head);

#endif

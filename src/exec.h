#ifndef __exec_h
#define __exec_h

int execute_command(char *path_to_program, char *arguments[]);
void execute_commands(struct word_command *head);

#endif

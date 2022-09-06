#include <sys/types.h>
#include <unistd.h>
#include "parse.h"
#include "dbg.h"


int execute_command(char *path_to_program, char *arguments[]) {
	pid_t forkres = fork();
	
	// if fork() returns 0, it means we are in the child process from here
	// if it returns -1, can't create child process
	// lastly in the parent process, fork() return the pid of the child
	if (forkres == 0) {
		execv(path_to_program, arguments);
	} else if (forkres == -1) {
		goto error;
	}
	return forkres;

error:
	log_err("An error occured while creating the child process");
	return -1;
}

void execute_commands(struct word_command *head) {
	struct word_command *current = head;

	while (current != NULL) {

	}
}

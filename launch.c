#include "shell.h"

/**
 * launch - Launch a program and wait for it to terminate
 * @args: An array of arguments
 *
 * Return: 1 to continue the shell loop
 */
int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1) {
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("launch");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}


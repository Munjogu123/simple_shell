#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

/**
 * main - execute basic UNIX commands
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment of new program
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *lineptr;
	size_t *n = 0;
	int get_val, exec_val;

	if (argc < 1)
	{
		perror("Usage");
	}


	while (1)
	{
		write(1, "$ ", 2);
		get_val = getline(&lineptr, n, stdin);

		if (get_val == -1)
		{
			perror("Error:");
			exit(98);
		}

		exec_val = execve(argv[0], argv, envp);

		if (exec_val == -1)
		{
			perror("Error:");
			exit(98);
		}
		printf("%s\n", lineptr);
		free(lineptr);
	}

	return (0);

}

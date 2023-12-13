#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * @env: Array of environment variables
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv, char **env)
{
	char *line;
	char **args;
	int status;

	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (1);
	}

	(void)env;

	do 
	{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (0);
}


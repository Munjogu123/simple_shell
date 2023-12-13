#include "test.h"

/**
 * main - entry point
 * @ac: no of args
 * @av: array of strings
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *lineptr, *lineptr_copy, *token;
	size_t n = 0;
	ssize_t val;
	const char *delim;
	int num_tokens, i, status;
	pid_t child;

	lineptr = NULL;
	lineptr_copy = NULL;
	delim = " \n";

	(void)ac;

	while (1)
	{
		printf("$ ");
		val = getline(&lineptr, &n, stdin);
		if (val == -1)
		{
			printf("Exiting...\n");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * val);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		av = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token  = strtok(NULL, delim);
		}
		av[i] = NULL;

		child = fork();
		if (child == 0)
			execmd(av);
		else
			wait(&status);
	}
	free(lineptr);
	free(lineptr_copy);

	return (0);
}

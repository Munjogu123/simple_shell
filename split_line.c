#include "shell.h"

/**
 * split_line - Split a line into tokens
 * @line: The line to split
 *
 * Return: An array of tokens
 */
char **split_line(char *line)
{
	char **tokens;
	char *token;
	size_t bufsize = BUFSIZE;
	size_t index = 0;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		perror("split_line");
		exit(1);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		if (index >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("split_line");
				exit(1);
			}
		}

		token = strtok(NULL, DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}


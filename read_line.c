#include "shell.h"

/**
 * read_line - Read a line from stdin
 *
 * Return: A pointer to the line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t readsize;

	readsize = getline(&line, &bufsize, stdin);
	if (readsize == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}
		else
		{
			perror("read_line");
			exit(1);
		}
	}
	return (line);
}


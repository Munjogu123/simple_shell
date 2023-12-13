#include "shell.h"

/**
 * execute - Execute a command
 * @args: An array of arguments
 *
 * Return: 1 to continue the shell loop, 0 to exit
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}
	return (launch(args));
}


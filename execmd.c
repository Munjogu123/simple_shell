#include "test.h"

/**
 * execmd - executes commands
 * @av: command from stdin
 */
void execmd(char **av)
{
	int val;
	char *command, *arg;

	if (av)
	{
		arg = av[0];
		command = get_location(arg);
		val = execve(command, av, NULL);
		if (val == -1)
			perror("Error");
	}
}

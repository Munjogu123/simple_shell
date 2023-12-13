#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

char *read_line(void);
char **split_line(char *line);
int launch(char **args);
int execute(char **args);

#endif

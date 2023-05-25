#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define EXIT_FAILURE 1
#define MAX_PATH_LENGTH 100
extern char **environ;

/* Functions */
int _strcmp(const char *s1, const char *s2);

/**
 * struct builtin - Struct format
 *
 * @name: name of the builin
 * @f: The function associated
 */

typedef struct builtin
{
	char *name;
	int (*f)(char **args, char *line);
} builtin_t;

#endif

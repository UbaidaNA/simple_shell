#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

void shell(void);
void signHanlder(__attribute__((unused))int sig_num);
char *getinput(int piped, char *line, char **args);
char **parse_input(char *line, char **tokens);
int handle_command(char **args, char *line);
int change_directory(char **args, char *line);
int exit_shell(char **args, char *line);
int addenv(char **args, char *line);
int deleteenv(char **args, char *line);
int print_env(char **args, char *line);
char *comment(char *input);
void execute_command(char *command);
void handle_commands(char *commands);

extern char **environ;
#define disregard(y) (void)(y)
#define BUFSIZE 1024
#define TOKEN_DELIM " \t\r\n\a"


/**
 * struct builtin - format
 *
 * @name: the name
 * @f: the function
 */
typedef struct builtin
{
	char *name;
	int (*f)(char **args, char *line);
} builtin_t;


#endif


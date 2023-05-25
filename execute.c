#include "shell.h"

/**
 * signHanlder - doesn't allow ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void signHanlder(__attribute__((unused))int sig_num)
{
	write(1, "\n", 1);
	fflush(stdin);
}

/**
	* handle_command - forks a child process
	* @args: the arguments
	* @line: the line
	* Return: 0
	*/

int handle_command(char **args, char *line)
{
int i = 0, status;
pid_t pid;
builtin_t builtin[] = {
{"exit", exit_shell},
{"env", print_env},
{"setenv", addenv},
{"unsetenv", deleteenv},
{"cd", change_directory},
{NULL, NULL}
};
if (args[0] == NULL)
{
return (1);
}
while (builtin[i].name)
{
if (strcmp(args[0], builtin[i].name) == 0)
{
(builtin[i].f)(args, line);
return (1);
}
i++;
}
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
fprintf(stderr, "%s: command not found\n", args[0]);
free(args);
free(line);
}
exit(126);
}
else if (pid < 0)
perror("fork");
else
wait(&status);

return (1);
}


/**
 * shell - runs the shell
 *
 * Return: void
 */


void shell(void)
{
int bufsize = BUFSIZE;
int piped = 0;
int status;
char *line = NULL;


if (!isatty(STDIN_FILENO))
{
piped = 1;
}
do {
char **args = malloc(bufsize * sizeof(char *));

line = getinput(piped, line, args);
line = comment(line);
args = parse_input(line, args);
status = handle_command(args, line);

free(args);
free(line);
} while (status);
}



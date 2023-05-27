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
* @command: the line
* Return: 0
*/

int handle_command(char **args, char *command)
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
(builtin[i].f)(args, command);
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
free(command);
}
exit(126);
}
else if (pid < 0)
perror("fork");
else
wait(&status);

return (1);
}





#include "shell.h"

/**
 * main - interactive shell
 *
 * Return: (0)
 */

int main(void)
{
char *command = NULL, *args[2], *token;
size_t command_len = 0;
pid_t pid;
int status;

while (1)
{
printf("$ ");
fflush(stdout);
if (getline(&command, &command_len, stdin) == -1)
{
break;
}
if (strcmp(command, "\n") == 0)
{
continue;
}
token = strtok(command, " \n");
args[0] = token;
args[1] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(0);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("Error");
exit(0);
}
else
{
waitpid(pid, &status, 0);
}
}
free(command);
return (0);
}

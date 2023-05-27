#include "shell.h"

/**
 * print_env - print variable in environ
 * @args: ignored
 * @command: command
 * Return: 0 if successful
*/

int print_env(char **args, char *command)
{
char **env = environ;

disregard(command);
disregard(args);

while (*env)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}

return (0);
}


/**
 * addenv - add variable in the environ
 * @args: parsed user input
 * @command: command
 * Return: 0 if successful
*/

int addenv(char **args, char *command)
{
disregard(command);

if (!args[2] || args[3])
{
write(STDOUT_FILENO, "Usage:\n\tsetenv VARIABLE VALUE\n", 31);
return (1);
}
if (setenv(args[1], args[2], 1) == -1)
{
perror(args[0]);
return (1);
}
return (0);
}









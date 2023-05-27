#include "shell.h"


/**
 * deleteenv - delete variable in environ
 * @args: parsed user input
 * @command: command
 * Return: 0 if successful
*/
int deleteenv(char **args, char *command)
{
disregard(command);

if (!args[1] || args[2])
{
write(STDOUT_FILENO, "Usage:\n\tunsetenv VARIABLE\n", 26);
return (1);
}
if (unsetenv(args[1]) == -1)
{
perror(args[0]);
return (1);
}
return (0);
}


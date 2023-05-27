#include "shell.h"


/**
 * exit_shell - exits shell
 * @args: the arguments
 * @command: command
 * Return: (int)
**/

int exit_shell(char **args, char *command)
{
int EXIT_CODE;
char *checker;

if (args[1] == NULL)
{
free(args);
free(command);
exit(0);
}
EXIT_CODE = strtol(args[1], &checker, 10);
if (*checker != '\0' || EXIT_CODE < 0)
{
fprintf(stderr, "%s: Illegal number: %s\n", command, args[1]);
free(args);
free(command);
exit(2);
}
free(args);
free(command);
exit(EXIT_CODE % 256);
}



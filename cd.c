#include "shell.h"



/**
 * change_directory - replicate pwd
 * @command: command
 * @args: the arguments
 * Return: (0)
 **/
int change_directory(char **args, char *command)
{
char *previous = getenv("OLDPWD");
char *current = getenv("PWD");

disregard(command);
if (args[1] == NULL)
{
if (chdir(getenv("HOME")) != 0)
{
perror("cd");
return (1);
}
setenv("OLDPWD", current, 1);
}
else if (strcmp(args[1], "-") == 0)
{
if (chdir(previous) != 0)
{
write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
return (1);
}
setenv("OLDPWD", current, 1);
write(STDOUT_FILENO, previous, strlen(previous));
write(STDOUT_FILENO, "\n", 1);
}
else
{
if (chdir(args[1]) != 0)
{
perror("chdir");
return (1);
}
setenv("OLDPWD", current, 1);
}
return (0);
}

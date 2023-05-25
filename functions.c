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
if (*checker != '\0')
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



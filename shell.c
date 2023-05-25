#include "shell.h"

/**
 * getinput - reads input from command
 * @is_piped: looks if it's piped
 * @command: the command
 * @args: the arguments
 * Return: returns a pointer
 */
char *getinput(int is_piped, char *command, char **args)
{
ssize_t length;
size_t size = 0;

if (!is_piped)
{
printf("$ ");
fflush(stdout);
signal(SIGINT, signHanlder);
length = getline(&command, &size, stdin);
}
else
{
signal(SIGINT, signHanlder);
length = getline(&command, &size, stdin);
if (length == -1)
{
free(args);
free(command);
exit(EXIT_SUCCESS);
}
if (command[length - 1] == '\n')
{
command[length - 1] = '\0';
}
}
return (command);
}


/**
 * parse_input - it parse the input
 *
 * @command: command
 * @tokens: tokens from the command
 * Return: a pointer to an array of arguments
 */

char **parse_input(char *command, char **tokens)
{
int size = BUFSIZE, position = 0;
char *token;

if (!tokens)
{
perror("Allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(command, TOKEN_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= size)
{
size += BUFSIZE;
tokens = realloc(tokens, size *sizeof(char *));
if (!tokens)
{
free(token);
perror("Allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOKEN_DELIM);
}
free(token);
tokens[position] = NULL;
return (tokens);
}



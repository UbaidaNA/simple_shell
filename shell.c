#include "shell.h"

/**
 * getinput - reads input from the user
 * @is_piped: if in interactive mode
 * @line: line
 * @args: args
 * Return: a pointer to the input string
 */
char *getinput(int is_piped, char *line, char **args)
{
ssize_t len;
size_t bufsize = 0;

if (!is_piped)
{
printf("$ ");
fflush(stdout);
signal(SIGINT, signHanlder);
len = getline(&line, &bufsize, stdin);
}
else
{
signal(SIGINT, signHanlder);
len = getline(&line, &bufsize, stdin);
if (len == -1)
{
free(args);
free(line);
exit(EXIT_SUCCESS);
}
if (line[len - 1] == '\n')
{
			line[len - 1] = '\0';
}
}
return (line);
}


/**
 * parse_input - parses the input into arguments
 *
 * @line: input string
 * @tokens: tokens to store
 * Return: a pointer to an array of arguments
 */

char **parse_input(char *line, char **tokens)
{
int bufsize = BUFSIZE, position = 0;
char *token;

if (!tokens)
{
perror("Allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, TOKEN_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
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



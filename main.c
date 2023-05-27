#include "shell.h"

/**
	* main - entry point to program
	* @ac: the number of arguments passed
	* @av: a pointer to an array of arguments
	* Return: 0
*/


int main(int ac, char **av)
{
	disregard(ac);
	disregard(av);
	shell();
	return (0);
}

/**
 * shell - runs the shell
 *
 * Return: void
 */


void shell(void)
{
int size = BUFSIZE;
int piped = 0;
int status;
char *command = NULL;


if (!isatty(STDIN_FILENO))
{
piped = 1;
}
do {
char **args = malloc(size * sizeof(char *));

command = getinput(piped, command, args);
command = comment(command);
args = parse_input(command, args);
status = handle_command(args, command);

free(args);
free(command);
} while (status);
}

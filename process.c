#include "shell.h"

/**
 * process - creates a new process
 * @pid: the process
 * @args: the array of arguments
 * @status: process id
 * Return: void
 */

void process(pid_t pid, char **args, int status)
{
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("./hsh");
		exit(0);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
	}
}

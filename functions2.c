#include "shell.h"

/**
 * execute_command - executes a single command
 * @command: command to be executed
 */

void execute_command(char *command)
{
	char *args[100];
	int i = 0, status;
	char *token = strtok(command, " ");
	pid_t pid = fork();

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Child process exited with status %d\n",
					WEXITSTATUS(status));
		}
	}
}


/**
 * command_handler - handles commands separated by semi-colons
 * @commands: commands to be handled
 */

void command_handler(char *commands)
{
	char *token = strtok(commands, ";");

	while (token != NULL)
	{
		execute_command(token);
		token = strtok(NULL, ";");
	}
}

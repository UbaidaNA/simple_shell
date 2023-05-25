#include "shell.h"

/**
 * main - interactive shell
 *
 * Return: (0)
 */

int main(void)
{
	char *command = NULL, *token, *args[1024];
	size_t command_len = 0;
	int i = 0, status = 0;
	pid_t pid;

	while (printf("$ ") && getline(&command, &command_len, stdin) != -1)
	{
		for (i = 0, token = strtok(command, " \n");
				token; token = strtok(NULL, " \n"))
		{
			if (token[0] == '#')
				break;
			args[i++] = token;
		}
		args[i] = NULL;
		if (args[0] != NULL && _strcmp(args[0], "exit") == 0)
			break;
		handle_path(args[0]);
		if (args[0] != NULL && _strcmp(args[0], "cd") == 0)
			handle_directory(args);
		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(0);
			}
			else if (pid == 0)
			{
				process(pid, args, status);
				exit(EXIT_SUCCESS);
			}
			else
				waitpid(pid, &status, 0);
		}
	}
	free(command);
	return (0);
}

#include "shell.h"

/**
 * handle_path - handles the path
 * @command: the command that gets passed
 *
 * Return: void
*/

void handle_path(const char *command)
{
	const char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char resolved_path[MAX_PATH_LENGTH];

		snprintf(resolved_path, MAX_PATH_LENGTH, "%s/%s", token, command);

		if (access(resolved_path, X_OK) == 0)
		{
			break;
		}

	token = strtok(NULL, ":");
	}
	free(path_copy);
}

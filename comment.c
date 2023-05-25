#include "shell.h"

/**
 * comment - ignores comments
 * @command: the command
 * Return: command without comments
*/

char *comment(char *command)
{
int i;

for (i = 0; command[i]; i++)
{
if (command[0] == '#')
{
command[i] = '\0';
}
else if ((command[i] == '#' && command[i - 1] == ' ')
|| (command[i] == '|' && command[i]))
{
command[i] = '\0';
}
else
{
command[i] = command[i];
}
}

return (command);
}



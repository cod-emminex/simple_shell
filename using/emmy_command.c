#include "emmy.h"
/**
 * emmy_check_command - check if command exists
 * @env: shell environ
 * @command: command to check
 * Return:
 *   A pointer to an array of tokens.
 */

char *emmy_check_command(char *command, char **env)
{
	char *command_path = NULL;
	int found = 0;
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{

			char *path = env[i] + 5;
			char *dir = strtok(path, ":");

			while (dir != NULL)
			{
				char command_path[256];

				emmyf(command_path, "%s/%s", dir, command);

				if (access(command_path, X_OK) == 0)
				{
					found = 1;
					break;
				}
				dir = strtok(NULL, ":");
			}
			break;
		}

	}
	if (found)
	{
		/* Return the full path to the command */
		return (command_path);
	}
	else
	{
		emmyf("%s: command not found\n", command);
		return (NULL);
	}
}

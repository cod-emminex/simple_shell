#include "emmy.h"

/**
 * main - entry point
 * @i: int
 * @args: arguments
 * @envp: environment
 * Return: 0
 */

int main(int i, char **args, char **envp)
{
	char *input, *token;
	size_t n = 0;

	while (true)
	{
		emmyf("emmy$ ");
		input = malloc(sizeof(char) * BUFFER_SIZE);
		n = BUFFER_SIZE;
		emmy_getline(&input, &n, stdin);
		args = malloc(sizeof(char *) * MAX_ARGS);
		token = emmy_strtok(input, " ");
		if (token != NULL)
		{
			args[i] = token;
			emmy_exec(args);
			i++;
		}
		args[i] = NULL;

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				emmy_exit();
			} else if (strcmp(args[0], "env") == 0)
			{
				emmy_env(args, envp);
			} else
			{
				char *command_path = emmy_check_command(args[0], envp);

				if (command_path != NULL)
				emmy_exec(args);
			}
		}
		free(token);
		free(input);
		free(args);
	}
}




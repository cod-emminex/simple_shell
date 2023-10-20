#include "emmy.h"

/**
 * main - entry point
 * @i: int
 * @args: arguments
 * Return: 0
 */

int main(int i, char **args)
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
		while (token != NULL)
		{
			args[i] = token;
			token = emmy_strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				emmy_exit();
		}
		free(token);
		free(input);
		free(args);
	}
}




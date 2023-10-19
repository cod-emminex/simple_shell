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
		emmyf("emmy$ \n");
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

/**
 * emmy_split_input - Splits the input into tokens.
 * @input: A pointer to a null-terminated string that represents
 *          the input to be split.
 *
 * Return:
 *   A pointer to an array of tokens.
 */

char **emmy_split_input(char *input)
{
    /* Initialize the length of the tokens array */
	int length = 0;

	/* Initialize the capacity of the tokens array */
	int capacity = 16;

	/* Allocate memory for the tokens array */
	char **token = malloc(capacity * sizeof(char *));

	/* Define the delimiters for strtok */
	char *delimiters = " \t\r\n";

	/* Get the first token */
	char *tok = strtok(input, delimiters);

	/* Loop over the input and split it into tokens */
	while (tok != NULL)
	{
		/* Add the token to the tokens array */
		token[length] = tok;

		/* Increment the length of the tokens array */
		length++;
		/* If the length of the */
		/* tokens array reaches its capacity, increase the capacity */
		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);

			token = realloc(token, capacity * sizeof(char *));
		}

		/* Get the next token */
		tok = strtok(NULL, delimiters);
	}

	/* Null-terminate the tokens array */
	token[length] = NULL;
	/* Return the tokens array */
	return (token);
}

/**
 * emmy_parse_input - Splits the input into tokens.
 * @input: A pointer to a null-terminated string that represents
 *          the input to be split.
 *
 * Return:
 *   A pointer to an array of tokens.
 */

char **emmy_parse_input(char *input)
{
	int capacity = 64;
	char **args = malloc(capacity * sizeof(char *));
	char *delimiter = " ";
	char *arg;
	int length = 0;

	arg = strtok(input, delimiter);

	while (arg != NULL)
	{
		args[length] = arg;

		length++;

		if (length >= capacity)
		{
			capacity *= 2;
			args = realloc(args, capacity * sizeof(char *));
		}

		arg = strtok(NULL, delimiter);
	}

	args[length] = NULL;

	return (args);
}


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

#include "emmy.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char *input;
	char **token;

	while (true)
	{
		emmyf("emmy$ ");

		input = emmy_read_input();
		token = emmy_split_input(input);

		if (token[0] != NULL)
		{
			emmy_exec(token);
		}

		free(token);
		free(input);
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


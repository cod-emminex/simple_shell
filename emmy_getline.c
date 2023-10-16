#include "emmy.h"

/**
 * emmy_read_input - read user input
 *
 * Return: stdin
 *   A pointer to the line read.
 */

char *emmy_read_input(void)
{
	/* Pointer to the input read. Initialized to NULL. */
	char *input = NULL;

	/* The size of the buffer to store the input. Initialized to 0. */
	size_t lenbuf = 0;

	/* Read the input using getline function. */
	getline(&input, &lenbuf, stdin);

	/* Return the input read. */
	return (input);
}

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

	/* The number of characters read by getline. */
	ssize_t num_chars;

	/* Read the input using getline function. */
	num_chars = getline(&input, &lenbuf, stdin);

	/* If getline returns -1, it means EOF or an error occurred. */
	if (num_chars == -1)
	{
        /* If EOF, exit the program cleanly. */
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        }
        /* If it's an error, print a message and exit with a failure status. */
        else {
            perror("emmyerror");
            exit(EXIT_FAILURE);
        }
    }


	/* Return the input read. */
	return (input);
}

/* Function: kash_read_line
 * -------------------------
 * Reads a line from the standard input.
 *
 * Returns:
 *   A pointer to the line read.
 */
char* kash_read_line() {
    /* Pointer to the line read. Initialized to NULL. */
    char *input = NULL;

    /* The size of the buffer to store the line. Initialized to 0. */
    size_t buflen = 0;
    /* Read the line using getline function. */
    num_chars = getline(&input, &buflen, stdin);

    /* Return the line read. */
    return input;
}

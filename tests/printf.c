#include "emmy.h"

/**
 * itoa - change int to str
 * @str: string
 * @n: integer
 */

void itoa(unsigned int n, char *str)
{
	int i = 0;
	int j;

	do {
		str[i++] = '0' + n % 10;
		n /= 10;
	} while (n > 0);
	str[i] = '\0';

	/* Reverse the string */


	for (j = 0; j < i / 2; j++)
	{
		char tmp = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
	}
}

/**
 * emmyf - works like printf
 * @format: format to print
 *
 */

void emmyf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == 's')
		{

			char *s = va_arg(args, char *);

			write(1, s, strlen(s));

		}

		else if (*format == 'd')
		{
			int d = va_arg(args, int);

			char str[12];  /* Buffer to hold the integer as a string */

			itoa(d, str);
			write(1, str, strlen(str));
		}
		else if (*format == 'u')
		{
			unsigned int u = va_arg(args, unsigned int);

			/* Buffer to hold the unsigned integer as a string */

			write(1, &unsigned int, strlen(unsigned int));
		}
		/* Add more format specifiers as needed */
		++format;
	}

	va_end(args);

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



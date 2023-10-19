#include "emmy.h"

/**
 * emmy_exit - terminates the shell
 *
 * Return: nothing
 */

void emmy_exit(void)
{
	exit(0);
}

/**
 * emmy_getline - reads a line from the standard input
 * @lineptr: pointer to a pointer to a char.
 * @n: pointer to a size_t.
 * @stream: pointer to a FILE. This is not used in this function.
 * Return: the number of characters read, or -1 if an error occurred.
 */

ssize_t emmy_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static char *buffer_ptr = buffer;
	static char *buffer_end = buffer;
	char *line = *lineptr;
	size_t line_size = 0;
	char c = *buffer_ptr++;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
			return (-1);
		*n = BUFFER_SIZE;
	}
	while (1)
	{
		if (buffer_ptr == buffer_end)
		{
			ssize_t bytes_read = read(0, buffer, BUFFER_SIZE);

			if (bytes_read <= 0)
				break;
			buffer_ptr = buffer;
			buffer_end = buffer + bytes_read;
		}
		if (c == '\n' || c == '\r')
			break;
		if (line_size + 1 >= *n)
		{
			*n *= 2, *lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
			line = *lineptr;
		}
		line[line_size++] = c;
	}
	line[line_size] = '\0';
	return (line_size);
}

/**
 * emmy_strtok - splits a string into tokens based on a delimiter
 * @str: the string to split. If str is NULL, the function continues splitting
 * the string from where it left off in the previous call.
 * @delim: the delimiter to split the string on.
 * Return: a pointer to the next token, or NULL if there are no more tokens.
 */

char *emmy_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_end = next_token;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);

	while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
		next_token++;
	if (*next_token == '\0')
		return (NULL);

	while (*token_end != '\0' && strchr(delim, *token_end) == NULL)
		token_end++;

	if (*token_end != '\0')
	{
		*token_end = '\0', next_token = token_end + 1;
	}
	else
	{
		next_token = NULL;
	}

	return (next_token - 1);
}


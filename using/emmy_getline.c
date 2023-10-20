#include "emmy.h"

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



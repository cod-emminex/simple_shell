#include "emmy.h"

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


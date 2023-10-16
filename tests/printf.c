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

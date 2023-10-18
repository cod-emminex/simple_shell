#include "emmy.h"

/**
 * emmyf - prints output
 * @format: string to print
 */


void emmyf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vfprintf(stdout, format, args);

	vprintf(format, args);

	va_end(args);
}

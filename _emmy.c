#include "emmy.h"

/**
 * my_printf - Writes the string pointed to by format to stdout
 * @format: The string to be written
 *
 * Return: The number of characters printed
 */
int my_printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;
    char *s;
    unsigned int num;
    char c;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 's':
                    s = va_arg(args, char *);
                    write(1, s, _strlen(s));
                    count += _strlen(s);
                    break;
                case 'd':
                    num = va_arg(args, int);
                    write(1, _itoa(num), _strlen(_itoa(num)));
                    count += _strlen(_itoa(num));
                    break;
                case 'u':
                    num = va_arg(args, unsigned int);
                    write(1, _uitoa(num), _strlen(_uitoa(num)));
                    count += _strlen(_uitoa(num));
                    break;
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                default:
                    write(1, &format[i], 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);

    return (count);
}

/**
 * _uitoa - Converts an unsigned integer to a string
 * @n: The unsigned integer to be converted
 *
 * Return: A string representation of the unsigned integer
 */
char *_uitoa(unsigned int n)
{
    static char buffer[12];
    int i = 0;

    if (n == 0)
    {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return (buffer);
    }

    while (n > 0)
    {
        buffer[i++] = '0' + n % 10;
        n /= 10;
    }

    buffer[i] = '\0';

    return (_reverse(buffer));
}

/**
    * _itoa - Converts an integer to a string
    * @n: The integer to be converted
    *
    * Return: A string representation of the integer
    */
   char *_itoa(int n)
   {
       static char buffer[12];
       int i = 0;

       if (n == 0)
       {
           buffer[i++] = '0';
           buffer[i] = '\0';
           return (buffer);
       }

       if (n < 0)
       {
           buffer[i++] = '-';
           n = -n;
       }

       while (n > 0)
       {
           buffer[i++] = '0' + n % 10;
           n /= 10;
       }

       buffer[i] = '\0';

       return (_reverse(buffer));
   }

/**
    * _reverse - Reverses a string
    * @s: The string to be reversed
    *
    * Return: A pointer to the reversed string
    */
   char *_reverse(char *s)
   {
       int i, j;
       char c;

       for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
       {
           c = s[i];
           s[i] = s[j];
           s[j] = c;
       }

       return (s);
   }

/**
 * _strlen - Returns the length of a string
 * @s: The string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return (i);
}

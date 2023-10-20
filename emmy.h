#ifndef EMMY_H
#define EMMY_H

#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 100
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

int my_printf(const char *format, ...);
int _strlen(char *s);
char *_itoa(int n);
char *_uitoa(unsigned int n);
char *_reverse(char *s);
void execute_command(char *line);
char **parse_line(char *line);



#endif

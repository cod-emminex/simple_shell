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

/* Protoypes */
void emmyf(const char *format, ...);
void itoa(unsigned int n, char *str);
char **emmy_split_input(char *input);
char *emmy_read_input(void);
void emmy_exec(char **args);
char **emmy_parse_input(char *input);
char *emmy_check_command(char *command, char **env);
void emmy_exit(void);
ssize_t emmy_getline(char **lineptr, size_t *n, FILE *stream);
char *emmy_strtok(char *str, const char *delim);
void emmy_env(char **args, char **envp);
#endif

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


/* Protoypes */
void emmyf(const char *format, ...);
void get_pid(void);
void itoa(unsigned int n, char *str);
char **emmy_split_input(char *input);
char *emmy_read_input();
void emmy_exec(char **args);
char **emmy_parse_input(char *input);
void emmy_loop(char **env);
char *emmy_check_command(char *command, char **env);

#endif

#include "emmy.h"

/**
    * main - Entry point
    * @ac: Number of arguments
    * @av: Array of arguments
    * @env: Array of environment variables
    *
    * Return: Always 0 (Success)
    */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;

    while (1) {
        my_printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1) {
            exit(EXIT_SUCCESS);
        }

        /* Parse the command line into arguments */
        args = parse_line(line);
        if (args == NULL)
        {
            my_printf("Error: Invalid command\n");
            continue;
        }

        /* Execute the command */
        execute_command(args[0]);

        /* Free the memory allocated for the arguments */
        free(args);
    }
	free(line);
    return (0);
}

#include "emmy.h"

/**
 * execute_command - Executes the command
 * @line: The command to be executed
 * @env: The environment variables
 *
 * Return: Nothing
 */
void execute_command(char *line)
{
    char **args;
    pid_t pid;
    int status;

    /* Parse the command line into arguments */
    args = parse_line(line);
    if (args == NULL)
    {
        my_printf("Error: Invalid command\n");
        return;
    }

    /* Fork a child process */
    pid = fork();
    if (pid == -1)
    {
        my_printf("Error: Failed to fork\n");
        return;
    }

    /* If this is the child process, execute the command */
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            my_printf("Error: Failed to execute command\n");
            exit(EXIT_FAILURE);
        }
    }

    /* If this is the parent process, wait for the child process to finish */
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    /* Free the memory allocated for the arguments */
    free(args);
}

/**
 * parse_line - Parses the command line into arguments
 * @line: The command line to be parsed
 *
 * Return: A pointer to the arguments
 */
char **parse_line(char *line)
{
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens)
    {
        my_printf("Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens)
            {
                my_printf("Error: Failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

#include "emmy.h"

/**
 * emmy_exec - execute using execve
 * Replaces the current process image with a new process image.
 * @args: An array of pointers to null-terminated strings that represent
 *         the argument list available to the new program.
 */

void emmy_exec(char **args)
{
	/* Child process ID */
	pid_t child_pid = fork();

	/* Environment variables for execve.*/
	/* In this case, we're passing an empty list. */
	char *envp[] = { NULL };

	/* Fork a child process */
	if (child_pid == 0)
	{
		/* Replace the process image with the new one */
		execve(args[0], args, envp);

		/* If execve returns, it must have failed */
		perror("emmyerror");
		exit(1);
	}
	else if (child_pid > 0)
	{
		/* In the parent process. Wait for the child to terminate */
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		/* The fork failed */
		perror("emmyerror");
	}
}

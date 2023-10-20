#include "emmy.h"


/**
 * emmy_env - prints the current environment
 * @args: arguments passed to the function
 * @envp: environment
 * Return: nothing
 */

void emmy_env(char **args, char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		if (args != NULL && strstr(envp[i], *args) != NULL)

		{
		emmyf("%s\n", envp[i]);
		i++;
		}
	}
}


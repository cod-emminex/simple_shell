#include "emmy.h"

/**
 * main- entry point
 * emmyf - entry point
 * Return: 0
 */

int main(void)
{
	pid_t pid = getpid();
	pid_t ppid = getppid();

	int a = 25;
	float b = 2.5;
	char c = 'D';
	char e[] = "Emmanuel";


	emmyf("%d\n%f\n%c\n%s\n", a, b, c, e);
	emmyf("%u\n%u\n", pid, ppid);
	emmyf("I am okay\n");
	return (0);
}

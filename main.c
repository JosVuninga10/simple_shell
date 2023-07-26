#include "shell.h"

/**
 * main - results in a shell
 * @ac: argument count
 * @av: argument vector
 * @env: environment
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av, env);
	}
	putchar('\n');
	return (0);
}

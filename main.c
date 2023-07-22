#include "shell.h"

/**
 * main - results in a shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		prompt(argv, env);
	}
	return (0);
}

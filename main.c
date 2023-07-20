#include "shell.h"

/**
 * main - results in a shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *prompt = "kajoseph $";
	char *linepr;
	size_t n = 0;
	ssize_t nd_prg;

	(void)argv;
	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		nd_prg = getline(&linepr, &n, stdin);
		if (nd_prg == -1)
		{
			printf("exiting...\n");
			return (-1);
		}
		printf("%s\n", linepr);

		free(linepr);
	}
	return (0);
}

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

	(void)argv;
	(void)argc;

	printf("%s", prompt);
	getline(&linepr, &n, stdin);
	printf("%s\n", linepr);

	free(linepr);
	return (0);
}

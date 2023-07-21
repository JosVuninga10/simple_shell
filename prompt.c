#include "shell.h"

/**
 * prompt - ...
 * @argv: ...
 * @env: ...
 *
 */
void prompt(char **argv, char **env)
{
	char *prmpt = "kajoseph $ ";
	char *linepr = NULL;
	size_t n = 0;
	ssize_t nd_prg;

	(void)argv;
	(void)env;

	while (1)
	{
		printf("%s", prmpt);
		nd_prg = getline(&linepr, &n, stdin);
		if (nd_prg == -1)
		{
			printf("exiting...\n");
			free(linepr);
			exit(0);
		}
		printf("%s\n", linepr);
	}
}

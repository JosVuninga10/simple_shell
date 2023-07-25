#include "shell.h"

/**
 * prompt - displays a prompt...
 * @av: ...
 * @env: ...
 *
 */
void prompt(char **av, char **env)
{
	char *linepr = NULL;
	size_t n = 0;
	ssize_t nd_prg;
	int i;
	char *argv[] = {NULL, NULL};
	int status;
	pid_t ch_id;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("kajoseph$ ");
		nd_prg = getline(&linepr, &n, stdin);
		if (nd_prg == -1)
		{
			free(linepr);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (linepr[i])
		{
			if (linepr[i] == '\n')
				linepr[i] = 0;
			i++;
		}
		argv[0] = linepr;
		ch_id = fork();
		if (ch_id == -1)
		{
			free(linepr);
			exit(EXIT_FAILURE);
		}
		if (ch_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}

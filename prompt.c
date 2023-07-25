#include "shell.h"

/**
 * prompt - displays a prompt...
 * @av: ...
 * @env: ...
 *
 */
void prompt(char **av, char **env)
{
#define MAX_COMMAND 10
	char *argv[MAX_COMMAND], *linepr = NULL;
	size_t n = 0;
	ssize_t nd_prg;
	int status, i, j;
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
		j = 0;
		argv[j] = strtok(linepr, " ");
		while (argv[j])
			argv[++j] = strtok(NULL, " ");
		ch_id = fork();
		if (ch_id == -1)
		{
			free(linepr);
			exit(EXIT_FAILURE);
		} else if (ch_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		} else
			wait(&status);
	}
}

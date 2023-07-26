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
			write(1, "(simple_shell) $ ", sizeof("(simple_shell) $ ") - 1);
		nd_prg = getline(&linepr, &n, stdin);
		i = 0;
		j = 0;
		initProcess(linepr, nd_prg, i, j, argv);
		/* strip(lineptr); */
		/* tokenize(argv, lineptr); */

		ch_id = fork();
		waitpid(ch_id, &status, 0);
		if (ch_id == -1)
		{
			free(linepr);
			exit(EXIT_FAILURE);
		} else if (ch_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				perror(av[0]);
		} else
			wait(&status);
	}
}

/**
 * initProcess - inits process...
 * @linepr: ...
 * @nd_prg: ...
 * @i: ...
 * @j: ...
 * @argv: ...
 *
 */
void initProcess(char *linepr, ssize_t nd_prg, int i, int j, char *argv[])
{
	if (nd_prg == -1)
	{
		free(linepr);
		exit(EXIT_FAILURE);
	}
	while (linepr[i])
	{
		if (linepr[i] == '\n')
			linepr[i] = 0;
		i++;
	}
	argv[j] = strtok(linepr, " ");
	while (argv[j])
		argv[++j] = strtok(NULL, " ");
}


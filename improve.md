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
	char *argv[MAX_COMMAND], *lineptr = NULL;

	int status;
	pid_t ch_id;

	while (1)
	{
		initProcess(lineptr);
		strip(lineptr);
		tokenize(argv, lineptr);
	
		ch_id = fork();
		if (ch_id == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		} else if (ch_id == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		} else
			wait(&status);
	}
}

void initProcess(char *lineptr) {
	ssize_t nd_prg;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf("kajoseph$ ");
	nd_prg = getline(&lineptr, &n, stdin);
	if (nd_prg == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	printf("Init finished");
}

void strip(char *lineptr) {
	int i = 0;
	while (&lineptr[i])
	{
		if (lineptr[i] == '\n')
			lineptr[i] = 0;
		i++;
	}
	printf("Strip finished");
}

void tokenize(char *argv[], char *lineptr) {
	int i = 0;
	
	argv[i] = strtok(lineptr, " ");
/*
	while (argv[i])
		argv[++i] = strtok(NULL, " ");
*/
}



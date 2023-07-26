#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int ac, char **av, char **env);
void prompt(char **av, char **env);
void initProcess(char *linepr, ssize_t nd_prg, int i, int j, char *argv[]);
void strip(char *lineptr);
void tokenize(char *argv[], char *lineptr);

#endif

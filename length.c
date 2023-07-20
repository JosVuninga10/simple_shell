#include "shell.h"

/**
 * get_length - count the number of char in a word
 * @strg: char to count
 * by Jos
 * Return: 0
 */


int get_length(char *strg)
{
	int length = 0;

	while (strg[length] != '\0')
	{
	       length++;
	}
	return (length);
}

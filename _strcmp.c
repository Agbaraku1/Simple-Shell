#include "shell.h"

/**
 * _strcmp -will compare two strings
 * @s1: is string 1
 * @s2: is string 2
 * Return: int that tells num spaces in between, (0) if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}

#include "shell.h"

/**
 * parsero - it will parse/separate text of a string into tokens
 * Space is used as a delimiter
 * @l: is a char pointer storing user input
 * Return: a char double pointer comprised of a char pointers
 */

char **parsero(char *l)
{
char **args;

char *parsed = NULL;
char *parsed2 = NULL;
char *linecpy = NULL;

int arg_n = 0, i = 0;

linecpy = _strdup(l);
parsed = strtok(linecpy, " \t");

while (parsed != NULL)
{
arg_n++;
parsed = strtok(NULL, " \t");
}

args = malloc(sizeof(char *) * (arg_n + 1));

if (args == NULL)
return (NULL);

parsed2 = strtok(l, " \t");

while (parsed2 != NULL)
{
args[i] = parsed2;
parsed2 = strtok(NULL, " \t");
i++;
}

args[i] = NULL;
free(linecpy);
return (args);
}

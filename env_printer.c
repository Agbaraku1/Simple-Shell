#include "shell.h"

/**
* env_printer - will print the environment variable
* @env: is the environment variable to be printed
* @ex_sts: is the exit status
* Return: Always (0) success
**/

int env_printer(char **env, int *ex_sts)
{
unsigned int i = 0;
while (env[i] != NULL)
{
str_printer(env[i]);
ponchar('\n');
i++;
}
*ex_sts = 0;
return (EXIT_SUCCESS);
}

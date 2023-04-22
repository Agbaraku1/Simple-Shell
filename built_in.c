#include "shell.h"

/**
* builtins -will help to implement the exit and printenv builtins
* @input: is the input buffer
* @args: is the parsed arguments
* @env: is the evironment
* @ex_st: is the exit status
* Return: void
**/

void builtins(char *input, char **args, char **env, int *ex_st)
{

if (_strcmp(args[0], "exit") == 0)
{
free(args);
free(input);
exit(*ex_st);
}

if (_strcmp(args[0], "env") == 0)
env_printer(env, ex_st);
}

#include "shell.h"

/**
 * _which - brings out command by appending it with a matching PATH directory
 * @str: is the first command user typed into shell
 * @env:is an  environmental variable
 * Return: a copy of the sorted out command
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;


	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);


	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{

			free_double_ptr(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	free_double_ptr(toks);
	return (str);
}

#include "shell.h"

/**
 * c_strcat - will concatenate two strings ignoring the first character ("~" in cd)
 * @dest: is a string to be appended to
 * @src:is the string to append
 * Return: is the concatenated string
 */
char *c_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;


	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	j = 1; 
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
 * c_setenv - custom _setenv will concatenate the string first before setting
 * @env: is the environmental variable linked list
 * @name:is the  environmental variable name
 * @dir:is the  directory path 
 * Return: (0) on success 
 */
int c_setenv(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	index = find_env(*env, name); 

	
	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}

/**
 * cd_only -will  change directory to home
 * @env: will bring in env linked list to update PATH and OLDPWD
 * @current: will bring in current working directotry
 */
void cd_only(list_t *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	c_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PWD", current);
	free(current);
	free(home);
}
/**
 * cd_execute -will  execute the cd
 * @env: brings environmental linked list to update PATH and OLDPWD
 * @current: brings in current working directotry
 * @dir: brings in dir path to change to
 * @str: brings in the 1st argument to write out the error
 * @num: brings in the line number to write out the error
 * Return: (0) if success (2) for fail
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * _cd - used to change directory
 * @str: is the user's typed in command
 * @env: is an enviromental linked list to retrieve HOME and OLDPWD paths
 * @num: is the nth user's command, to be used at error message
 * Return: (0) if success (<S-F9>2) for fail
 */
int _cd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	current = getcwd(current, 0); 
	if (str[1] != NULL)
	{
		if (str[1][0] == '~') 
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-');
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else
		cd_only(env, current);
	free_double_ptr(str); 
	return (exit_stat);
}

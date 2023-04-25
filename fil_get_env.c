#include "shell.h"

/**
 * c_strdup - its a custom string duplication; excludes starts bytes
 * @str: the string to duplicate (e.g. env_ var PATH=/bin:/bin/ls)
 * @cs: its the number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string (e.g. /bin:/bin/ls)
 */
char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}

/**
 * get_env - help find and returns a copy of the requested env_ var
 * @str: the string to store it in
 * @env: the entire set of env_ var
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (c_strdup(env->var, cs));
}

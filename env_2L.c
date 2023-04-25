#include "shell.h"

/**
 * env_linked_list - it creates a linked list from env_ var
 * @env: environmental variables (env_ var)
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - it prints environmental variables
 * @str: enables the user's command into shell (i.e. "env")
 * @env: environmental variables (env_ var)
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}


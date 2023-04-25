#include "shell.h"

/**
 * not_found - it writes error ("sh: 1: lss: not found")
 * @str: the user's typed command
 * @c_n: its the nth user's typed command
 * @env: brings in environmental variables linked list to write shell name
 */
void not_found(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cant_cd_to - it writes error ("sh: 2: cd: can't cd to xyz")
 * @str: the user's typed argument after the cmd cd
 * @c_n: the nth user's typed command
 * @env: it brings in env_ var linked list to write shell name
 */
void cant_cd_to(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * illegal_number - it write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: denotes the user's typed argument after the cmd exit
 * @c_n: nth user's typed command
 * @env: it brings in env_ var linked list to write shell name
 */
void illegal_number(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}

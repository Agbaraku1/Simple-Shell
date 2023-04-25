#include "shell.h"

/**
 * t_strlen - will return the token's string length for mallocing
 * @str:is a token
 * @pos: is the index position in user's command typed into shell
 * @delm: is the delimeter
 * Return:is the token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}

/**
 * t_size - will return number of delim while ignoring continuous delim
 * @str: is the user's command typed into shell
 * @delm: is the delimeter
 * Return: is the number of delims therefore  (num token = delims + 1)
 */
int t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{

			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{

			num_delm--;
		}
		i++;
	}
	return (num_delm);
}

/**
 * ignore_delm -will return a version of string without preceeding delims
 * @str: is a string
 * @delm: is the delimiter
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - will tokenize a string and returns an array of tokens
 * @str: is the user's command to be typed into shell
 * @delm:is the  delimeter
 * Return: an array of the tokens
 */
char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];

	str = ignore_delm(str, d_ch);

	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0';
			t++;
		}

		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}

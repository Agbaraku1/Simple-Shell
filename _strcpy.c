#include "shell.h"

/**
 * _strcpy - will copy the string pointed to by the src, which includes the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: will copy source to the buffer
 * @src: is the source to copy
 * Return:the copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

#include "shell.h"

/**
* nnline - will be used to remove the new line with the NULL character
* @in: is the new line
* Return: void
**/

void nnline(char *in)
{
int i = 0;
while (in[i])
{
if (in[i] == '\n')
{
in[i] = '\0';
return;
}
i++;
}
}

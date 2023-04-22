#include "shell.h"

/**
* free_matrix - it will free a 2D matrix of int pointers
* @matrix: is the char double pointer to be freed
* @height: is the int for height of 2D array to be passed
* Return: void
**/

void free_matrix(char **matrix, int height)
{
int z;
for (z = 0; z < height; z++)
free(matrix[z]);
free(matrix);
}

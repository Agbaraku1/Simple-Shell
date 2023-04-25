#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* it removes new line */
void nnline(char *in);

/* it will Write a char in stdout */
int ponchar(char c);

/* it will Print a string */
void str_printer(char *s);

/* Tries to Compares 2 strings */
int _strcmp(char *s1, char *s2);

/* It will  measure the lenght of a string */
int _strlen(char *s);

/* it Concatenates 2 strings */
char *_strcat(char *dest, char *src);

/* it Copy's a string pointed to src */
char *_strcpy(char *dest, char *src);

/* it Duplicates a string */
char *_strdup(char *str);

/* it will parse/separate text of a string into tokens */
char **parsero(char *l);

/* it will help to implement exit env_printer builtins */
void builtins(char *input, char **args, char **env, int *ex_st);

/* it prints the enviroment variable */
int env_printer(char **env, int *ex_sts);

/* Prints a special number */
void int_printer(int *atte);

/* Prints the path string */
char *str_path(char *dir, char *fst);

/* Prints the enviroment PATH */
int _path(char *fst, char **inpt, char **env, int *ex_st);

/* it executes process in the main shell */
void _xcute(int status, char **args, int *ex_st, int *cnt);

/* it handles special characters and errors at typing commands */
int super_char(char *buffer, ssize_t bytes, int *ex_st);

/* it helps to free a matrix of pointers */
void free_matrix(char **matrix, int height);
#endif


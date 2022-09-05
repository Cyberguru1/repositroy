#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFSIZE 1024

/**
 * struct data - sturct data contains some runtime  data
 * @av: argument vector
 * @input: command line inputed by user
 * @args: tokens of the comand line
 * @statu: last status of the shell
 * @counter: lines counter
 * @_environ: enviromental variable
 * @pid: process id of the shell
 */
typedef struct data
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **__environ;
    char *pid;
}dshell;


/* getlin */
ssize_t get_line(char **buff, size_t *buffsize, FILE *fp);

/* strtoken */
unsigned int check_delimeter(char c, const char *str);
char *_strtok(char *str, const char *delim);
char **parse_cmd(char *input);

/* memory management */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memcpy(char *dest, char *src, unsigned int n);
void free_all(char **ptr, char *line);
char *_memset(char *str, char fill, unsigned int num);
void *_calloc(unsigned int size);

/* strops */
int _putchar(char c);
void _puts(char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *first_str, char *second_str);
int _strncmp(char *s1, char *s2, size_t n);
char *_strndup(char *s1, char *s2);
void revstr(char *s);
int cmpChar(char str1[], const char *del);
int _isdigit(const char *s);
int _strspn(char *s, char *a);
char *_strcat(char *s1, const char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *s1);

/* bulilib */
int geetlen(int n);
int _atoi(char *s);
char *_itoa(int n);

/* error handling */
char *strcat_cd(dshell *, char *, char *, char *);
char *error_get_cd(dshell *datash);
char *error_not_found(dshell *datash);
char *error_exit_shell(dshell *datash);
char *error_get_alias(char **args);
char *error_env(dshell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(dshell *datash);
int get_error(dshell *datash, int eval);

/* check syntax */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(dshell *datash, char *input, int i, int bool);
int check_syntax(dshell *datash, char *input);




#endif

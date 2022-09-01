#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFSIZE 1024

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
void _strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);
int _strcmp(char *first_str, char *second_str);


#endif

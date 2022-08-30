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
#endif

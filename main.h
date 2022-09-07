#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data - sturct data contains some runtime  data
 * @av: argument vector
 * @input: command line inputed by user
 * @args: tokens of the comand line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: enviromental variable
 * @pid: process id of the shell
 */
typedef struct data
{	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} dshell;
/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/* getlin */
ssize_t get_line(char **buff, size_t *buffsize, FILE *fp);
char *read_line(int *i_eof);

/* strtoken */
unsigned int check_delimeter(char c, const char *str);
char *_strtok(char *str, const char *delim);
char **parse_cmd(char *input);

/* memory management */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);


/* strops */
int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *first_str, char *second_str);
int _strncmp(char *s1, char *s2, size_t n);
char *_strndup(char *s1, char *s2);

void revstr(char *s);
int cmp_Chars(char str1[], const char *del);
int _isdigit(const char *s);
int _strspn(char *s, char *a);
char *_strcat(char *s1, const char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *s1);

/* bulilib */
int geetlen(int n);
int _atoi(char *s);
char *_itoa(int n);

/* aray_cmd */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, dshell *datash);
int split_commands(dshell *datash, char *input);
char **split_line(char *input);

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

/* input_check */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(dshell *datash, char *input, int i, int bool);
int check_syntax(dshell *datash, char *input);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(dshell *datash);
int check_error_cmd(char *dir, dshell *datash);
int cmd_exec(dshell *datash);
void get_sigint(int sig);
int exit_shell(dshell *datash);
int exec_line(dshell *datash);
int (*get_builtin(char *cmd))(dshell *);

/* env_ops.c */
void check_env(r_var **h, char *in, dshell *data);
int check_vars(r_var **h, char *in, char *st, dshell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, dshell *datash);

/* help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);
int get_help(dshell *datash);

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(dshell *datash);
} builtin_t;

/* lists.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* env.c */
char *_getenv(const char *name, char **_environ);
int _env(dshell *datash);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, dshell *datash);
int _setenv(dshell *datash);
int _unsetenv(dshell *datash);

/* cd.c */
void cd_dot(dshell *datash);
void cd_to(dshell *datash);
void cd_previous(dshell *datash);
void cd_to_home(dshell *datash);
int cd_shell(dshell *datash);

void shell_loop(dshell *datash);

#endif

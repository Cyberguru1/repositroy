#include "main.h"

/**
 * aux_help_env - Help information for the builtin env
 * Return: no return
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));

}
/**
 * aux_help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void aux_help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlen(help));
}


/**
 * aux_help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_exit - Help information fot the builint exit
 * Return: no return
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help - Help information for the builtin help.
 * Return: no return
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * aux_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(dshell *datash)
{

	if (datash->args[1] == 0)
		aux_help_general();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		aux_help();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
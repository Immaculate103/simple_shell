#include "shell.h"

/**
 * _myexit - facilitates shell exit
 * @info: a structure made up of probable arguments. Used for the management of
 *	 constant function prototype.
 *
 * Return: Must always return -1; depicts shell exit.
 */
int _myexit(info_t *info)
{
	if (info->argv[1] != NULL)
	{
		/* Attempt to convert exit code to int */
		char *endptr;
		int exitcode = strtol(info->argv[1], &endptr, 10);

		if (*endptr != '\0')
		{
			/* Non-numeric argument */
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}

		info->err_num = exitcode;
	}
	return (-1);
}

/**
 * _mycd - substitutes the processes' present folder
 * @info: a structure with probable argument. Used for the mgt of
 *        constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir = info->argv[1];
	char *prev_dir = NULL;

	if (!dir)
		dir = _getenv(info, "HOME=");

	else if (_strcmp(dir, "-") == 0)
	{
		prev_dir = _getenv(info, "OLDPWD=");
		if (!prev_dir)
		{
			print_error(info, "OLDPWD not set\n";
			return (1);
		}
		dir = prev_dir;
	}

	if (chdir(dir) == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(dir), _eputchar('\n');
		return (1);
	}

	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "pwd", getcwd(NULL, 0));

	return (0);
}

/**
 * _myhelp - prints data on commands available
 * @info: Structure consisting of the probable arguments. Used for the mgt
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char *help_info[] = {
		"help - display this help message",
		"cd - change the current working directory",
		"exit - exit the shell",
		"env - print the current environment",
		"setenv - set an environment variable",
		"unsetenv - unset an environment variable",
		"history - display command history"
	};
	int i;

	for (i = 0; i < sizeof(help_info) / sizeof(char *); i++)
	{
		_puts(help_info[i]);
		_putchar('\n');
	}
	return (0);
}

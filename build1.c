#include "shell.h"

/**
 * mylive – leaves the shell from the function given
 * @info: Structure possess potential arguments and
 * Used to maintain constant function prototype.
 * Return: leaves with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int mylive(info_l *info)
{
	int exitcheck;

	if (info->argv[1]) 
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Foreign number: ");
			eputs1(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mydisk -from the function alters the current 
 * directory of the process
 * @info: Structure possess potential arguments and
 * used to maintain constant function prototype.
 * Return: Always 0
 */
int mydisk(info_l *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getenv1(info, "HOME=");
		if (!dir)
			chdir_ret = 
				chdir((dir = getenv1(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!getenv1(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv1(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = getenv1(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		eputs1(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", getenv1(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * myhelp - from the function alters the current 
 * directory of the process
 * @info: Structure possess potential arguments and
 * Used to maintain constant function prototype.
 * Return: Always 0
 *by nexttosho
 */
int myhelp(info_l *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); 
	return (0);
}

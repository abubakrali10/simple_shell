#include "main.h"

/**
 * exit_arg - mange exit with arguments
 * @arr: array of command
 * @line: line reading
 * @error: number of line
 * @argv: array of main argument
 * Return: 1 or nothing
 */

int exit_arg(char **arr, char *line, int error, char *argv[])
{
	int state;
	char *c;

	state = str_to_num(arr[1]);
	if (state >= 256)
	{
		free_array(arr);
		free(line);
		exit(state - 256);
	}
	else if (state < 0)
	{
		c = num_to_str(error);
		write(STDOUT_FILENO, argv[0], string_len(argv[0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, c, string_len(c));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, arr[0], string_len(arr[0]));
		write(STDOUT_FILENO, ": Illegal number: ", 18);
		write(STDOUT_FILENO, arr[1], string_len(arr[1]));
		write(STDOUT_FILENO, "\n", 1);
		free(c);
		if (!isatty(STDIN_FILENO))
		{
			free_array(arr);
			free(line);
			exit(2);
		}
		else
			free_array(arr);
	}
	else
	{
		free_array(arr);
		free(line);
		exit(state);
	}

	return (1);
}

/**
 * shell_exit - exit the shell
 * @arr: first arg of a command
 * @line: line get by getline function
 * @null_case: stat of command
 * @error: number of line
 * @argv: array of arguments
 * Return: nothing
 */

int shell_exit(char **arr, char *line, int null_case, int error, char *argv[])
{
	if (string_cmp(arr[0], "exit") == 0)
	{
		if (arr[1] == NULL)
		{
			free_array(arr);
			free(line);
			if (null_case)
				exit(EXIT_SUCCESS);
			else
				exit(127);
		}
		else
		{
			if (exit_arg(arr, line, error, argv))
				return (1);
		}
	}

	return (0);
}

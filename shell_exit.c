#include "main.h"

/**
 * str_to_num - convert str to num
 * @str: string input
 * Return: number
 */

int str_to_num(char *str)
{
	int sign = 1, res = 0, i = 0;

	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		else
			res = (res * 10) + (str[i] - '0');
		i++;
	}

	return (res * sign);
}

/**
 * shell_exit - exit the shell
 * @arr: first arg of a command
 * @line: line get by getline function
 * Return: nothing
 */

void shell_exit(char **arr, char *line)
{
	int state;

	if (string_cmp(arr[0], "exit") == 0)
	{
		if (arr[1] == NULL)
		{
			free_array(arr);
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			state = str_to_num(arr[1]);
			free_array(arr);
			free(line);
			exit(state);
		}
	}
}

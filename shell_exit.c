#include "main.h"

/**
 * shell_exit - exit the shell
 * @arr: first arg of a command
 * Return: nothing
 */

void shell_exit(char **arr)
{
	if (string_cmp(arr[0], "exit") == 0)
	{
		if (arr[1] == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(atoi(arr[1]));
		}
	}
}

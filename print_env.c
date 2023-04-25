#include "main.h"

/**
 * print_env - print environment variables
 * @env: environment array
 * Return: nothing
 */

void print_env(char *env[])
{
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], string_len(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

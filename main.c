#include "main.h"

/**
 * main - entry function to shell program
 * @argc: arguments number
 * @argv: array of arguments
 * @env: array of enviromental variables
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *env[])
{
	char *line = NULL, **arr, *command;
	size_t n = 0;
	ssize_t line_res;
	struct stat st;
	(void)atgc;

	mode("$ ", 2);

	while ((line_res = getline(&line, &n, stdin)) != -1)
	{
		if (line_res == 1)
		{
			mode("$ ", 2);
			continue;
		}

		if (line[string_len(line) - 1] == '\n')
			line[string_len(line) - 1] = '\0';

		arr = string_to_array(line, ' ');
		command = check_command(env, arr[0], st);
		shell_exit(arr);

		run(arr, command, env, argv);

		mode("$ ", 2);
	}
	mode("\n", 1);

	return (0);
}

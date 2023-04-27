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
	int error = 0, null_case = 1;
	(void)argc;

	mode("$ ", 2);
	while ((line_res = getline(&line, &n, stdin)) != -1)
	{
		if (line[string_len(line) - 1] == '\n')
			line[string_len(line) - 1] = '\0';

		arr = string_to_array(line, ' ');
		if (arr == NULL)
		{
			mode("$ ", 2);
			continue;
		}
		error++;
		if (shell_exit(arr, line, null_case, error, argv))
		{
			null_case = 0;
			mode("$ ", 2);
			continue;
		}
		command = check_command(env, arr[0], st);

		null_case = run(arr, command, env, argv, error);

		mode("$ ", 2);
	}
	mode("\n", 1);
	free(line);
	if (!isatty(STDIN_FILENO))
		exit(127);

	return (0);
}

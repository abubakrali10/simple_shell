#include "main.h"

/**
 * forking - start forking
 * @child: pid of child
 * @arr: array of command
 * @command: full command path
 * @env: array of enviromental variables
 * Return: nothing
 */

void forking(pid_t child, char **arr, char *command, char *env[])
{
	if (child < 0)
	{
		perror("error");
		free_array(arr);
		free(command);
	}
	else if (child == 0)
	{
		if (execve(command, arr, env))
		{
			free_array(arr);
			free(command);
		}
		else
		{
			perror("error");
			free_array(arr);
			free(command);
		}
	}
	else
	{
		wait(NULL);
		free_array(arr);
		free(command);
	}
}

/**
 * run - execute command line and fork it
 * @arr: array of command
 * @command: full command path
 * @env: array of enviromental variables
 * @argv: array of main function arguments
 * @error: error number
 * Return: nothing
 */

int run(char **arr, char *command, char *env[], char *argv[], int error)
{
	char c[1];
	pid_t child;

	if (string_cmp(arr[0], "env") == 0)
	{
		error++;
		free_array(arr);
		free(command);
		print_env(env);
	}
	else if (command == NULL)
	{
		c[0] = '0' + error;
		write(STDOUT_FILENO, argv[0], string_len(argv[0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, c, 1);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, arr[0], string_len(arr[0]));
		write(STDOUT_FILENO, ": not found", 11);
		write(STDOUT_FILENO, "\n", 1);
		error++;
		free_array(arr);
		free(command);
	}
	else
	{
		child = fork();
		forking(child, arr, command, env);
		error++;
	}

	return (error);
}

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
 * Return: nothing
 */

void run(char **arr, char *command, char *env[], char *argv[])
{
	pid_t child;

	if (string_cmp(arr[0], "env") == 0)
	{
		free_array(arr);
		free(command);
		print_env(env);
	}
	else if (command == NULL)
	{
		perror(argv[0]);
		free_array(arr);
		free(command);
	}
	else
	{
		child = fork();
		forking(child, arr, command, env);
	}
}

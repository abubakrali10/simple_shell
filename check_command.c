#include "main.h"

/**
 * check_command - function check command is exist or not
 * @env: enviromental variables array
 * @arg: first word in array
 * @st: structure stat of file
 * Return: command if exit or null
 */

char *check_command(char *env[], char *arg, struct stat st)
{
	char **path_array, *temp, *path;
	int i = 0;

	if (stat(arg, &st) == 0)
	{
		path = string_conc(arg, "");
		return (path);
	}

	path_array = get_path(env);

	if (path_array == NULL)
	{
		perror("error");
		free_array(path_array);
		return (NULL);
	}

	while (path_array[i])
	{
		temp = string_conc(path_array[i], "/");
		path = string_conc(temp, arg);
		free(temp);
		if (stat(path, &st) == 0)
		{
			free_array(path_array);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(path_array);

	return (NULL);
}

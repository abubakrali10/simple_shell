#include "main.h"

/**
 * get_path - get array of enviromental variable path
 * @env: enviromental variable array
 * Return: array pointer
 */

char **get_path(char *env[])
{
	char **env_arr, *ptr;
	int i = 0, y = 0, j = 5;

	while (env[i])
	{
		if (string_search(env[i], "PATH=") == 0)
			break;
		i++;
	}

	ptr = malloc(sizeof(char) * (string_len(env[i]) - 4));
	if (ptr == NULL)
	{
		perror("error");
		free(ptr);
		return (NULL);
	}

	while (env[i][j])
	{
		ptr[y] = env[i][j];
		y++;
		j++;
	}
	ptr[y] = '\0';

	env_arr = string_to_array(ptr, ':');
	free(ptr);

	return (env_arr);
}

#include "main.h"

/**
 * file_len - get length of file content
 * @file_name: file name input
 * @st: structure of file state
 * Retrun: length
 */

int file_len(char *file_name, struct stat st)
{
  stat(file_name, &st);

  return (st.st_size);
}

/**
 * reading - read file content and save it
 * @file: open file dicriptor
 * @len: length of file content
 * Return: content
 */

char *reading(int file, int len)
{
  char *str;

  str = malloc(sizeof(char) * len);
  if (str == NULL)
  {
    free(str);
    return (NULL);
  }
  read(file, str, len);

  return (str);
}

/**
 * read_file - read command from files
 * @argv: array of main args
 * @env: array of enviromental variables
 * @st: structure state of file
 * Return: nothing
 */

void read_file(char *argv[], char *env[], struct stat st, int error, char *line)
{
  char **arr, *command, *str, **line_arr;
  int len, file, i = 0;

  file = open(argv[1], O_RDONLY);
  if (file < 0)
  {
    perror("error");
    exit(EXIT_FAILURE);
  }

  len = file_len(argv[1], st);
  str = reading(file, len);
  line_arr = string_to_array(str, '\n');
  free(str);
  while (line_arr[i])
  {

    if (string_len(line_arr[i]) < 1)
      continue;

    arr = string_to_array(line_arr[i], ' ');

    command = check_command(env, arr[0], st);
    shell_exit(arr, line);

    error = run(arr, command, env, argv, error);
    i++;
  }
  free_array(line_arr);
  close(file);

  exit(EXIT_SUCCESS);
}

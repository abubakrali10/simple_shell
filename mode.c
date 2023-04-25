#include "main.h"

/**
 * mode - check if the shell is in interactive mode or not
 * @text: text write to stdout
 * @len: text length
 * Return: nothing
 */

void mode(char *text, int len)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, text, len);
}

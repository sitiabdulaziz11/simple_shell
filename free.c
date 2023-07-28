#include "shell.h"

/**
 * free_tokens - free.
 * @tokens: tok.
 *
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;
	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

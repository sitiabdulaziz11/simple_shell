#include "shell.h"
/**
 * exeout - execute commands.
 * @argv: argument
 */
void exeout(char **argv)
{
	char *command = NULL, *act_comm = NULL;

	if (argv)
	{
		command = argv[0];
		act_comm = found_path(command);
		if (act_comm != NULL)
		{
			if (execve(act_comm, argv, environ) == -1)
				perror("Error executing the command");
			free(act_comm);
		}
		else
		{
			_printf("%s: %d: command not found", argv[0], 1);
		}
	}
}
/**
 * display_env - env.
 * @env: argumnt
 */
void display_env(const char **env)
{
	int i, l;

	while (env[l] != NULL)
		l++;
	env = malloc(sizeof(char *) * (l + 1));
	env[l] = NULL;

	for (i = 0; *env[i] != '\0'; i++)
	{
		_printf("%s", *env[i]);
	}
}

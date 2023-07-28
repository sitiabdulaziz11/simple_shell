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
			perror("Command not found");
		}
	}
}

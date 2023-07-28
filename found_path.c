#include "shell.h"
/**
 * found_path - get path
 * @comm: command
 *
 * Return: char
 */
char *found_path(char *comm)
{
	char *pth, *pth_copy, *tot;

	pth = getenv("PATH");
	if (!pth)
	{
		return (NULL);
	}
	pth_copy = _strdup(pth);
	if (!pth_copy)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	tot = find_exe(comm, pth_copy);
	free(pth_copy);
	return (tot);
}
/**
 * find_exe - exe find.
 * @comm: command
 * @path: path
 *
 * Return: val
 */
char *find_exe(char *comm, char *path)
{
	char *pth_tkn, *exe;

	pth_tkn = strtok(path, ":");
	while (pth_tkn)
	{
		exe = create_executable_path(pth_tkn, comm);
		if (exe)
		{
			if (file_exists(exe))
				return (exe);
			free(exe);
		}
		pth_tkn = strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * create_executable_path - path.
 * @directory: dir
 * @command: command
 *
 * Return: val
 */
char *create_executable_path(const char *directory, const char *command)
{
	char *exe, *p, *s;
	size_t dir_len, comm_len;

	p = (char *)directory;
	s = (char *)command;
	dir_len = _strlen(p);comm_len = _strlen(s);
	exe = malloc(dir_len + comm_len + 2);
	if (!exe)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	_strcpy(exe, p);
	_strcat(exe, "/");
	_strcat(exe, s);
	return (exe);
}
/**
 * file_exists - file found.
 * @filename: name of file.
 *
 * Return: val
 */
int file_exists(const char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer) == 0);
}

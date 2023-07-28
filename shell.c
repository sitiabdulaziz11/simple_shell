#include "shell.h"
/**
 * main - entry
 * @ac: argc
 * @av: argv
 *
 * Return: o
 */
int main(int ac, char **av, char *env[])
{

	(void)ac;
	(void)av;
	(void)env;
	/*for (i = 0; *env[i] != '\0'; i++)
	{
		_printf("%s", env[i]);
	}*/
	simple_shell_loop();

	return (0);
}
/**
 * simple_shell_loop - shell implementation.
 *
 */
void simple_shell_loop(void)
{
	char *ln, **tok;
	pid_t pid;
	int status;

	while (1)
	{
		_printf("$ ");
		ln = read_line();
		if (ln == NULL)
			break;
		tok = div_line(ln);
		if (tok != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				free_tokens(tok);
				free(ln);
				perror("Error: fork");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				exeout(tok);
				exit(EXIT_SUCCESS);
			}
			if (waitpid(pid, &status, 0) == -1)
			{
				free_tokens(tok);
				free(ln);
				perror("Error:wait");
				exit(EXIT_FAILURE);
			}
			free_tokens(tok);
		}
		free(ln);
	}
}
/**
 * read_line - line
 *
 * Return: char
 */
char *read_line(void)
{
	char *ln = NULL;
	size_t buf = 0;
	ssize_t nr;

	nr = getline(&ln, &buf, stdin);

	if (nr == -1)
	{
		free(ln);
		perror("Error getline");
		_putchar('\n');
		return (NULL);
	}
	if (ln[nr - 1] == '\n')
		ln[nr - 1] = '\0';
	return (ln);
}
/**
 * div_line - line divid.
 * @line: line.
 *
 * Return: char
 */
char **div_line(char *line)
{
	const char *delim = " \n";
	int i = 0;
	char **tokens = NULL;
	int n_tokens = 0;
	char *token;

	token = strtok(line, delim);
	while (token)
	{
		n_tokens++;
		token = strtok(NULL, delim);
	}
	if (n_tokens == 0)
		return (NULL);
	tokens = malloc(sizeof(char *) * (n_tokens + 1));
	if (tokens == NULL)
	{
		perror("oops: memory allocation error");
		return (NULL);
	}
	token = strtok(line, delim);
	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			while (i > 0)
			{
				free(tokens[i - 1]);
				i--;
			}
			free(tokens);
			perror("Oops: Memory allocation error");
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

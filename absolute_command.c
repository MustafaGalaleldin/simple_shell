#include "main.h"
/**
 * absolute_command - command with path check
 *
 * @av: argvs
 * @env: env variables
 * @sign: the sign
 * Return: command with path if its existed
 */
char *absolute_command(char **av, char **env, int *sign)
{
	char *tok;
	char *path;
	char *command, *path_cpy;
	struct stat st_var;

	if (stat(av[0], &st_var) == 0)
	{
		*sign = 0;
		return (av[0]);
	}
	path = get_path(env);
	path_cpy = _strdup(path);
	tok = strtok(path_cpy, ":");
	while (tok)
	{
		command = malloc(_strlen(av[0]) + _strlen(tok) + 2);
		if (!command)
			return (NULL);
		_strcpy(command, tok);
		_strcat(command, "/");
		_strcat(command, av[0]);
		if (stat(command, &st_var) == 0)
		{
			free(path_cpy);
			return (command);
		}
		free(command);
		tok = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}

#include "../main.h"
/**
 * main - simple shell program
 * @argc: argument numbers
 * @argv: argument vector
 * @env: the enviroment
 * Return: 0 on success
*/
int main(int __attribute__((unused))argc, char *argv[], char **env)
{
	char *buf = NULL, *buf_cpy, *tok, **av, *call_path;
	size_t buf_size = 0, count = 0, i = 0;
	int x = 1, y = 0;
	FILE *file;

	while (1)
	{
		if (argv[1])
		{
			file = fopen(argv[1], "r");
			if (!file)
			{
				perror(argv[0]);
				return (127);

			}
			if (getline(&buf, &buf_size, file) == -1)
			{
				free(buf);
				return (0);
			}
			fclose(file);
			y = 1;
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "^_^ ", 4);
		if (getline(&buf, &buf_size, stdin) == -1 /* || (buf[0] == 'e' &&
					buf[1] == 'x' && buf[2] == 'i' &&
					buf[3] == 't' && buf[4] == '\n')*/)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 2);
			free(buf);
			return (0); }
		}
		 if (buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' &&
				buf[3] == 't' && buf[4] == '\n')
		 {
			 free(buf);
			 exit(EXIT_SUCCESS);
		 }
		if (buf[0] == 'e' && buf[1] == 'n' && buf[2] == 'v')
		{
			while (environ[i])
			{
				write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
			i = 0;
			
			continue;
		}
		buf_cpy = _strdup(buf);
		tok = my_strtok(buf_cpy, " \n");
		if (!tok || tok[i] == '#')
		{
			free(buf_cpy);
			continue; }
		while (tok)
		{
			count++;
			tok = my_strtok(NULL, " \n"); }
		count++;
		av = tokenizer(buf, count);
		call_path = absolute_command(av, env, &x);
		if (!call_path && !y)
		{
			perror(argv[0]);
			free(buf_cpy);
			/*free(buf);*/
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			continue;
			/*return (127);*/
		}
		if (y)
		{
			if (fork() == 0)
			{
				if ((execve(call_path, av, NULL)) == -1)
				{
					perror(argv[0]);
					free(buf_cpy);
					for (i = 0; av[i]; i++)
						free(av[i]);
					free(av);
					free(call_path);
					free(buf);
					wait(NULL);
					return (127);
				}
			}
			wait(NULL);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(buf_cpy);
			free(call_path);
			free(av);
			free(buf);
			return (0);
		}
		if (fork() == 0)
		{
			if ((execve(call_path, av, NULL)) == -1)
			{
				perror(argv[0]);
				return (-1);
			}
		}
		wait(NULL);
		free(buf_cpy);
		if (x)
			free(call_path);
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);}
}

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
char *_strdup(const char *str);
char **tokenizer(char *buf, size_t count);
char *get_path(char **env);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *absolute_command(char **av, char **env, int *sign);
int _strlen(const char *s);
char *my_strtok(char *str, const char *delim);
char *my_getenv(char *env_var);
int _strncmp(const char *str1, const char *str2, size_t n);
int check_empty(char *_str);
int _strcmp(char *s1, char *s2);
void ch_dir(const char *link);

#endif

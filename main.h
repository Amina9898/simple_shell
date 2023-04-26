#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void print_prompt(void);

char *get_line(void);

char **split_string(char *buf, char **env);

char **check_path(char *path);

char **search_env(char **env);

int cmd_status(char **user_input, char **path);

int execute(char **user_input, int status, char **env, char **argv);

void print_env(char **env);

void _free(char **argv);

int _strlen(char *string);

char *_strcpy(char *s1, char *s2);

char *_strcat(char *s1, char *s2);

int _strcmp(char *s1, char *s2);

char *_strdup(char *string);

void sig_handler(int sig);

char *_getenv(char *name);

int handle_error(char *argv, char *cmd);

#endif

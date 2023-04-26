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

char **split_string(char *buf);

char *check_path(char **argv);

void execute(char **av, char *name);

void print_env(void);

void _free(char **argv);

int _strlen(char *string);

char *_strcpy(char *s1, char *s2);

char *_strcat(char *s1, char *s2);

int _strcmp(char *s1, char *s2);

char *_strdup(char *string);

void EOF_handle(int get, char *buf);

void sig_handler(int sig);

#endif

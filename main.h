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

extern char **environ;

void print_prompt(void);

char **split_string(char *buf);
char *check_path(char **argv);

#endif

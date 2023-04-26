#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void)
{
    char *args[MAX_LINE/2 + 1];
    char *cmd = NULL;
    size_t cmd_size = 0;
    int should_run = 1;
    int exit_status = 0;
    pid_t pid;
    char **env = __environ;
    int i;
    char *token;

    while (should_run)
    {
        printf("osh> ");
        fflush(stdout);

        if (getline(&cmd, &cmd_size, stdin) == -1)
        {
            break;
        }

        i = 0;
        token = strtok(cmd, " \t\n");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
        {
            if (args[1] != NULL)
            {
                exit_status = atoi(args[1]);
            }
            exit(exit_status);
        }

        if (strcmp(args[0], "env") == 0)
        {
            while (*env)
            {
                printf("%s\n", *env++);
            }
            continue;
        }

        pid = fork();
        if (pid < 0)
        {
            fprintf(stderr, "Failed to fork process\n");
            return 1;
        }

        if (pid == 0)
        {
            execve(args[0], args, env);
            fprintf(stderr, "Failed to execute command: %s\n", args[0]);
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    free(cmd);
    return 0;
}

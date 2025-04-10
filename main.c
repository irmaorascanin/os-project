#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

int execute_command(char *command, char **args);

void display_prompt() {
    printf("prompt$ ");
}

void parse_input(char *input, char **args) {
    int i = 0;
    args[i] = strtok(input, " \t\n");
    while (args[i] != NULL) {
        args[++i] = strtok(NULL, " \t\n");
    }
}

int execute_command(char *command, char **args) {
    if (strcmp(command, "exit") == 0) {
        return 0; // Exit the shell
    } else if (strcmp(command, "cp") == 0) {
        if (fork() == 0) {
            execvp("./commands/cp", args);  // Execute cp command
            perror("execvp failed");
            exit(1);
        }
    } else if (strcmp(command, "history") == 0) {
        if (fork() == 0) {
            execvp("./commands/history", args);  // Execute history command
            perror("execvp failed");
            exit(1);
        }
    } else if (strcmp(command, "free") == 0) {
        if (fork() == 0) {
            execvp("./commands/free", args);  // Execute free command
            perror("execvp failed");
            exit(1);
        }
    } else if (strcmp(command, "fortune") == 0) {
        if (fork() == 0) {
            execvp("./commands/fortune", args);  // Execute fortune command
            perror("execvp failed");
            exit(1);
        }
    } else {
        printf("Command not found: %s\n", command);
    }

    wait(NULL);  // Wait for child process to finish
    return 1;    // Continue running shell
}

int main() {
    char input[MAX_CMD_LEN];
    char *args[MAX_ARGS];

    while (1) {
        display_prompt();
        if (!fgets(input, MAX_CMD_LEN, stdin)) break;

        parse_input(input, args);

        if (args[0] == NULL) continue;  // Skip if empty input
        if (execute_command(args[0], args) == 0) break;  // Exit if "exit" is typed
    }

    return 0;
}

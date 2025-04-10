#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HISTORY_FILE "history.txt"
#define MAX_HISTORY 100

void add_to_history(const char *command) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (file == NULL) {
        perror("Error opening history file");
        return;
    }

    fprintf(file, "%s\n", command);
    fclose(file);
}

void display_history() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (file == NULL) {
        perror("Error opening history file");
        return;
    }

    char line[1024];
    int line_number = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_number++, line);
    }
    fclose(file);
}

void clear_history() {
    FILE *file = fopen(HISTORY_FILE, "w");
    if (file == NULL) {
        perror("Error clearing history file");
        return;
    }
    fclose(file);
    printf("History cleared\n");
}

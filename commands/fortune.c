#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *fortunes[] = {
    "The only limit to our realization of tomorrow is our doubts of today.",
    "Life is what happens when you're busy making other plans.",
    "In the middle of every difficulty lies opportunity.",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts."
};

void display_fortune() {
    srand(time(NULL));  // Seed for random number generation
    int random_index = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));
    printf("%s\n", fortunes[random_index]);
}

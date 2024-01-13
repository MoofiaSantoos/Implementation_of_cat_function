#include <getopt.h>
#include <stdio.h>

#include "parser.h"

int main(int argc, char **argv) {
    flags conf = {0};
    char *short_options = "beEnstTv";
    struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                    {"number", no_argument, NULL, 'n'},
                                    {"squeeze-blank", no_argument, NULL, 's'}};
    return 0;
}

void cat(char *filename) {                                            // Coding function itself
    FILE *file = fopen(filename, "r");                                // Opening and reading a file
    if (file == NULL) {                                               // Starting checking for wrong input
        perror("n/a");                                                // Prints error
        return;                                                       // Exits function
    }
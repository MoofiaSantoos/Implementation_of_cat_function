#include <getopt.h>
#include <stdio.h>


int main(int argc, char **argv) {
    config conf = {0};
    char *short_options = "beEnstTv";
    struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                    {"number", no_argument, NULL, 'n'},
                                    {"squeeze-blank", no_argument, NULL, 's'}};
    
    int error = parse_params(argc, argv, short_options, long_options, &conf);

    if (error) {
        return 1;
    }
    return 0;
}

// void cat(char *filename) {                                            // Coding function itself
//     FILE *file = fopen(filename, "r");                                // Opening and reading a file
//     if (file == NULL) {                                               // Starting checking for wrong input
//         perror("n/a");                                                // Prints error
//         return;                                                       // Exits function
//     }
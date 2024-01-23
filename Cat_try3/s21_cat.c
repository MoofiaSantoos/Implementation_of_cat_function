#include "s21_cat.h"



int main(int argc, char **argv) {
    cat_programm(argc, argv[1]);
}



void cat_programm(int argc, char *argv) {
    int ch;
    FILE *file = fopen(argv, "r");
    if (file == NULL) {
        perror("ERROR");
    }
    else {
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
    }
    fclose(file);
    }
}
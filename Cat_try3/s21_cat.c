#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_cat.h"
#include <getopt.h>



int main(int argc, char *argv) {
    void cat_programm(int argc, char *argv);
}



void cat_programm(int argc, char *argv) {
    int ch;
    FILE *file = fopen(argv, "r");
    while ((ch = fgetc(file)) != EOF) {
        for (int i = 1; i < argc; i++) {
            putchar(ch);
        }
    }
    fclose(file);
}
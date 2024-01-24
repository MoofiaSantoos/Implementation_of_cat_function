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

void cat_b(char *buffer, int buffLength, FILE *file) {
  int counter = 1;
  while (fgets(buffer, buffLength, file)) {
    if (buffer[0] != '\n') {
        printf("%6d%s", counter++, buffer);
    }
  }
}
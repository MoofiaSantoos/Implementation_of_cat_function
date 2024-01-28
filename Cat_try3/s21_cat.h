#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#define SIZE 256

typedef struct {
    int b, e, E, n, s, t, T, v;
} flags;

void cat_programm (int argc, char *argv, flags flags);
void cat_b(char *buffer, int buffLength, FILE *fptr);
void cat_n(char *buffer, int size, FILE *file);
void cat_s(char *buffer, int size, FILE *file);
void cat_v(FILE *file);
void cat_e(FILE *file);
void cat_E(FILE *file);
void cat_t(FILE *file);
void cat_T(FILE *file);
flags CatReadFlags(int argc, char *argv[]);


#endif
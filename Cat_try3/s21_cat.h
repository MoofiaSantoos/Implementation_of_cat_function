#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

typedef struct {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
} flags;

void cat_programm (int argc, char *argv);

#endif
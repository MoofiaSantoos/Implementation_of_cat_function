#ifndef PARSE_H
#define PARSE_H

//Объявляем структуру флагов для дальнейшего использования//
typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flags;

//Объявляем фунцкию для парсинга//
int parse_params(int argc, char **argv, char *short_options,
                 struct option long_options[], flags *conf);

#endif
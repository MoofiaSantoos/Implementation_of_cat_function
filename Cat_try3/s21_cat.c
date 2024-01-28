#include "s21_cat.h"

int main(int argc, char **argv)
{
    flags flags = CatReadFlags(argc, argv);
    cat_programm(argc, argv[2], flags);
}

flags CatReadFlags(int argc, char *argv[])
{
    struct option LongOptions[] = {
        {"number-nonblank", 0, NULL, 'b'},
        {"number", 0, NULL, 'n'},
        {"squeeze-blank", 0, NULL, 's'},
        {NULL, 0, NULL, 0}};
    int currentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL);
    flags flags = {0};
    while (currentFlag != -1)
    {
        switch (currentFlag)
        {
            break;
        case 'b':
            flags.b = 1;
            break;
        case 'e':
            flags.e = 1;
        case 'v':
            flags.v = 1;
            break;
        case 'E':
            flags.E = 1;
            break;
        case 'n':
            flags.n = 1;
            break;
        case 's':
            flags.s = 1;
            break;
        case 't':
            flags.t = 1;
            break;
        case 'T':
            flags.T = 1;
            break;
        }
        currentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL);
    }
    return flags;
}

void cat_programm(int argc, char *argv, flags flags)
{
    int ch;
    char buffer[SIZE];
    FILE *file = fopen(argv, "r");
    if (file == NULL)
    {
      perror("ERROR");
    }
    else if (flags.b)
    {
      cat_b(buffer, SIZE, file);
    }
    else if (flags.n)
    {
      cat_n(buffer, SIZE, file);
    }
    else if (flags.s)
    {
      cat_s(buffer, SIZE, file);
    }
    else if (flags.v)
    {
      cat_v(file);
    }
    else if (flags.e)
    {
      cat_e(file);
    }
    else if (flags.t)
    {
      cat_t(file);
    }
    else if (flags.T)
    {
      cat_T(file);
    }
    else if (flags.E)
    {
      cat_E(file);
    }
    else
    {
        while ((ch = fgetc(file)) != EOF)
        {
            putchar(ch);
        }
        fclose(file);
    }
}

void cat_b(char *buffer, int size, FILE *file)
{
    int counter = 1;
    while (fgets(buffer, size, file))
    {
        if (buffer[0] != '\n')
        {
            printf("%6d\t", counter++);
        }
        printf("%s", buffer);
    }
}

void cat_n(char *buffer, int size, FILE *file)
{
    int counter = 1;
    while (fgets(buffer, size, file))
    {
        printf("%6d\t%s", counter++, buffer);
    }
}

void cat_s(char *buffer, int size, FILE *file)
{
    int flag = 0;
    while (fgets(buffer, size, file))
    {
        if (buffer[0] == '\n')
        {
            if (flag == 0)
            {
                flag = 1;
                printf("%s", buffer);
            }
        }
        else
            flag = 0;
        if (flag == 0)
        {
            printf("%s", buffer);
        }
    }
}

void cat_v(FILE *file) {
  int c;
  while ((c = getc(file)) != EOF) {
    if ((c < 32 && c != '\n' && c != '\t') || c == 127) printf("^");
    if (c > 127 && c < 160) printf("M-^");
    if (c > 159 && c < 255) {
      printf("M-");
      c = c + 128;
    } else if ((c < 32 || (c > 126 && c < 255)) && c != '\n' && c != '\t') {
      if (c > 126 && c < 160)
        c = c - 64;
      else if (c < 126)
        c = c + 64;
      if (c >= 160 && c < 255) c = c + 128;
    }
    if (c == 255)
      printf("M-^?");
    else
      putc(c, stdout);
  }
}

void cat_e(FILE *file) {
  int c;
  while ((c = getc(file)) != EOF) {
    if (c == 10) printf("$");
    if ((c < 32 && c != '\n' && c != '\t') || c == 127) printf("^");
    if (c > 127 && c < 160) printf("M-^");
    if (c > 159 && c < 255) {
      printf("M-");
      c = c + 128;
    } else if ((c < 32 || (c > 126 && c < 255)) && c != '\n' && c != '\t') {
      if (c > 126 && c < 160)
        c = c - 64;
      else if (c < 126)
        c = c + 64;
      if (c >= 160 && c < 255) c = c + 128;
    }

    if (c == 255)
      printf("M-^?");
    else
      putc(c, stdout);
  }
}

void cat_E(FILE *file) {
  int c;
  while ((c = getc(file)) != EOF) {
    if (c == '\n') {
      printf("$");
    }
    putc(c, stdout);
  }
}

void cat_t(FILE *file) {
  int c;
  while ((c = getc(file)) != EOF) {
    if (c == 10) printf("$");
    if ((c < 32 && c != '\n' && c != '\t') || c == 127) printf("^");
    if (c > 127 && c < 160) printf("M-^");
    if (c > 159 && c < 255) {
      printf("M-");
      c = c + 128;
    } else if ((c < 32 || (c > 126 && c < 255)) && c != '\n' && c != '\t') {
      if (c > 126 && c < 160)
        c = c - 64;
      else if (c < 126)
        c = c + 64;
      if (c >= 160 && c < 255) c = c + 128;
    }
    if (c == 255)
      printf("M-^?");
    else
      putc(c, stdout);
  }
}

void cat_T(FILE *file) {
  int c;
  while ((c = getc(file)) != EOF) {
    if (c != '\t')
      putc(c, stdout);
    else
      printf("^I");
  }
}
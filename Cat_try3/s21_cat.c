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
            flags.e = 1;
            break;
        case 'n':
            flags.n = 1;
            break;
        case 's':
            flags.s = 1;
            break;
        case 't':
            flags.t = 1;
            flags.v = 1;
            break;
        case 'T':
            flags.t = 1;
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
    else if (flags.e)
    {
        cat_e(file, flags.v);
    }
    else if (flags.t)
    {
        cat_t(file, flags.v);
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


int transform(int ch) {
  if (ch == '\n' || ch == '\t')
    return ch;  // return is allowed in the pre-check
  if ((ch >= 0 && ch < 9) || (ch > 10 && ch < 32) || (ch > 126 && ch <= 160)) {
    printf("^");
    if (ch > 126) {
      ch -= 64;
    } else {
      ch += 64;
    }
  }
  return ch;
}

void cat_e(FILE *file, int v) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        // Если считанный символ - символ новой строки, выводим "$"
        if (ch == '\n') {
            putchar('$');
        }
    if (v == 1) {
        ch = transform(ch);
    }
    printf("%c", ch);
    }
}

void cat_t(FILE *file, int v) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        // Если считанный символ - символ новой строки, выводим "$"
        if (ch == '\t') {
            printf("^");
            ch = '|';
        }
    if (v == 1) {
        ch = transform(ch);
    }
    printf("%c", ch);
    }
}
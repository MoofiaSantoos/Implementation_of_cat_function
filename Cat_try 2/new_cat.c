#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include "new_cat.h"

typedef struct {
    bool NumberNonBlank;
    bool MarkEndList;
    bool NumberAll;
    bool SqueezeBlank;
    bool Tab;
    // bool PrintHidden;
} Flags;

Flags CatReadFlags(int argc, char *argv[]) {
    struct option LongOptions[] = {
        {"number-nonblank", 0, NULL, 'b'},
        {"number", 0, NULL, 'n'},
        {"squeeze-blank", 0, NULL, 's'},
        {NULL, 0, NULL, 0}
    };
    int CurrentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL);
    Flags flags = {false, false, false, false, false};
    for (;CurrentFlag != -1; 
        CurrentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL)) {
        switch (CurrentFlag) {
            break; case 'b':
            flags.NumberNonBlank = true;
            break; case 'e':
            flags.MarkEndList = true;
            // case 'v':
            // flags.PrintHidden = true;
            break; case 'E':
            flags.MarkEndList = true;
            break; case 'n':
            flags.NumberAll = true;
            break; case 's':
            flags.SqueezeBlank = true;
            // break; case 't':
            // flags.PrintHidden = true;
            case 'T':
            flags.Tab = true;
        }
    }
    return flags;
}

void CatFile(FILE *file, Flags flags, const char *table[static 256]){
    int c = 0; //Хранит в себе текущие циклы которые мы записали
    int last; //Переменная для использования с конкретными аргументами (?)
    (void)last;
    (void)flags;
    while (fread(&c, 1, 1, file) > 0) {
        printf("%s", table[c]);
    }
}

int main(int argc, char *argv[]) {
    Flags flags = CatReadFlags(argc, argv);
    const char *table[256];
    if (flags.NumberNonBlank)
        printf ("number non-blank lines\n");
    if (flags.MarkEndList)
        CatSetMarkEndList(table);
    if(flags.NumberAll)
        printf("number all\n");
    if (flags.SqueezeBlank)
        printf("squeeze\n");
    if(flags.Tab)
        CatSetTab(table);
    // if(flags.PrintHidden)
    //     //printf("print non-print\n");
    //     CatPrintHidden(table);
    CatFile(stdin, flags, table);
}
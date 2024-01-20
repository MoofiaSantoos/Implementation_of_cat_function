#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

typedef struct {
    bool NumberNonBlank;
    bool MarkEndList;
    bool NumberAll;
    bool SqueezeBlank;
    bool Tab;
    bool PrintHidden;
} Flags;

Flags CatReadFlags(int argc, char *argv[]) {
    struct option LongOptions[] = {
        {"number-nonblank", 0, NULL, 'b'},
        {"number", 0, NULL, 'n'},
        {"squeeze-blank", 0, NULL, 's'},
        {NULL, 0, NULL, 0}
    };
    int CurrentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL);
    Flags flags = {false, false, false, false, false, false};
    for (;CurrentFlag != -1; 
        CurrentFlag = getopt_long(argc, argv, "bevEnstT", LongOptions, NULL)) {
        switch (CurrentFlag) {
            break; case 'b':
            flags.NumberNonBlank = true;
            break; case 'e':
            flags.MarkEndList = true;
            case 'v':
            flags.PrintHidden = true;
            break; case 'E':
            flags.MarkEndList = true;
            break; case 'n':
            flags.NumberAll = true;
            break; case 's':
            flags.SqueezeBlank = true;
            break; case 't':
            flags.PrintHidden = true;
            case 'T':
            flags.Tab = true;
        }
    }
    return flags;
}

int main(int argc, char *argv[]) {
    (void) argc, (void)argv;
    Flags flags = CatReadFlags(argc, argv);
    if (flags.NumberNonBlank)
    printf ("number non-blank lines\n");
    if (flags.MarkEndList)
    printf("mark end of lines\n");
    if(flags.NumberAll)
    printf("number all\n");
    if (flags.SqueezeBlank)
    printf("squeeze\n");
    if(flags.Tab)
    printf("tab\n");
    if(flags.PrintHidden)
    printf("print non-printable\n");
}
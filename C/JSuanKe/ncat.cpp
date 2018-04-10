#include <stdio.h>
#include <string.h>
#include "roman.h"
 
typedef struct {
    int mark_r;
    FILE *fin;
    FILE *fout;
} Nact;
 
int init(int argc, char *argv[], Nact *args) {
    if (argc < 2) { return 0; }
    args->mark_r = (strcmp(argv[1], "-r") == 0 ? 1 : 0);
    args->fin = stdin;
    args->fout = stdout;
    if (argc >= 3) {
        args->fin = fopen(argv[2], "r");
        if (argc >= 4) {
            args->fout = fopen(argv[3], "w");
        }
    }
    return 1;
}
 
void In_Out(Nact *args) {
    if (args->fin == NULL || args->fout == NULL) return ;
    int lines = 1;
    int out_lines = 1;
    char str[25];
    char c;
    while (fscanf(args->fin, "%c", &c) != EOF) {
        if (out_lines == 1) {
            if (args->mark_r) {
                fprintf(args->fout, "%s\t", to_roman_numeral(str, lines));
            } else {
                fprintf(args->fout, "%d\t", lines);
            }
            out_lines = 0;
        }
        fprintf(args->fout, "%c", c);
        if (c == '\n') {
            out_lines = 1;
            ++lines;
        }
    }
    return ;
}

void close_all(Nact *args) {
    if (args->fin != stdin) {
        fclose(args->fin);
        args->fin = NULL;
    }
    if (args->fout != stdout) {
        fclose(args->fout);
        args->fout = NULL;
    }
    return ;
}
 
int main(int argc, char *argv[])
{
    Nact Parameters;
    if (init(argc, argv, &Parameters) == 0) {
        return 0;
    }
    In_Out(&Parameters);
    close_all(&Parameters);
    return 0;
}
 


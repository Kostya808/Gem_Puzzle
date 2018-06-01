#include <stddef.h>
#include <stdio.h>
#include "function.h"

int check_win(size_t size, int *puzzle)
{
    int i, g = 0;
    for (i = 0; i < size * size - 1; i++) {
        if (puzzle[i] == i + 1) {
            g = i + 1;
        } else {
            return 0;
        }
    }
    if (g == size * size - 1) {
        return 1;
    }
    return 0;
}

int record(size_t size, int move)
{
    int n = 0, count, i;
    char ch = '\n';
    FILE *in = fopen("record.txt", "r");
    if (in == NULL) {
        return 2;
    }
    while (!feof(in)) {
        if (fgetc(in) == '\n') {
            n++;
        }
    }
    fseek(in , 0, SEEK_SET);
    int records[n];
    for (count = 0; count < n; count++) {
        fscanf(in, "%d", &records[count]);
    }
    fclose(in);
    FILE *out = fopen("record.txt", "w");
    if (out == NULL) {
        return 3;
    }
    if ((records[size - 2] != 0 && records[size - 2] > move) || (records[size - 2] == 0)) {
        records[size - 2] = move;
    }
    for (i = 0; i < n; i++) {
        fprintf (out, "%d%c", records[i], ch);
    }
    fclose(out);
    return 0;
}

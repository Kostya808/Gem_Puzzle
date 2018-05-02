#include <stddef.h>

int check_win(size_t size, int *puzzle)
{
    int g = 0;
    for (int i = 0; i < size * size - 1; i++) {
        if (puzzle[i] > puzzle[i + 1]){
            g++;
        }
        else {
            return 0;
        }
    }
    if (g == size * size - 2){
        return -1;
    }
    return 0;
}
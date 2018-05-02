#include <stddef.h>

int check_win(size_t size, int *puzzle)
{
    int i, g = 0;
    for (i = 0; i < size * size - 1; i++) {
        if (puzzle[i] == i + 1){
            g = i + 1;
        }
        else {
            return 0;
        }
    }
    if (g == size * size - 1){
        return 1;
    }
    return 0;
}
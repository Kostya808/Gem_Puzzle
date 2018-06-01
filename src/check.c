#include "function.h"
#include <stdbool.h>
#include <stddef.h>

bool check (int *puzzle, unsigned int side_length)
{
    size_t i;
    for (i = 0; i < side_length * side_length - 1; ++i) {
        if ((puzzle[i] > puzzle[i + 1]) && (puzzle[i + 1] !=0)) {
            return true;
        }
    }
    if (puzzle[side_length * side_length - 1] == 0) {
        return false;
    }
    return true;
}

size_t check_complexity(int choice)
{
    size_t size = 0;
    if (choice == 0) {
        size = 2;
    }
    if (choice == 1) {
        size = 3;
    }
    if (choice == 2) {
        size = 4;
    }
    if (choice == 3) {
        size = 5;
    }
    if (choice == 4) {
        size = 6;
    }
    return size;
}

#include <stddef.h>
#include "function.h"

void init (int *puzzle, unsigned int side_length)
{
    size_t cell_idx;
    size_t cell_number = side_length * side_length;
    for (cell_idx = 0; cell_idx < cell_number - 1; ++cell_idx) {
        puzzle[cell_idx] = cell_idx + 1;
    }
    puzzle[cell_number - 1] = 0;
}

void mixing (int *puzzle, size_t size)
{
    bool check_result;
    do {
        shuffle (puzzle, size);
        check_result = check (puzzle, size);
    } while (check_result == false);
}

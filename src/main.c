#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <stdio.h>

int main()
{
    size_t size = complexity(), check_win = 0;    
    int * puzzle = (int *)malloc(sizeof(int)*size*size);
	if (puzzle == NULL)
	    return -1;
    init (puzzle, size);
    bool check_result;
    do {
	    shuffle (puzzle, size);
	    check_result = check (puzzle, size);
	} while (check_result == false);
    
	while (check_win != -1) {
	    interface(size, puzzle);
	    move_empty(size, puzzle);
		check_win = 0;
	}
    return 0;
}

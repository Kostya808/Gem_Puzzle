#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <stdio.h>

int main()
{
    size_t size = complexity();    
    int * puzzle = (int *)malloc(sizeof(int)*size*size); 
    init (puzzle, size);
    bool check_result;
    do {
	    shuffle (puzzle, size);
	    check_result = check (puzzle, size);
	} while (check_result == false);

    return 0;
}

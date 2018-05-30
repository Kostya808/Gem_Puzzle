#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <stddef.h>
#include <ncurses.h>

int main()
{
	int flag, buf, move = 0;
    size_t size = complexity(), win = 0, empty;    
    int * puzzle = (int *)malloc(sizeof(int)*size*size);
	if (puzzle == NULL)
	    return -1;
    init (puzzle, size);
    bool check_result;
    do {
	    shuffle (puzzle, size);
	    check_result = check (puzzle, size);
	} while (check_result == false);
    empty = search(puzzle, size * size, 0);
	while (win != 1) {
	    interface(size, puzzle);
	    buf = empty;
	    empty = move_cells(empty, size, puzzle);
	    if (empty == size * size)
	    {
	    	flag = quit();
	    	if(flag == 0)
		    	return 0;
		    empty = buf;
	    }
		if (empty == size * size - 1)
		    win = check_win(size, puzzle);
		move++;
	}
	record(size, move);
	quit_win();
    return 0;
}

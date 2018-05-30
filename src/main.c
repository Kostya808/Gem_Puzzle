#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <stddef.h>
#include <ncurses.h>

int main()
{
	int flag, buf, move = 0, rating, i;
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
	
    FILE *rec = fopen("record.txt", "r");
    if (rec == NULL) {
        return -1;
    }
	for(i = 0; i < size - 1; i++)
    	fscanf(rec, "%d", &rating);

    fclose(rec);

    while (win != 1) {
	    interface(size, puzzle, move, rating);
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
		if (buf != empty)
			move++;
	}
	record(size, move);
	quit_win();
    return 0;
}

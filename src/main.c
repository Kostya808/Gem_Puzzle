#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <stddef.h>
#include <time.h>
#include <ncurses.h>

int main()
{
	srand(time(NULL));
	int flag, buf, move = 0, rating, i, preventor = 0, exit = 0;
    size_t win = 0, empty;    
    
    while (exit == 0) {
		size_t size = complexity();
	    int * puzzle = (int *)malloc(sizeof(int)*size*size);
		if (puzzle == NULL)
		    return -1;
    	init (puzzle, size);
    	mixing (puzzle, size);

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
		    
		    if (empty == (size * size) + 1) {
			  	empty = buf;	
		    	flag = resolve(1);
		    	if (flag == 0) {
			    	init (puzzle, size);
    				mixing (puzzle, size);
				    empty = search(puzzle, size * size, 0);
				    move = 0;
				    preventor = 1;
		    	}
		    }

	    	if (empty == size * size) {
	    		flag = resolve(2);
	    		if (flag == 0)
			    	return 0;
			    empty = buf;
		    }
			if (empty == size * size - 1)
			    win = check_win(size, puzzle);
			if (buf != empty && preventor != 1)
				move++;
			if (preventor == 1)
				preventor = 0;
		}
		record(size, move);
		exit = quit_win();
		if (exit == 0)
			win = 0;
			move = 0;
	}
    return 0;
}

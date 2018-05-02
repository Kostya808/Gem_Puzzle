#include <ncurses.h>
#include <stddef.h>

void interface(size_t size, int * puzzle)
{
	clear();
	int i, j, e, k;
    initscr();
    curs_set(0); 
    keypad(stdscr, true); 
    for (k = 0; k < size; k++)
    	printw("---");
    printw("-");
	printw("\n");
    for (i = 0; i < size; i++){
    	for (j = 0; j < size; j++){
		    printw("|");
    		printw("%2.d", puzzle[i * size + j]);
    	}
    	printw("|");
    	printw("\n");
    	if (i != size - 1){
    		for (e = 0; e < size - 1; e++){
    			if (e == 0)
	    			printw("---+");
	    		if (e == size - 2)
	    			printw("---");
	    		else 
					printw("--+");
    		}
    	printw("\n");
    	}
    }
    for (k = 0; k < size; k++)
    	printw("---");
    printw("-");
	printw("\n");
    
    endwin();
}
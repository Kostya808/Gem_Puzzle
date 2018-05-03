#include <ncurses.h>
#include <stddef.h>

void interface(size_t size, int * puzzle)
{
    int i, j, k, count = 0;
    int row, col;
    const char *str3 = "---+--+---";
    const char *str4 = "---+--+--+---";
    const char *str5 = "---+--+--+--+---";
    const char *str6 = "---+--+--+--+--+---";

    clear();

    initscr();

    curs_set(0); 

    keypad(stdscr, true); 

    getmaxyx(stdscr, row, col); 

    start_color();

    init_pair(1,  COLOR_BLUE,    COLOR_BLACK);

    attron(COLOR_PAIR(1));

    for (k = 0; k < size; k++)
    	mvwprintw(stdscr, (row - size*2) / 2, col/2 - size*2 + k*3,"===");
    printw("=");
	printw("\n");
    for (i = 0; i < size; i++){
    	for (j = 0; j < size; j++){
		    mvwprintw(stdscr, (row - size*2) / 2 + i + 1 + count, col/2 - size*2 + j*3, "|");
    		printw("%2.d", puzzle[i * size + j]);
    	}
    	printw("|");
    	printw("\n");
        if (i != size - 1){
            if(size == 3)
                mvwprintw(stdscr, (row - size*2) / 2 + i + 2  + count, col/2 - size*2, "%s", str3);
            if(size == 4)
                mvwprintw(stdscr, (row - size*2) / 2 + i + 2  + count, col/2 - size*2, "%s", str4);
            if(size == 5)
                mvwprintw(stdscr, (row - size*2) / 2 + i + 2  + count, col/2 - size*2, "%s", str5);
            if(size == 6)
                mvwprintw(stdscr, (row - size*2) / 2 + i + 2  + count, col/2 - size*2, "%s", str6);
            printw("\n");
            count++;
        }
    }
    for (k = 0; k < size; k++)
    	mvwprintw(stdscr, (row - size*2) / 2 + i + 1 + count, col/2 - size*2 + k*3,"===");
    printw("=");
	printw("\n");
    
    endwin();
}
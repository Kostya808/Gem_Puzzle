#include <ncurses.h>
#include "function.h"

const char version[5][6] = {
    "(2x2)",
	"(3x3)",
    "(4x4)", 
    "(5x5)",
    "(6x6)"
};

int complexity()
{
	size_t choice = 0;
	int flag = 0, i = 0, row, col;
    
    initscr();                   
    
    getmaxyx(stdscr, row, col); 

    curs_set(0);
    
    keypad (stdscr, true); 
    
    start_color();
    
    init_pair(1,  COLOR_BLUE,    COLOR_BLACK);
    
    attron(COLOR_PAIR(1));    

    while (flag == 0){
    	clear();
        mvwprintw(stdscr, (row - 8) / 2, (col - 32) / 2, "Welcome to the game Gem puzzle!");
        mvwprintw(stdscr, (row - 5) / 2, (col - 35) / 2, "Choose the size of the game field:\n");
    	for (i = 0; i < 5; i++){
    		if (i == choice)
    			mvwprintw(stdscr, (row  + 2*i) / 2, (col - 15) / 2, ">Size");
    		else
    			mvwprintw(stdscr, (row  + 2*i) / 2, (col - 15) / 2, " Size");
    		printw("%s\n", version[i]);
    	}
        mvwprintw(stdscr, row - 2, col - col, "Use the keys: key_up, key_down, enter to select...");
    	switch (getch()){
    		case KEY_UP:
    			if (choice > 0)
    				choice--;
    			break;
    		case KEY_DOWN:
    			if (choice != 4)
    				choice++;
    			break;
    		case 10:
    			flag = 1;
    		break;
    	}
    }
    
    endwin();
    
    return check_complexity(choice);
}


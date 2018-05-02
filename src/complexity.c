#include <ncurses.h>
#include "function.h"

const char version[4][6] = {
	"(3x3)",
    "(4x4)", 
    "(5x5)",
    "(6x6)"
};

int complexity()
{
	size_t choice = 0;
	int flag = 0, i = 0;
    initscr();                   
    curs_set(0);
    keypad (stdscr, true); 
    printw("%s\n", version[i]);
    while (flag == 0){
    	clear();
        printw("Choose the difficulty of the game\n");
    	for (i = 0; i < 4; i++){
    		if (i == choice)
    			addch('>');
    		else
    			addch(' ');
    		printw("%s\n", version[i]);
    	}
    	switch (getch()){
    		case KEY_UP:
    			if (choice > 0)
    				choice--;
    			break;
    		case KEY_DOWN:
    			if (choice != 2)
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


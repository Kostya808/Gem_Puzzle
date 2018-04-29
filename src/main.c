#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init.h"
#include "shuffle.h"
#include "check.h"

const char version[3][6] = {
    "(4x4)", 
    "(5x5)",
    "(6x6)"
};

int main()
{
	unsigned int choice = 0, size;
	int flag = 0, i = 0;
    initscr();                   
    curs_set(0);
    keypad (stdscr, true); 
    printw("%s\n", version[i]);
    while (flag == 0) //Выбор уровня сложности{
    {
    	clear();
        printw("Choose the difficulty of the game\n");
    	for (i = 0; i < 3; i++)
    	{
    		if (i == choice)
    			addch('>');
    		else
    			addch(' ');
    		printw("%s\n", version[i]);
    	}
    	switch (getch())
    	{
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
    
    if (choice == 0)
    	size = 4;
    else if (choice == 1)
    	size = 5;
    else
    	size = 6; // }
    
    int * puzzle = (int *)malloc(sizeof(int)*size*size); //Создание матрицы с выбранным размером
    init (puzzle, size);
    bool check_result;
    do {
	    shuffle (puzzle, size);
	    check_result = check (puzzle, size);
	} while (check_result == false);
    return 0;
}

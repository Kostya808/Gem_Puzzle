#include <ncurses.h>
#include <stdlib.h>

int main()
{
	unsigned int choice = 0, size;
	int flag = 0, i;
	const char version[3][11] = {
    	"Easy(4x4)", 
    	"Medium(5x5)",
    	"Hard(6x6)", 
	};
    initscr();                   
    curs_set(0);
    keypad (stdscr, true); 
    while (flag == 0) //Выбор уровня сложности{
    {
    	clear();
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
    
    int * puzzle = (int *)malloc(sizeof(int)*size*size);   //Создание матрицы с выбранным размером 
    
    return 0;
}
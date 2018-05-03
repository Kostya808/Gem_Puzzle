#include <ncurses.h>
#include <stddef.h>

void interface(size_t size, int * puzzle)
{
    int i, j, k, count = 0;
    int row, col;
    const char *str2 = "---+---";
    const char *str3 = "---+--+---";
    const char *str4 = "---+--+--+---";
    const char *str5 = "---+--+--+--+---";
    const char *str6 = "---+--+--+--+--+---";

    clear();

    initscr();

    curs_set(0); 

    keypad(stdscr, true); 

    getmaxyx(stdscr, row, col); 

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
            if(size == 2)
                mvwprintw(stdscr, (row - size*2) / 2 + i + 2  + count, col/2 - size*2, "%s", str2);
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
    printw("");
    mvwprintw(stdscr, row - 2, 0, "Use the keys: key_up, key_down, key_right, key_left for moving...");
    mvwprintw(stdscr, row - 3, 0, "To exit, press ESC...");
    
    endwin();
}

int quit()
{
    int row, col, choice = 0, flag;

    initscr();

    clear();

    keypad(stdscr, true); 

    getmaxyx(stdscr, row, col); 

    while (flag == 0){
        clear();
        mvwprintw(stdscr, row / 2, (col - 34) / 2, "Are you sure you want to get out?");
        if (choice == 0){
                mvwaddch(stdscr, row / 2 + 1, (col - 34) / 2 + 3, '>');
                mvwprintw(stdscr, row / 2 + 1, (col - 34) / 2 + 4,"Yes, I give up");
                mvwaddch(stdscr, row / 2 + 2, (col - 34) / 2 + 3,' ');
                mvwprintw(stdscr, row / 2 + 2, (col - 34) / 2 + 4,"No, I changed my mind");
            }
            else{
                mvwaddch(stdscr, row / 2 + 1, (col - 34) / 2 + 3, ' ');
                mvwprintw(stdscr, row / 2 + 1, (col - 34) / 2 + 4,"Yes, I give up");
                mvwaddch(stdscr, row / 2 + 2, (col - 34) / 2 + 3,'>');
                mvwprintw(stdscr, row / 2 + 2, (col - 34) / 2 + 4,"No, I changed my mind");
            }
        mvwprintw(stdscr, row - 2, col - col, "Use the keys: key_up, key_down, enter to select...");
        switch (getch()){
            case KEY_UP:
                if (choice > 0)
                    choice--;
                break;
            case KEY_DOWN:
                if (choice != 1)
                    choice++;
                break;
            case 10:
                flag = 1;
            break;
        }
    }
    if (choice == 1){
        endwin();
        return 1;
    }

    else
        endwin(); 
        return 0;
}

void quit_win()
{
    int row, col;

    initscr();

    clear();

    getmaxyx(stdscr, row, col); 

    mvwprintw(stdscr, row / 2, (col - 10) / 2, "You win!");
    mvwprintw(stdscr, row - 1, 0, "Press any key...");

    getch();
    endwin();
}
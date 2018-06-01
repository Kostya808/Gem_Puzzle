#include <ncurses.h>
#include <stddef.h>

void interface(size_t size, int *puzzle, int move, int record)
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
    printw("Your best result: %d\n", record);
    printw("Number of moves made: %d\n", move);
    for (k = 0; k < size; k++) {
        mvwprintw(stdscr, (row - size * 2) / 2, col / 2 - size * 2 + k * 3,"===");
    }
    printw("=");
    printw("\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mvwprintw(stdscr, (row - size * 2) / 2 + i + 1 + count, col / 2 - size * 2 + j * 3, "|");
            printw("%2.d", puzzle[i * size + j]);
        }
        printw("|");
        printw("\n");
        if (i != size - 1) {
            if (size == 2) {
                mvwprintw(stdscr, (row - size * 2) / 2 + i + 2  + count, col / 2 - size * 2, "%s", str2);
            }
            if(size == 3) {
                mvwprintw(stdscr, (row - size * 2) / 2 + i + 2  + count, col / 2 - size * 2, "%s", str3);
            }
            if(size == 4) {
                mvwprintw(stdscr, (row - size * 2) / 2 + i + 2  + count, col / 2 - size * 2, "%s", str4);
            }
            if(size == 5) {
                mvwprintw(stdscr, (row - size * 2) / 2 + i + 2  + count, col / 2 - size * 2, "%s", str5);
            }
            if(size == 6) {
                mvwprintw(stdscr, (row - size * 2) / 2 + i + 2  + count, col / 2 - size * 2, "%s", str6);
            }
            printw("\n");
            count++;
        }
    }
    for (k = 0; k < size; k++) {
        mvwprintw(stdscr, (row - size * 2) / 2 + i + 1 + count, col / 2 - size * 2 + k * 3,"===");
    }
    printw("=");
    printw("\n");
    printw("");
    mvwprintw(stdscr, row - 2, 0, "Use the keys: key_up, key_down, key_right, key_left for moving...");
    mvwprintw(stdscr, row - 3, 0, "To exit press: esc...");
    mvwprintw(stdscr, row - 4, 0, "To shuffle the chips press: space_key...");

    endwin();
}

int resolve(int option)
{
    int row, col, choice = 0, flag;

    initscr();

    clear();

    keypad(stdscr, true);

    getmaxyx(stdscr, row, col);

    while (flag == 0) {
        clear();
        if (option == 1) {
            mvwprintw(stdscr, (row - 2) / 2, (col - 34) / 2, "Do you really want to start over?");
        } else if (option == 2) {
            mvwprintw(stdscr, (row - 2) / 2, (col - 34) / 2, "Are you sure you want to get out?");
            } else
                mvwprintw(stdscr, (row - 2) / 2, (col - 32) / 2, "Want to start a new game?");
        if (option != 3) {
            if (choice == 0) {
                mvwaddch(stdscr, row / 2 + 1, (col - 34) / 2 + 3, '>');
                mvwprintw(stdscr, row / 2 + 1, (col - 34) / 2 + 4,"Yes, I give up");
                mvwaddch(stdscr, row / 2 + 2, (col - 34) / 2 + 3,' ');
                mvwprintw(stdscr, row / 2 + 2, (col - 34) / 2 + 4,"No, I changed my mind");
            } else {
                mvwaddch(stdscr, row / 2 + 1, (col - 34) / 2 + 3, ' ');
                mvwprintw(stdscr, row / 2 + 1, (col - 34) / 2 + 4,"Yes, I give up");
                mvwaddch(stdscr, row / 2 + 2, (col - 34) / 2 + 3,'>');
                mvwprintw(stdscr, row / 2 + 2, (col - 34) / 2 + 4,"No, I changed my mind");
            }
        } else {
            if (choice == 0) {
                mvwaddch(stdscr, row / 2 + 1, (col - 18) / 2 + 3, '>');
                mvwprintw(stdscr, row / 2 + 1, (col - 18) / 2 + 4,"Yes");
                mvwaddch(stdscr, row / 2 + 2, (col - 18) / 2 + 3,' ');
                mvwprintw(stdscr, row / 2 + 2, (col - 18) / 2 + 4,"No");
            } else {
                mvwaddch(stdscr, row / 2 + 1, (col - 18) / 2 + 3, ' ');
                mvwprintw(stdscr, row / 2 + 1, (col - 18) / 2 + 4,"Yes");
                mvwaddch(stdscr, row / 2 + 2, (col - 18) / 2 + 3,'>');
                mvwprintw(stdscr, row / 2 + 2, (col - 18) / 2 + 4,"No");
            }
        }
        mvwprintw(stdscr, row - 2, col - col, "Use the keys: key_up, key_down, enter to select...");
        switch (getch()) {
        case KEY_UP:
            if (choice > 0) {
                choice--;
            }
            break;
        case KEY_DOWN:
            if (choice != 1) {
                choice++;
            }
            break;
        case 10:
            flag = 1;
            break;
        }
    }
    if (choice == 1) {
        endwin();
        return 1;
    } else
        endwin();
        return 0;
}

int quit_win()
{
    int row, col, flag;

    initscr();

    clear();

    getmaxyx(stdscr, row, col);

    mvwprintw(stdscr, row / 2, (col - 30) / 2, "Congratulations! You won!");
    mvwprintw(stdscr, row - 1, 0, "Press any key...");
    getch();
    endwin();
    flag = resolve(3);
    if (flag == 0) {
        return 0;
    }
    return 1;
}

#include <ncurses.h>
#include <stddef.h>


int search(int *puzzle, int n, int key)
{
  for (int i = 0; i < n; i++) {
    if (puzzle[i] == key)
      return i;
  }
  return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int move_empty(size_t size, int *puzzle)
{
    initscr();
    curs_set(0);
    keypad(stdscr, true);
    size_t empty = search(puzzle, size * size, 0), i = 0;
    if (empty != -1) {
        while (i != -1){
            switch (getch()) {
            case KEY_UP:
                if (empty >= size)
                    swap(&puzzle[empty], &puzzle[empty - size]);
                    return 0;
            case KEY_DOWN:
                if (empty <= size * size - 5)
                    swap(&puzzle[empty], &puzzle[empty + size]);
                    return 0;
            case KEY_LEFT:
                if (empty % size != 0)
                    swap(&puzzle[empty], &puzzle[empty - 1]);
                    return 0;
            case KEY_RIGHT:
                if (empty % size != size -1)
                    swap(&puzzle[empty], &puzzle[empty + 1]);
                    return 0;
            
            }
        }
        i = 0;
    }
    endwin();
    return -1;
}

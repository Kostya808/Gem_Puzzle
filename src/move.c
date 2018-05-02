#include <ncurses.h>
#include <stddef.h>


int search(int *puzzle, size_t n, int key)
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

size_t move_cells(size_t empty, size_t size, int *puzzle)
{
    initscr();
    curs_set(0); 
    keypad(stdscr, true);
    if (empty != -1) {
            switch (getch()) {
            case KEY_DOWN:
                if (empty >= size)
                    swap(&puzzle[empty], &puzzle[empty - size]);
                    empty = empty - size;
                    return empty;
                    endwin();
            case KEY_UP:
                if (empty <= size * size - (size +1))
                    swap(&puzzle[empty], &puzzle[empty + size]);
                    empty = empty + size;
                    return empty;
                    endwin();
            case KEY_RIGHT:
                if (empty % size != 0)
                    swap(&puzzle[empty], &puzzle[empty - 1]);
                    empty = empty -1;
                    return empty;
                    endwin();
            case KEY_LEFT:
                if (empty % size != size -1)
                    swap(&puzzle[empty], &puzzle[empty + 1]);
                    empty = empty + 1;
                    return empty;
                    endwin();
            
            }
    }
    return empty;
    endwin();
}

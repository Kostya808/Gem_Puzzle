#ifndef FUNCTION_H
#define FUNCTION_H

#include <stddef.h>

int complexity();
size_t check_complexity(int choice);
void init (int *puzzle, unsigned int side_length);
void shuffle (int* puzzle, unsigned int side_length);
bool check (int* puzzle, unsigned int side_length);
void interface(int size, int * puzzle);
size_t move_cells(size_t empty, size_t size, int *puzzle);
int search(int *puzzle, size_t n, int key);
void swap(int *a, int *b);
int check_win(size_t size, int *puzzle);
int quit();

#endif
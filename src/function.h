#ifndef FUNCTION_H
#define FUNCTION_H

#include <stddef.h>

int complexity();
size_t check_complexity(int choice);
void init (int *puzzle, unsigned int side_length);
void shuffle (int* puzzle, unsigned int side_length);
bool check (int* puzzle, unsigned int side_length);
void interface(int size, int * puzzle);
int move_empty(size_t size, int *puzzle);
int search(int *puzzle, int n, int key);
void swap(int *a, int *b);
int check_win(size_t size, int *puzzle);

#endif
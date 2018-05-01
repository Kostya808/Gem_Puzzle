#ifndef FUNCTION_H
#define FUNCTION_H

int complexity();
size_t check_complexity(int choice);
void init (int *puzzle, unsigned int side_length);
void shuffle (int* puzzle, unsigned int side_length);
bool check (int* puzzle, unsigned int side_length);

#endif
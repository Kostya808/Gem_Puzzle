#include <stdbool.h>
#include <stddef.h>

bool check (int* puzzle, unsigned int side_length)
{
	size_t row_num, col_num, e, k, N = 0, add = 0;
	for (row_num = 0; row_num < side_length; ++row_num){
		for (col_num = 0; col_num < side_length; ++col_num){
			if (puzzle[side_length*row_num+col_num] == 0)
				e = row_num + 1;
			do {
				++k;
				++add;
				if ((row_num == side_length - 1)&&(col_num == side_length - 1))
					k = 0;
			} while (puzzle[side_length*row_num+col_num] < puzzle[side_length*row_num+col_num+add]);
			N += k;
			k = 0;
			add = 0;
		}
	}
	N += e;
	if (N%2 == 0)
		return true;
	else
		return false;
}

size_t check_complexity(int choice)
{
    size_t size = 0;
    if (choice == 0)
        size = 4;
    if (choice == 1)
        size = 5;
    if (choice == 2)
        size = 6; 
    return size;
}
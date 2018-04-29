#include <time.h>
#include <stdlib.h>

void shuffle (int* puzzle, unsigned int side_length)
{
	srand(time(NULL));
	size_t row_num, col_num, a, b, tmp;
	for (row_num = 0; row_num < side_length; ++row_num){
		for (col_num = 0; col_num < side_length; ++j){
			a = rand () % (side_length - 1);
			b = rand () % (side_length - 1);
			tmp = puzzle[4*row_num+col_num];
			puzzle[4*row_num+col_num] = puzzle[4*a+b];
			puzzle[4*a+b] = tmp;
		}
	}
}

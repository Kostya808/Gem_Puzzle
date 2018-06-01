#include "function.h"
#include <stdbool.h>
#include <stddef.h>

bool check (int* puzzle, unsigned int side_length)
{
	size_t i;
	for (i = 0; i < side_length*side_length-1; ++i){
		if ((puzzle[i] > puzzle[i+1])&&(puzzle[i+1]!=0))
			return true;
	}
	if (puzzle[side_length*side_length-1] == 0)
		return false;
	return true;
	/*Памятник очень классному тех. заданию
	 * size_t row_num, col_num, e, k, N = 0, add = 1;
	for (row_num = 0; row_num < side_length; ++row_num){
		for (col_num = 0; col_num < side_length; ++col_num){
			k = 0;
			if (puzzle[side_length*row_num+col_num] == 0){
				e = (side_length*row_num+col_num)/side_length+1;
			}
			if (puzzle[side_length*row_num+col_num+add] == 0){
				if (side_length*row_num+col_num+add != side_length*side_length-1){
					++add;
					e = (side_length*row_num+col_num+add)/side_length+1;
				}
			}
			while (puzzle[side_length*row_num+col_num] < puzzle[side_length*row_num+col_num+add]){
				if ((side_length*row_num+col_num+add == side_length*side_length-1)||(side_length*row_num+col_num == side_length*side_length-1)){
					if (puzzle[side_length*row_num+col_num] < puzzle[side_length*row_num+col_num+add])
						k = 0;
					else
						++k;
					break;
				}
				if(puzzle[side_length*row_num+col_num+add+1] == 0){
					if (side_length*row_num+col_num+add+1 != side_length*side_length-1){
						++add;
						e = (side_length*row_num+col_num+add+1)/side_length+1;
					}
				}
				++k;
				++add;
			}
			if ((side_length*row_num+col_num+add != side_length*side_length-1)&&(side_length*row_num+col_num != side_length*side_length-1))
				++k;
			else 
				k = 0;
			N += k;
			k = 0;
			add = 1;
		} 
	}
	N += e;
	if ((N == e)&&(puzzle[side_length*side_length-1] == 0))
		return false;
	//if (side_length%2 == 1)
	//	++N;
	if (N%2 == 0)
		return true;
	else
		return false; */
}

size_t check_complexity(int choice)
{
    size_t size = 0;
    if (choice == 0)
        size = 2;
    if (choice == 1)
        size = 3;
    if (choice == 2)
        size = 4;
	if (choice == 3)
        size = 5;
    if (choice == 4)
    	size = 6;
    return size;
}

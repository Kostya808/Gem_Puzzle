#include <time.h>
#include <stdlib.h>
#include <stddef.h>

#define STEP_ABSENT 0
#define STEP_UP 1
#define STEP_DOWN 2
#define STEP_RIGHT 3
#define STEP_LEFT 4

void shuffle (int* puzzle, unsigned int side_length)
{
	
	size_t cur_row = side_length - 1;
	size_t cur_col = side_length - 1;
	size_t i;
	int steps[4];
	size_t step = STEP_ABSENT;
	for (i = 0; i < 10000; ++i){
		size_t step_num = 0;
		if (cur_row != 0 && step !=STEP_UP)
			steps[step_num++] = STEP_UP;
		if (cur_row != side_length-1 && step != STEP_DOWN)
			steps[step_num++] = STEP_DOWN;
		if (cur_col != side_length-1 && step != STEP_RIGHT)
			steps[step_num++] = STEP_RIGHT;
		if (cur_col != 0 && step != STEP_LEFT)
			steps[step_num++] = STEP_LEFT;
		step = steps[rand() % step_num];
		switch (step){
		case STEP_UP:
			//tmp = puzzle[side_length*cur_row+cur_col];
			puzzle[side_length*cur_row+cur_col] = puzzle[side_length*(cur_row-1)+cur_col];
			puzzle[side_length*(cur_row-1)+cur_col] = 0;
			--cur_row;
			break;
		case STEP_DOWN:
			//tmp = puzzle[side_length*cur_row+cur_col];
			puzzle[side_length*cur_row+cur_col] = puzzle[side_length*(cur_row+1)+cur_col];
			puzzle[side_length*(cur_row+1)+cur_col] = 0;
			++cur_row;
			break;
		case STEP_RIGHT:
			//tmp = puzzle[side_length*cur_row+cur_col];
			puzzle[side_length*cur_row+cur_col] = puzzle[side_length*cur_row+cur_col+1];
			puzzle[side_length*cur_row+cur_col+1] = 0;
			++cur_col;
			break;
		case STEP_LEFT:
			//tmp = puzzle[side_length*cur_row+cur_col];
			puzzle[side_length*cur_row+cur_col] = puzzle[side_length*cur_row+cur_col-1];
			puzzle[side_length*cur_row+cur_col-1] = 0;
			--cur_col;
			break;
		}
			
		
	}
	
}

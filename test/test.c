#include <ctest.h>
#include <stdbool.h>
#include <function.h>
#include <stdlib.h>

CTEST(check_selection, choice_of_complexity) 
{
	//GIVEN
	const int choice1 = 0;
	const int choice2 = 1;
	const int choice3 = 2;
	const int choice4 = 3;
	const int choice5 = 4;
	
	//WHEN
	size_t size1 = check_complexity(choice1);
	size_t size2 = check_complexity(choice2);	
	size_t size3 = check_complexity(choice3);	
	size_t size4 = check_complexity(choice4);
	size_t size5 = check_complexity(choice5);

	//THEN
	const size_t expected1 = 3;
	const size_t expected2 = 4;
	const size_t expected3 = 5;
	const size_t expected4 = 6;
	const size_t expected5 = 0;

	ASSERT_EQUAL(expected1, size1);
	ASSERT_EQUAL(expected2, size2);
	ASSERT_EQUAL(expected3, size3);
	ASSERT_EQUAL(expected4, size4);
	ASSERT_EQUAL(expected5, size5);
}

CTEST(check_for_move, check_win) 
{
	size_t size = 3;

    //GIVEN
    int *puzzle = (int *)malloc(sizeof(int) * size * size);
	init(puzzle, size);

	//WHEN
	size_t win2 = check_win(size, puzzle);

	//THEN
	const size_t expected2 = 1;

	ASSERT_EQUAL_U(expected2, win2);
}
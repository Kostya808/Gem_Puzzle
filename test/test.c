#include <ctest.h>
#include <stdbool.h>
#include <function.h>


CTEST(check_selection, choice_of_complexity) 
{
	//GIVEN
	const int choice1 = 0;
	const int choice2 = 1;
	const int choice3 = 2;
	const int choice4 = 3;
	
	//WHEN
	size_t size1 = check_complexity(choice1);
	size_t size2 = check_complexity(choice2);	
	size_t size3 = check_complexity(choice3);	
	size_t size4 = check_complexity(choice4);	

	//THEN
	const size_t expected1 = 4;
	const size_t expected2 = 5;
	const size_t expected3 = 6;
	const size_t expected4 = 0;

	ASSERT_EQUAL(expected1, size1);
	ASSERT_EQUAL(expected2, size2);
	ASSERT_EQUAL(expected3, size3);
	ASSERT_EQUAL(expected4, size4);
}


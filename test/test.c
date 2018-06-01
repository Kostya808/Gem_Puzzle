#include <ctest.h>
#include <stdbool.h>
#include <function.h>
#include <stdlib.h>
#include <string.h>

CTEST (check_creating, check_init)
{
    size_t size1 = 2;
    size_t size2 = 3;
    size_t size3 = 4;
    size_t size4 = 5;
    size_t size5 = 6;
    size_t size6 = 7;
    size_t arr_size1 = sizeof(int) * size1 * size1;
    size_t arr_size2 = sizeof(int) * size2 * size2;
    size_t arr_size3 = sizeof(int) * size3 * size3;
    size_t arr_size4 = sizeof(int) * size4 * size4;
    size_t arr_size5 = sizeof(int) * size5 * size5;
    size_t arr_size6 = sizeof(int) * size6 * size6;
    int *puzzle1 = malloc(arr_size1);
    int *puzzle2 = malloc(arr_size2);
    int *puzzle3 = malloc(arr_size3);
    int *puzzle4 = malloc(arr_size4);
    int *puzzle5 = malloc(arr_size5);
    int *puzzle6 = malloc(arr_size6);
    int testsite1[] = {1, 2, 3, 0};
    int testsite2[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int testsite3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int testsite4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 0};
    int testsite5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0};
    int testsite6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
      37, 38, 39, 40, 41, 42, 43, 44, 45,46,47,48,0};
    init(puzzle1, size1);
    init(puzzle2, size2);
    init(puzzle3, size3);
    init(puzzle4, size4);
    init(puzzle5, size5);
    init(puzzle6, size6);
    const void *actual_data1 = puzzle1, *control_data1 = testsite1;
    const void *actual_data2 = puzzle2, *control_data2 = testsite2;
    const void *actual_data3 = puzzle3, *control_data3 = testsite3;
    const void *actual_data4 = puzzle4, *control_data4 = testsite4;
    const void *actual_data5 = puzzle5, *control_data5 = testsite5;
    const void *actual_data6 = puzzle6, *control_data6 = testsite6;
    ASSERT_DATA(actual_data1, arr_size1, control_data1, arr_size1);
    ASSERT_DATA(actual_data2, arr_size2, control_data2, arr_size2);
    ASSERT_DATA(actual_data3, arr_size3, control_data3, arr_size3);
    ASSERT_DATA(actual_data4, arr_size4, control_data4, arr_size4);
    ASSERT_DATA(actual_data5, arr_size5, control_data5, arr_size5);
    ASSERT_DATA(actual_data6, arr_size6, control_data6, arr_size6);
}

CTEST (check_creating, check_shuffle)
{
    size_t size1 = 2;
    size_t size2 = 3;
    size_t size3 = 4;
    size_t size4 = 5;
    size_t size5 = 6;
    size_t size6 = 7;
    size_t arr_size1 = sizeof(int) * size1 * size1;
    size_t arr_size2 = sizeof(int) * size2 * size2;
    size_t arr_size3 = sizeof(int) * size3 * size3;
    size_t arr_size4 = sizeof(int) * size4 * size4;
    size_t arr_size5 = sizeof(int) * size5 * size5;
    size_t arr_size6 = sizeof(int) * size6 * size6;
    int *puzzle1 = malloc(arr_size1);
    int *puzzle2 = malloc(arr_size2);
    int *puzzle3 = malloc(arr_size3);
    int *puzzle4 = malloc(arr_size4);
    int *puzzle5 = malloc(arr_size5);
    int *puzzle6 = malloc(arr_size6);
    int testsite1[] = {1, 2, 3, 0};
    int testsite2[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int testsite3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int testsite4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
	  18, 19, 20, 21, 22, 23, 24, 0};
    int testsite5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
	  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0};
    int testsite6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
	  18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
	  37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0};
    init(puzzle1, size1);
    init(puzzle2, size2);
    init(puzzle3, size3);
    init(puzzle4, size4);
    init(puzzle5, size5);
    init(puzzle6, size6);
    shuffle(puzzle1, size1);
    shuffle(puzzle2, size2);
    shuffle(puzzle3, size3);
    shuffle(puzzle4, size4);
    shuffle(puzzle5, size5);
    shuffle(puzzle6, size6);
    int flgeq1 = 0, flgeq2 = 0, flgeq3 = 0, flgeq4 = 0, flgeq5 = 0, flgeq6 = 0;
    size_t flgfind1 = 0, flgfind2 = 0, flgfind3 = 0, flgfind4 = 0, flgfind5 = 0, flgfind6 = 0;
    flgeq1 = memcmp(puzzle1, testsite1, size1 * size1 * sizeof(int));
    flgeq2 = memcmp(puzzle2, testsite2, size2 * size2 * sizeof(int));
    flgeq3 = memcmp(puzzle3, testsite3, size3 * size3 * sizeof(int));
    flgeq4 = memcmp(puzzle4, testsite4, size4 * size4 * sizeof(int));
    flgeq5 = memcmp(puzzle5, testsite5, size5 * size5 * sizeof(int));
    flgeq6 = memcmp(puzzle6, testsite6, size6 * size6 * sizeof(int));
    size_t i, j;
    for (i = 0; i < size1 * size1; ++i) {
        for (j = 0; j < size1 * size1; ++j) {
            if (testsite1[i] == puzzle1[j]) {
                ++flgfind1;
            }
        }
    }
    for (i = 0; i < size2 * size2; ++i) {
        for (j = 0; j < size2 * size2; ++j) {
            if (testsite2[i] == puzzle2[j]) {
                ++flgfind2;
			}
        }
    }
    for (i = 0; i < size3 * size3; ++i) {
        for (j = 0; j < size3 * size3; ++j) {
            if (testsite3[i] == puzzle3[j]) {
                ++flgfind3;
			}
        }
    }
    for (i = 0; i < size4 * size4; ++i) {
        for (j = 0; j < size4 * size4; ++j) {
            if (testsite4[i] == puzzle4[j]) {
                ++flgfind4;
			}
        }
    }
    for (i = 0; i < size5 * size5; ++i) {
        for (j = 0; j < size5 * size5; ++j) {
            if (testsite5[i] == puzzle5[j]) {
                ++flgfind5;
            }
        }
    }
    for (i = 0; i < size6 * size6; ++i) {
        for (j = 0; j < size6 * size6; ++j) {
            if (testsite6[i] == puzzle6[j]) {
                ++flgfind6;
            }
        }
    }
    const size_t unexpected_eq1 = 0;
    const size_t unexpected_eq2 = 0;
    const size_t unexpected_eq3 = 0;
    const size_t unexpected_eq4 = 0;
    const size_t unexpected_eq5 = 0;
    const size_t unexpected_eq6 = 0;
    const size_t expected_find1 = 4;
    const size_t expected_find2 = 9;
    const size_t expected_find3 = 16;
    const size_t expected_find4 = 25;
    const size_t expected_find5 = 36;
    const size_t expected_find6 = 49;
    ASSERT_NOT_EQUAL(unexpected_eq1, flgeq1);
    ASSERT_NOT_EQUAL(unexpected_eq2, flgeq2);
    ASSERT_NOT_EQUAL(unexpected_eq3, flgeq3);
    ASSERT_NOT_EQUAL(unexpected_eq4, flgeq4);
    ASSERT_NOT_EQUAL(unexpected_eq5, flgeq5);
    ASSERT_NOT_EQUAL(unexpected_eq6, flgeq6);
    ASSERT_EQUAL(expected_find1, flgfind1);
    ASSERT_EQUAL(expected_find2, flgfind2);
    ASSERT_EQUAL(expected_find3, flgfind3);
    ASSERT_EQUAL(expected_find4, flgfind4);
    ASSERT_EQUAL(expected_find5, flgfind5);
    ASSERT_EQUAL(expected_find6, flgfind6);
}

CTEST(check_creating, test_for_solvability_check)
{
    int puzzle1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 15};
    bool result1 = check(puzzle1, 4);
    int puzzle2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    bool result2 = check(puzzle2, 4);
    ASSERT_TRUE(result1);
    ASSERT_FALSE(result2);
}

CTEST(check_selection, choice_of_complexity) 
{
    //GIVEN
    const int choice1 = 0;
    const int choice2 = 1;
    const int choice3 = 2;
    const int choice4 = 3;
    const int choice5 = 4;
    const int choice6 = 5;

    //WHEN
    size_t size1 = check_complexity(choice1);
    size_t size2 = check_complexity(choice2);	
    size_t size3 = check_complexity(choice3);	
    size_t size4 = check_complexity(choice4);
    size_t size5 = check_complexity(choice5);
    size_t size6 = check_complexity(choice6);

    //THEN
    const size_t expected1 = 2;
    const size_t expected2 = 3;
    const size_t expected3 = 4;
    const size_t expected4 = 5;
    const size_t expected5 = 6;
    const size_t expected6 = 0;

    ASSERT_EQUAL(expected1, size1);
    ASSERT_EQUAL(expected2, size2);
    ASSERT_EQUAL(expected3, size3);
    ASSERT_EQUAL(expected4, size4);
    ASSERT_EQUAL(expected5, size5);
    ASSERT_EQUAL(expected6, size6);
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

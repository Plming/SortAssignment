#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"

void printMenu()
{
	/*
	 * ****************************************
	 * ****   여러가지 정렬 프로그램 구현   *****
	 * ****                                 *****
	 * ****   1. bubble sort                 *****
	 * ****   2. bubble sort with flag       *****
	 * *****  3. insertion sort               *****
	 * *****  4. selection sort               *****
	 * *****  5. quick sort                  *****
	 * *****  6. merge sort(반복문 사용)     *****
	 * *****  7. heap sort                   *****
	 * *****  8. radix sort                  *****
	 * *****  9. quit                        *****
	 * ****************************************
	*/

	const char menus[][64] =
		{
			"여러가지 정렬 프로그램 구현",
			"",
			"bubble sort",
			"bubble sort with flag",
			"insertion sort",
			"selection sort",
			"quick sort",
			"merge sort(iterative)",
			"heap sort",
			"radix sort",
			"quit"
		};

	int i;

	for (i = 0; i < 45; ++i)
	{
		putchar('*');
	}
	putchar('\n');

	for (i = 0; i < sizeof(menus) / sizeof(menus[0]); ++i)
	{
		if (i < 2)
		{
			printf("***** %-33s *****\n", menus[i]);
		}
		else
		{
			printf("***** %d. %-30s *****\n", i - 1, menus[i]);
		}
	}

	for (i = 0; i < 45; ++i)
	{
		putchar('*');
	}
	putchar('\n');

	printf("select ? ");
}

int* createRandomArrayMalloc(int size)
{
	static const int MAX_VALUE = 100;

	int i;
	int* const arr = malloc(sizeof(int) * size);
	assert(arr != NULL);

	srand(time(NULL));
	for (i = 0; i < size; ++i)
	{
		arr[i] = rand() % MAX_VALUE;
	}

	return arr;
}

void printArray(int arr[], int from, int to)
{
	int i;

	for (i = from; i <= to; ++i)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}


#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define LEN (20)

void printMenu();
element* createRandomArrayMalloc(int size);
void printArray(element arr[], int from, int to);

int main()
{
	element* arr = NULL;

	while (1)
	{
		int command;

		printMenu();
		scanf(" %d", &command);

		switch (command)
		{
		case 1: /* bubble sort */
			arr = createRandomArrayMalloc(LEN);
			printf("before sort: ");
			printArray(arr, 0, LEN - 1);

			bubbleSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 0, LEN - 1);
			free(arr);
			break;

		case 2: /* bubble sort with flag */
			arr = createRandomArrayMalloc(LEN);
			printf("before sort: ");
			printArray(arr, 1, LEN);

			bubbleFlagSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 1, LEN);
			free(arr);
			break;

		case 3: /* insertion sort */
			arr = createRandomArrayMalloc(LEN + 1);
			printf("before sort: ");
			printArray(arr, 1, LEN);

			insertionSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 1, LEN);
			free(arr);
			break;

		case 4: /* selection sort */
			arr = createRandomArrayMalloc(LEN + 1);
			printf("before sort: ");
			printArray(arr, 1, LEN);

			selectionSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 1, LEN);
			free(arr);
			break;

		case 5: /* quick sort */
			arr = createRandomArrayMalloc(LEN);
			printf("before sort: ");
			printArray(arr, 0, LEN - 1);

			quickSort(arr, 0, LEN - 1);

			printf("after  sort: ");
			printArray(arr, 0, LEN - 1);
			free(arr);
			break;

		case 6: /* merge sort */
			arr = createRandomArrayMalloc(LEN + 1);
			printf("before sort: ");
			printArray(arr, 1, LEN);

			mergeSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 1, LEN);
			free(arr);
			break;

		case 7: /* heap sort */
			arr = createRandomArrayMalloc(LEN + 1);
			printf("before sort: ");
			printArray(arr, 1, LEN);

			heapSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 1, LEN);
			free(arr);
			break;

		case 9:
			return 0;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

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

element* createRandomArrayMalloc(int size)
{
	const int THRESHOLD = 100;

	int i;
	element* arr = malloc(sizeof(element) * size);
	assert(arr != NULL);

	srand(time(NULL));
	for (i = 0; i < size; ++i)
	{
		arr[i].key = rand() % THRESHOLD;
	}

	return arr;
}

void printArray(element arr[], int from, int to)
{
	int i;

	for (i = from; i <= to; ++i)
	{
		printf("%2d ", arr[i].key);
	}
	putchar('\n');
}


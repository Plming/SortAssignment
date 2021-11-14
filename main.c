#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "util.h"

#define LEN (20)

int main()
{
	const char* BEFORE = "before sort: ";
	const char* AFTER = "after  sort: ";

	void* list = NULL;
	enum MenuType menuType;

	srand(time(NULL));

	while (1)
	{
		printMenu();
		scanf(" %d", &menuType);

		switch (menuType)
		{
		case BUBBLE_SORT:
			list = createRandomArrayMalloc(LEN);
			printArray(BEFORE, list, 0, LEN - 1);

			bubbleSort(list, LEN);

			printArray(AFTER, list, 0, LEN - 1);
			free(list);
			break;

		case BUBBLE_SORT_WITH_FLAG:
			list = createRandomArrayMalloc(LEN);
			printArray(BEFORE, list, 0, LEN - 1);

			bubbleFlagSort(list, LEN);

			printArray(AFTER, list, 0, LEN - 1);
			free(list);
			break;

		case INSERTION_SORT:
			list = createRandomArrayMalloc(LEN + 1);
			printArray(BEFORE, list, 1, LEN);

			insertionSort(list, LEN);

			printArray(AFTER, list, 1, LEN);
			free(list);
			break;

		case SELECTION_SORT:
			list = createRandomArrayMalloc(LEN);
			printArray(BEFORE, list, 0, LEN - 1);

			selectionSort(list, LEN);

			printArray(AFTER, list, 0, LEN - 1);
			free(list);
			break;

		case QUICK_SORT:
			list = createRandomArrayMalloc(LEN);
			printArray(BEFORE, list, 0, LEN - 1);

			quickSort(list, 0, LEN - 1);

			printArray(AFTER, list, 0, LEN - 1);
			free(list);
			break;

		case ITERATIVE_MERGE_SORT:
			list = createRandomArrayMalloc(LEN);
			printArray(BEFORE, list, 0, LEN - 1);

			mergeSort(list, LEN);

			printArray(AFTER, list, 0, LEN - 1);
			free(list);
			break;

		case HEAP_SORT:
			list = createRandomArrayMalloc(LEN + 1);
			printArray(BEFORE, list, 1, LEN);

			heapSort(list, LEN);

			printArray(AFTER, list, 1, LEN);
			free(list);
			break;

		case RADIX_SORT:
			list = createRandomListMalloc(LEN);
			printList(BEFORE, list);

			list = radixSort(list);

			printList(AFTER, list);
			destructList(list);
			break;

		case QUIT:
			return 0;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

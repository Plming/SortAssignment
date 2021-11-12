#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "util.h"

#define LEN (20)

int main()
{
	int* arr = NULL;
	int link[LEN + 1]; // for radix sort

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
			printArray(arr, 0, LEN - 1);

			bubbleFlagSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 0, LEN - 1);
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
			arr = createRandomArrayMalloc(LEN);
			printf("before sort: ");
			printArray(arr, 0, LEN - 1);

			selectionSort(arr, LEN);

			printf("after  sort: ");
			printArray(arr, 0, LEN - 1);
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

		case 8: /* radix sort */
			arr = createRandomArrayMalloc(LEN);
			printf("before sort: ");
			printArray(arr, 0, LEN - 1);

			int first = radixSort(arr, link, 3, 10, LEN);

			printf("after  sort: ");
			for (int i = first; i != 0; i = link[i])
			{
				printf("%2d ", arr[i]);
			}
			putchar('\n');

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

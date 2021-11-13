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

			list_node* list = NULL;
			list_node* rear = list;
			for (int i = 0; i < 20; ++i)
			{
				rear = appendRandomNumber(&rear);

				if (i == 0)
				{
					list = rear;
				}
			}

			list_node* cursor;
			printf("Before sort: ");
			for (cursor = list; cursor != NULL; cursor = cursor->link)
			{
				int key = cursor->key[0] * 10 + cursor->key[1];
				printf("%2d ", key);
			}
			putchar('\n');

			list = radixSort(list);

			printf("After  sort: ");
			for (cursor = list; cursor != NULL; cursor = cursor->link)
			{
				int key = cursor->key[0] * 10 + cursor->key[1];
				printf("%2d ", key);
			}
			putchar('\n');
			break;

		case 9:
			return 0;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "util.h"

void printMenu()
{
	/*
	 * ****************************************
	 * ****   여러가지 정렬 프로그램 구현    *****
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

	for (i = 0; i < size; ++i)
	{
		arr[i] = rand() % MAX_VALUE;
	}

	return arr;
}

node_t* createRandomListMalloc(int size)
{
	node_t* list = NULL;
	node_t* rear = list;
	int i;

	for (i = 0; i < size; ++i)
	{
		rear = appendRandomNumber(&rear);

		if (i == 0)
		{
			list = rear;
		}
	}

	return list;
}

node_t* appendRandomNumber(node_t** appendAt)
{
	int i;
	node_t* newNode = malloc(sizeof(node_t));
	assert(newNode != NULL);

	for (i = 0; i < MAX_DIGIT; ++i)
	{
		newNode->key[i] = rand() % RADIX_SIZE;
	}
	newNode->link = NULL;

	if (*appendAt == NULL)
	{
		*appendAt = newNode;
	}
	else
	{
		(*appendAt)->link = newNode;
	}

	return newNode;
}

void destructList(node_t* list)
{
	while (list != NULL)
	{
		node_t* next = list->link;
		free(list);
		list = next;
	}
}

void printArray(const char* prefix, int arr[], int from, int to)
{
	int i;

	printf("%s", prefix);

	for (i = from; i <= to; ++i)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}

void printList(const char* prefix, node_t* list)
{
	printf("%s", prefix);
	for (; list != NULL; list = list->link)
	{
		int key = 0;
		int i;
		for (i = 0; i < MAX_DIGIT; ++i)
		{
			key *= RADIX_SIZE;
			key += list->key[i];
		}

		printf("%2d ", key);
	}
	putchar('\n');
}

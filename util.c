#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "util.h"

void print_menu()
{
	static const char menus[][64] = {
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

	size_t i;

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
			printf("***** %lu. %-30s *****\n", i - 1, menus[i]);
		}
	}

	for (i = 0; i < 45; ++i)
	{
		putchar('*');
	}
	putchar('\n');

	printf("select ? ");
}

int* create_numbers_array_malloc(int length)
{
    const int MAX_VALUE = 100;

	size_t i;
	int* const arr = malloc(sizeof(int) * length);

	assert(arr != NULL);

	for (i = 0; i < length; ++i)
	{
		arr[i] = rand() % MAX_VALUE;
	}

	return arr;
}

node_t* create_numbers_list_malloc(int length)
{
	node_t* list = NULL;
	node_t* rear = list;
	size_t i;

	for (i = 0; i < length; ++i)
	{
		rear = append_random_number(&rear);

		if (i == 0)
		{
			list = rear;
		}
	}

	return list;
}

node_t* append_random_number(node_t** append_at)
{
	int i;
	node_t* new_node = malloc(sizeof(node_t));
	assert(new_node != NULL);

	for (i = 0; i < MAX_DIGIT; ++i)
	{
        new_node->key[i] = rand() % RADIX_SIZE;
	}
    new_node->link = NULL;

	if (*append_at == NULL)
	{
		*append_at = new_node;
	}
	else
	{
		(*append_at)->link = new_node;
	}

	return new_node;
}

void destroy_list(node_t* list)
{
	while (list != NULL)
	{
		node_t* next = list->link;
		free(list);
		list = next;
	}
}

void print_array(const char* prefix, int arr[], int from, int to)
{
	size_t i;

	printf("%s", prefix);

	for (i = from; i <= to; ++i)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}

void print_list(const char* prefix, node_t* list)
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

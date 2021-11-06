#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define LEN (20)

void print_menu();
void randomize_array(int arr[], int length);
void print_array(int arr[], int length);

int main()
{
	int arr[LEN];

	while (1)
	{
		print_menu();
		int command;
		scanf(" %d", &command);

		randomize_array(arr, LEN);

		switch (command)
		{
		case 1:
			printf("before sort: ");
			print_array(arr, LEN);

			printf("after  sort: ");
			bubble_sort(arr, LEN);
			print_array(arr, LEN);
			break;
		case 4:
			printf("before sort: ");
			print_array(arr, LEN);

			printf("after  sort: ");
			selection_sort(arr, LEN);
			print_array(arr, LEN);
			break;
		case 9:
			return 0;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

void print_menu()
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

	const char menus[][32] =
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

void randomize_array(int arr[], int length)
{
	int i;

	srand(time(NULL));
	for (i = 0; i < length; ++i)
	{
		arr[i] = rand() % 100;
	}
}

void print_array(int arr[], int length)
{
	int i;

	for (i = 0; i < length; ++i)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}


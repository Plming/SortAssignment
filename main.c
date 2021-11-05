#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

void show_menu();
void randomize_array(int arr[], int length);
void print_array(int arr[], int length);

int main()
{
	int arr[20];
	const int length = sizeof(arr) / sizeof(arr[0]);

	while (1)
	{
		show_menu();
		int command;
		scanf(" %d", &command);

		randomize_array(arr, length);
		print_array(arr, length);
		putchar('\n');

		switch (command)
		{
		case 1:
			printf("before sort: ");
			print_array(arr, length);

			printf("after  sort: ");
			bubble_sort(arr, length);
			print_array(arr, length);
			break;
		case 9:
			return 0;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
}

void show_menu()
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

	for (int i = 0; i < sizeof(menus) / sizeof(menus[0]); ++i)
	{
		printf("***** %d. %-30s *****\n", i + 1, menus[i]);
	}

	printf("select ? ");
}

void randomize_array(int arr[], int length)
{
	srand(time(NULL));
	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand() % 100;
	}
}

void print_array(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%2d ", arr[i]);
	}
	putchar('\n');
}


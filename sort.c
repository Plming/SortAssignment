#include "sort.h"

void bubble_sort(int arr[], int length)
{
	int i;
	int j;

	for (i = length - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selection_sort(int arr[], int length)
{
	int i;
	int j;

	for (i = 0; i < length - 1; i++)
	{
		int min_index = i;
		for (j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}

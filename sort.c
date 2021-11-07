#include "sort.h"

#define SWAP(a, b, temp) (temp) = (a); (a) = (b); (b) = (temp)

void bubble_sort(element arr[], int length)
{
	int i;
	int j;

	for (i = length - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (arr[j + 1].key < arr[j].key)
			{
				element temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void insert(element e, element a[], int i)
{
	// pre condition: length of a is more than i + 2
	// post condition: a[1:i+1] sorted

	a[0] = e;
	while (e.key < a[i].key)
	{
		a[i + 1] = a[i];
		--i;
	}
	a[i + 1] = e;
}

void insertion_sort(element a[], int n)
{
	// post-condition: a[1:n] sorted

	int j;
	for (j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

void selection_sort(element arr[], int length)
{
	int i;
	int j;

	for (i = 0; i < length - 1; i++)
	{
		int min_index = i;
		for (j = i + 1; j < length; ++j)
		{
			if (arr[j].key < arr[min_index].key)
			{
				min_index = j;
			}
		}

		element temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}

void quick_sort(element a[], int left, int right)
{
	int pivot;
	int i, j;
	element temp;

	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left].key;
		do
		{
			do
			{
				++i;
			} while (a[i].key < pivot);

			do
			{
				--j;
			} while (a[j].key > pivot);

			if (i < j)
			{
				SWAP(a[i], a[j], temp);
			}
		} while (i < j);
		SWAP(a[left], a[j], temp);
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}
#include <stdlib.h>

#include "sort.h"

#define SWAP(a, b, temp) (temp) = (a); (a) = (b); (b) = (temp)

void bubbleSort(element arr[], int length)
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

void insertionSort(element a[], int n)
{
	// post-condition: a[1:n] sorted

	int j;
	for (j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j - 1);
	}
}

void selectionSort(element arr[], int length)
{
	int i;
	int j;

	for (i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < length; ++j)
		{
			if (arr[j].key < arr[minIndex].key)
			{
				minIndex = j;
			}
		}

		element temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void quickSort(element a[], int left, int right)
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
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

void merge(element initList[], element mergedList[], int i, int m, int n)
{
	// pre-condition: initList[i:m], initList[m+1,n] are sorted list
	// post-condition: mergedList[i:n] is sorted list that merged them into

	int j = m + 1;
	int k = i;
	int t;

	while (i <= m && j <= n)
	{
		if (initList[i].key <= initList[j].key)
		{
			mergedList[k++] = initList[i++];
		}
		else
		{
			mergedList[k++] = initList[j++];
		}
	}

	if (i > m) // first list done earlier
	{
		for (t = j; t <= n; ++t)
		{
			mergedList[t] = initList[t];
		}
	}
	else // second list done earlier
	{
		for (t = i; t <= m; ++t)
		{
			mergedList[k + t - i] = initList[t];
		}
	}
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;

	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
	{
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	}

	if ((i + s - 1) < n)
	{
		merge(initList, mergedList, i, i + s - 1, n);
	}
	else
	{
		for (j = i; j <= n; ++j)
		{
			mergedList[j] = initList[j];
		}
	}
}

void mergeSort(element a[], int n)
{
	int s = 1;
	element *extra = malloc(sizeof(element) * (n + 1));

	while (s < n)
	{
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}

	free(extra);
}
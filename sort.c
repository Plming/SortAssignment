#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define SWAP(a, b, temp) (temp) = (a); (a) = (b); (b) = (temp)

void bubbleSort(int arr[], int length)
{
	int i, j;
	int temp;

	for (i = length - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				SWAP(arr[j], arr[j + 1], temp);
			}
		}
	}
}

void bubbleFlagSort(int list[], int length)
{
	// represents that list[flag : length - 1] is sorted
	int flag = length - 1;

	int i;
	int temp;

	while (flag > 0)
	{
		int lastSwappedIndex = 0;

		for (i = 0; i < flag; ++i)
		{
			if (list[i + 1] < list[i])
			{
				SWAP(list[i], list[i + 1], temp);
				lastSwappedIndex = i;
			}
		}

		// after lastSwappedIndex, list must be sorted
		flag = lastSwappedIndex;
	}
}

void insertionSort(int a[], int n)
{
	/* perform a insertion sort on the list */
	int i, j;
	int temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i]; /* save a[i] */
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
		{
			a[j + 1] = a[j]; /* shift operation */
		}
		a[j + 1] = temp;
	}
}

void selectionSort(int arr[], int length)
{
	int i, j;
	int temp;

	for (i = 0; i < length - 1; i++)
	{
		int minIndex = i;

		for (j = i + 1; j < length; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		SWAP(arr[i], arr[minIndex], temp);
	}
}

void quickSort(int a[], int left, int right)
{
	int pivot;
	int i, j;
	int temp;

	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left];
		do
		{
			do
			{
				++i;
			} while (a[i] < pivot);

			do
			{
				--j;
			} while (a[j] > pivot);

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

void merge(const int initList[], int mergedList[], int i, int m, int n)
{
	// pre-condition: initList[i : m], initList[m + 1 : n] are sorted list
	// post-condition: mergedList[i : n] is sorted list that merged them into

	int j = m + 1;
	int k = i;
	int t;

	while (i <= m && j <= n)
	{
		if (initList[i] <= initList[j])
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

void mergePass(int initList[], int mergedList[], int n, int s)
{
	int i, j;

	for (i = 0; i <= n - 2 * s; i += 2 * s)
	{
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
	}

	if (i + s < n)
	{
		merge(initList, mergedList, i, i + s - 1, n - 1);
	}
	else
	{
		for (j = i; j < n; ++j)
		{
			mergedList[j] = initList[j];
		}
	}
}

void mergeSort(int arr[], int n)
{
	// post-condition: arr[0 : n - 1] is sorted

	// cluster size
	int size = 1;

	int *extra = malloc(sizeof(int) * (n));
	assert(extra != NULL);

	while (size < n)
	{
		mergePass(arr, extra, n, size);
		size *= 2;
		mergePass(extra, arr, n, size);
		size *= 2;
	}

	free(extra);
}

void adjust(int a[], int root, int n)
{
	int temp = a[root];
	const int rootKey = a[root];

	int child = 2 * root;
	while (child <= n)
	{
		if (child < n && a[child] < a[child + 1])
		{
			++child;
		}

		if (rootKey > a[child])
		{
			break;
		}
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}

	a[child / 2] = temp;
}

void heapSort(int a[], int n)
{
	int i;
	int temp;

	for (i = n / 2; i > 0; --i)
	{
		adjust(a, i, n);
	}

	for (i = n - 1; i > 0; --i)
	{
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}

node_t *radixSort(node_t *ptr)
{
	// return the head node of sorted linked list

	node_t *front[RADIX_SIZE];
	node_t *rear[RADIX_SIZE];

	int i, j;

	for (i = MAX_DIGIT - 1; i >= 0; --i)
	{
		// initialize bins
		for (j = 0; j < RADIX_SIZE; ++j)
		{
			front[j] = rear[j] = NULL;
		}

		while (ptr)
		{
			const int digit = ptr->key[i];

			if (!front[digit])
			{
				front[digit] = ptr;
			}
			else
			{
				rear[digit]->link = ptr;
			}

			rear[digit] = ptr;
			ptr = ptr->link;
		}

		ptr = NULL;
		for (j = RADIX_SIZE - 1; j >= 0; --j)
		{
			if (front[j])
			{
				rear[j]->link = ptr;
				ptr = front[j];
			}
		}
	}

	return ptr;
}
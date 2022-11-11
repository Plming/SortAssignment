#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define SWAP(a, b, temp) (temp) = (a); (a) = (b); (b) = (temp)

void bubble_sort(int arr[], int length)
{
	size_t i;
	size_t j;
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

void bubble_sort_with_flag(int list[], int length)
{
	// represents that list[flag : length - 1] is sorted
	int flag = length - 1;

	int i;
	int temp;

	while (flag > 0)
	{
		int last_swapped_index = 0;

		for (i = 0; i < flag; ++i)
		{
			if (list[i + 1] < list[i])
			{
				SWAP(list[i], list[i + 1], temp);
				last_swapped_index = i;
			}
		}

		// after last_swapped_index, list must be sorted
		flag = last_swapped_index;
	}
}

void insertion_sort(int a[], int n)
{
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

void selection_sort(int arr[], int length)
{
	int i, j;
	int temp;

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

		SWAP(arr[i], arr[min_index], temp);
	}
}

void quick_sort(int a[], int left, int right)
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
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
}

void merge(const int init_list[], int merged_list[], int i, int m, int n)
{
	// pre-condition: init_list[i : m], init_list[m + 1 : n] are sorted list
	// post-condition: merged_list[i : n] is sorted list that merged them into

	int j = m + 1;
	int k = i;
	int t;

	while (i <= m && j <= n)
	{
		if (init_list[i] <= init_list[j])
		{
            merged_list[k++] = init_list[i++];
		}
		else
		{
            merged_list[k++] = init_list[j++];
		}
	}

	if (i > m) // first list done earlier
	{
		for (t = j; t <= n; ++t)
		{
            merged_list[t] = init_list[t];
		}
	}
	else // second list done earlier
	{
		for (t = i; t <= m; ++t)
		{
            merged_list[k + t - i] = init_list[t];
		}
	}
}

void merge_pass(int init_list[], int merged_list[], int n, int s)
{
	int i, j;

	for (i = 0; i <= n - 2 * s; i += 2 * s)
	{
		merge(init_list, merged_list, i, i + s - 1, i + 2 * s - 1);
	}

	if (i + s < n)
	{
		merge(init_list, merged_list, i, i + s - 1, n - 1);
	}
	else
	{
		for (j = i; j < n; ++j)
		{
            merged_list[j] = init_list[j];
		}
	}
}

void merge_sort(int arr[], int n)
{
	// post-condition: arr[0 : n - 1] is sorted

	// cluster size
	int size = 1;

	int *extra = malloc(sizeof(int) * (n));
	assert(extra != NULL);

	while (size < n)
	{
        merge_pass(arr, extra, n, size);
		size *= 2;
        merge_pass(extra, arr, n, size);
		size *= 2;
	}

	free(extra);
}

void adjust(int a[], int root, int n)
{
	int temp = a[root];
	const int root_key = a[root];

	int child = 2 * root;
	while (child <= n)
	{
		if (child < n && a[child] < a[child + 1])
		{
			++child;
		}

		if (root_key > a[child])
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

void heap_sort(int a[], int n)
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

node_t *radix_sort(node_t *ptr)
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
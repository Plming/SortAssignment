#ifndef _SORT_H_
#define _SORT_H_

typedef struct
{
	int key;
} element;

void bubble_sort(element arr[], int length);

void insert(element e, element a[], int i);
void insertion_sort(element a[], int n);

void selection_sort(element arr[], int length);

void quick_sort(element a[], int left, int right);

#endif //_SORT_H_

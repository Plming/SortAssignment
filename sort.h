#ifndef _SORT_H_
#define _SORT_H_

typedef struct
{
	int key;
} element;

void bubbleSort(element arr[], int length);

void bubbleFlagSort(element list[], int length);

void insert(element e, element a[], int i);
void insertionSort(element a[], int n);

void selectionSort(element arr[], int length);

void quickSort(element a[], int left, int right);

void merge(element initList[], element mergedList[], int i, int m, int n);
void mergePass(element initList[], element mergedList[], int n, int s);
void mergeSort(element a[], int n);

void adjust(element a[], int root, int n);
void heapSort(element a[], int n);

int digit(element n, int pos, int radix);
int radixSort(element a[], int link[], int d, int r, int n);

#endif //_SORT_H_

#ifndef _SORT_H_
#define _SORT_H_

typedef struct
{
	int key;
} element;

void bubbleSort(int arr[], int length);

void bubbleFlagSort(int list[], int length);

void insert(int e, int a[], int i);
void insertionSort(int a[], int n);

void selectionSort(int arr[], int length);

void quickSort(int a[], int left, int right);

void merge(int initList[], int mergedList[], int i, int m, int n);
void mergePass(int initList[], int mergedList[], int n, int s);
void mergeSort(int a[], int n);

void adjust(int a[], int root, int n);
void heapSort(int a[], int n);

int digit(int n, int pos, int radix);
int radixSort(int a[], int link[], int d, int r, int n);

#endif //_SORT_H_

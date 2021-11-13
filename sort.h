#ifndef _SORT_H_
#define _SORT_H_

#define MAX_DIGIT (2)
#define RADIX_SIZE (10)

typedef struct list_node* list_pointer;

typedef struct list_node
{
	int key[MAX_DIGIT];
	list_pointer link;
};

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

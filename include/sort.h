#ifndef SORTASSIGNMENT_SORT_H
#define SORTASSIGNMENT_SORT_H

#define MAX_DIGIT (2)
#define RADIX_SIZE (10)

typedef struct node
{
	int key[MAX_DIGIT];
	struct node* link;
} node_t;

void bubble_sort(int arr[], int length);

void bubble_sort_with_flag(int list[], int length);

void insertion_sort(int a[], int n);

void selection_sort(int arr[], int length);

void quick_sort(int a[], int left, int right);

void merge(const int init_list[], int merged_list[], int i, int m, int n);
void merge_pass(int init_list[], int merged_list[], int n, int s);
void merge_sort(int arr[], int n);

void adjust(int a[], int root, int n);
void heap_sort(int a[], int n);

node_t* radix_sort(node_t* ptr);

#endif //SORTASSIGNMENT_SORT_H

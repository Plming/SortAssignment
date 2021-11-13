#ifndef _UTIL_H_
#define _UTIL_H_

enum MenuType
{
	BUBBLE_SORT = 1,
	BUBBLE_SORT_WITH_FLAG,
	INSERTION_SORT,
	SELECTION_SORT,
	QUICK_SORT,
	ITERATIVE_MERGE_SORT,
	HEAP_SORT,
	RADIX_SORT,
	QUIT
};

void printMenu();
int* createRandomArrayMalloc(int size);
list_node* createRandomListMalloc(int size);
void destructList(list_node* list);
void printArray(const char* prefix, int arr[], int from, int to);
void printList(const char* prefix, list_node* list);

#endif //_UTIL_H_

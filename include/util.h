#ifndef SORTASSIGNMENT_UTIL_H
#define SORTASSIGNMENT_UTIL_H

typedef enum {
    BUBBLE_SORT = 1,
    BUBBLE_SORT_WITH_FLAG,
    INSERTION_SORT,
    SELECTION_SORT,
    QUICK_SORT,
    ITERATIVE_MERGE_SORT,
    HEAP_SORT,
    RADIX_SORT,
    QUIT
} menu_t;

void print_menu();

int *create_numbers_array_malloc(int length);

node_t *create_numbers_list_malloc(int length);

node_t *append_random_number(node_t **append_at);

void destroy_list(node_t *list);

void print_array(const char *prefix, int arr[], int from, int to);

void print_list(const char *prefix, node_t *list);

#endif //SORTASSIGNMENT_UTIL_H

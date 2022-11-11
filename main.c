#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "util.h"

#define LEN (16)

int main(void) {
    const char *BEFORE = "before sort: ";
    const char *AFTER = "after  sort: ";

    void *list = NULL;
    menu_t menu;

    while (1) {
        clock_t start;

        print_menu();
        scanf(" %d", &menu);

        start = clock();
        switch (menu) {
            case BUBBLE_SORT:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                bubble_sort(list, LEN);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case BUBBLE_SORT_WITH_FLAG:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                bubble_sort_with_flag(list, LEN);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case INSERTION_SORT:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                insertion_sort(list, LEN);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case SELECTION_SORT:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                selection_sort(list, LEN);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case QUICK_SORT:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                quick_sort(list, 0, LEN - 1);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case ITERATIVE_MERGE_SORT:
                list = create_numbers_array_malloc(LEN);
                print_array(BEFORE, list, 0, LEN - 1);

                merge_sort(list, LEN);

                print_array(AFTER, list, 0, LEN - 1);
                free(list);
                break;

            case HEAP_SORT:
                list = create_numbers_array_malloc(LEN + 1);
                print_array(BEFORE, list, 1, LEN);

                heap_sort(list, LEN);

                print_array(AFTER, list, 1, LEN);
                free(list);
                break;

            case RADIX_SORT:
                list = create_numbers_list_malloc(LEN);
                print_list(BEFORE, list);

                list = radix_sort(list);

                print_list(AFTER, list);
                destroy_list(list);
                break;

            case QUIT:
                return 0;

            default:
                printf("잘못된 입력입니다.\n");
                break;
        }

        printf("Elapsed time: %f seconds\n", (double) (clock() - start) / CLOCKS_PER_SEC);
    }
}
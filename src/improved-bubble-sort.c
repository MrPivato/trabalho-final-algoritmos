#include "improved-bubble-sort.h"
#include "sort-state.h"

bool improved_bubble_sort_iter(union SortingAlgorithmState *state)
{

    int *list = state->improved_bubble_sort_state.list;
    size_t list_size = state->improved_bubble_sort_state.list_size;

    int temp = 0;
    for (int i = 0; i < list_size; i++)
    {
        bool sorted = true;
        for (int j = 0; j < list_size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                sorted = false;
            }
        }

        if (sorted)
            return true;
    }

    return false;
};

union SortingAlgorithmState improved_bubble_sort_init(int list[],
                                                      size_t list_size)
{
    struct ImprovedBubbleSortState state = {.list = list,
                                            .list_size = list_size,
                                            .going_right = true};
    union SortingAlgorithmState ret = {.improved_bubble_sort_state = state};
    return ret;
}

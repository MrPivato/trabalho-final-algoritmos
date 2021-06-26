#ifndef improved_bubble_sort_state_h_INCLUDED
#define improved_bubble_sort_state_h_INCLUDED

#include <stdbool.h>
#include <stddef.h>
struct ImprovedBubbleSortState
{
    int *list;
    size_t list_size;
    bool going_right;
};

#endif // improved_bubble_sort_state_h_INCLUDED

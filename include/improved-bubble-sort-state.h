#ifndef improved_bubble_sort_state_h_INCLUDED
#define improved_bubble_sort_state_h_INCLUDED

#include <stdbool.h>
#include <stddef.h>
struct ImprovedBubbleSortState
{
    int *list;
    size_t list_size;
    int index1;
    int index2;
    bool sorted;
    enum
    {
        Go_right,
        Start_comparing,
        Comparing,
        Done,
    } action;
};

#endif // improved_bubble_sort_state_h_INCLUDED

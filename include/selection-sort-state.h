#ifndef selection_sort_state_h_INCLUDED
#define selection_sort_state_h_INCLUDED

#include <stddef.h>

struct SelectionSortState
{
    int *list;
    size_t list_size;
    size_t i, j, min;
    enum
    {
        SS_Scrolling,
        SS_Searching,
        SS_Done,
    } action;
};

#endif // selection_sort_state_h_INCLUDED

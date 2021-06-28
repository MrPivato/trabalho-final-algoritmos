#ifndef quick_sort_state_h_INCLUDED
#define quick_sort_state_h_INCLUDED

#include <stddef.h>

struct QuickSortState
{
    int *list;
    size_t list_size;
    int pivot;
    int i, j;
    int first, last;
    // int index2;
    // bool sorted;
    struct QuickSortState* left;
    struct QuickSortState* right;
    enum
    {
        QS_Working,
        QS_DoingLeft,
        QS_DoingRight,
        QS_WaitLeft,
        QS_WaitRight,
        QS_Done,
    } action;
};

#endif // quick_sort_state_h_INCLUDED

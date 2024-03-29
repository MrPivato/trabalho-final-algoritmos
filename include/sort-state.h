#ifndef sort_state_h_INCLUDED
#define sort_state_h_INCLUDED

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "improved-bubble-sort-state.h"
#include "merge-sort-state.h"
#include "quick-sort-state.h"
#include "selection-sort-state.h"

typedef union SortingAlgorithmState {
    struct MergeSortListSection *merge_sort_state;
    struct ImprovedBubbleSortState improved_bubble_sort_state;
    struct QuickSortState *quick_sort_state;
    struct SelectionSortState selection_sort_state;
} SortingAlgorithmState;

struct SortingAlgorithm
{
    char *funcname;
    union SortingAlgorithmState (*init)(int *, size_t);
    bool (*iter)(union SortingAlgorithmState *);
    void (*draw)(WINDOW *, int *, size_t, union SortingAlgorithmState *);
};

void default_draw(WINDOW *, int *list, size_t list_size,
                  union SortingAlgorithmState *);

#endif // sort-state_h_INCLUDED

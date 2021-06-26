#ifndef sort_state_h_INCLUDED
#define sort_state_h_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

// #include "improved-bubble-sort.h"
#include "merge-sort-state.h"
// #include "quick-sort.h"
// #include "selection-sort.h"

typedef union SortingAlgorithmState {
    struct MergeSortListSection *merge_sort_state;
    // struct ImprovedBubbleSortState improved_bubble_sort_state;
} SortingAlgorithmState;

struct SortingAlgorithm
{
    char *funcname;
    union SortingAlgorithmState (*init)(int *, size_t);
    bool (*iter)(union SortingAlgorithmState *);
};

#endif // sort-state_h_INCLUDED

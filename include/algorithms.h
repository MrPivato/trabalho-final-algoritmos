#ifndef algorithms_h_INCLUDED
#define algorithms_h_INCLUDED

#include "sort-state.h"

#include "improved-bubble-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
// #include "selection-sort.h"

static struct SortingAlgorithm ALGORITHMS[] = {
    {"Improved Bubble Sort", improved_bubble_sort_init, improved_bubble_sort_iter},
    // {"Selection Sort", selection_sort, NULL},
    {"Quick Sort", quick_sort_init, quick_sort_iter},
    {"Merge Sort", merge_sort_init, merge_sort_iter},
};

static int ALGORITHMS_count = (sizeof(ALGORITHMS) / sizeof(ALGORITHMS[0]));

#endif

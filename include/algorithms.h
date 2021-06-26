#ifndef algorithms_h_INCLUDED
#define algorithms_h_INCLUDED

#include "improved-bubble-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "selection-sort.h"

struct SortingAlgorithm
{
    char *funcname;
    void (*func)(int *, size_t);
};

static struct SortingAlgorithm ALGORITHMS[] = {
    {"Improved Bubble Sort", improved_bubble_sort},
    {"Selection Sort", selection_sort},
    {"Quick Sort", quick_sort},
    {"Merge Sort", merge_sort},
};

static int ALGORITHMS_count = (sizeof(ALGORITHMS) / sizeof(ALGORITHMS[0]));

#endif // algorithms_h_INCLUDED

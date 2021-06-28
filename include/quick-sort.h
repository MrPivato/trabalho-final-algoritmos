#ifndef quick_sort_h_INCLUDED
#define quick_sort_h_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

#include "quick-sort-state.h"

union SortingAlgorithmState quick_sort_init(int list[], size_t list_size);

bool quick_sort_iter(union SortingAlgorithmState *state_union);

#endif // quick_sort_h_INCLUDED

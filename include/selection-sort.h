#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "selection-sort-state.h"

union SortingAlgorithmState selection_sort_init(int list[], size_t list_size);

bool selection_sort_iter(union SortingAlgorithmState *state_union);

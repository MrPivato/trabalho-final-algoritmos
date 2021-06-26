#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "improved-bubble-sort-state.h"

union SortingAlgorithmState improved_bubble_sort_init(int list[], size_t list_size);

bool improved_bubble_sort_iter(union SortingAlgorithmState *state);

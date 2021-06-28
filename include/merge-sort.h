#ifndef merge_sort_h_INCLUDED
#define merge_sort_h_INCLUDED

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>

#include "merge-sort-state.h"

/*
 * Merge sort
 * Divide a lista em segmentos
 * Ordena os dois segmentos usando merge-sort
 * Enquanto os segmentos tiverem elementos
 * Adiciona o menor elemento primeiro elemento
 */
union SortingAlgorithmState merge_sort_init(int *list, size_t list_size);

bool merge_sort_iter(union SortingAlgorithmState *state);

void merge_sort_draw(WINDOW *, int *list, size_t list_size,
                     union SortingAlgorithmState *);

#endif // merge_sort_h_INCLUDED

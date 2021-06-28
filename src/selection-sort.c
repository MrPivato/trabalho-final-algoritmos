#include "selection-sort.h"
#include "sort-state.h"

void ss_level1(struct SelectionSortState *state)
{
    state->min = state->i;
    state->j = state->i + 1;
    state->action = SS_Searching;

    if (state->i >= state->list_size - 1)
        state->action = SS_Done;
}
void ss_level2(struct SelectionSortState *state)
{

    if (state->list[state->j] < state->list[state->min])
        state->min = state->j;

    state->j++;

    if (state->j == state->list_size)
    {
        int temp = state->list[state->i];
        state->list[state->i] = state->list[state->min];
        state->list[state->min] = temp;

        state->i++;
        state->action = SS_Scrolling;
    }
}

bool selection_sort_iter(union SortingAlgorithmState *state_union)
{
    struct SelectionSortState *state = &state_union->selection_sort_state;

    switch (state->action)
    {
    case SS_Scrolling:
        ss_level1(state);
        break;
    case SS_Searching:
        ss_level2(state);
        break;
    case SS_Done:
        return true;
        break;
    }
    return false;
};

union SortingAlgorithmState selection_sort_init(int list[], size_t list_size)
{
    struct SelectionSortState tmp = {
        .list = list,
        .list_size = list_size,
        .i = 0,
        .action = SS_Scrolling,
    };
    union SortingAlgorithmState ret = {.selection_sort_state = tmp};
    return ret;
}

#include "improved-bubble-sort.h"
#include "sort-state.h"

void go_right(struct ImprovedBubbleSortState *state)
{
    if (state->index1 < state->list_size)
    {
        state->index2 = 0;
        state->action = Start_comparing;
    }
    else
        state->action = Done;
}

void start_comparing(struct ImprovedBubbleSortState *state)
{
    state->sorted = true;
    state->action = Comparing;
}

void compare(struct ImprovedBubbleSortState *state)
{
    int *list = state->list;
    size_t list_size = state->list_size;

    if (state->index2 >= state->list_size - state->index1 - 1)
    {
        state->index1++;
        state->action = Go_right;
        return;
    }

    int temp = 0;
    if (list[state->index2] > list[state->index2 + 1])
    {
        temp = list[state->index2];
        list[state->index2] = list[state->index2 + 1];
        list[state->index2 + 1] = temp;
        state->sorted = false;
    }

    state->index2++;
}


bool improved_bubble_sort_iter(union SortingAlgorithmState *state_union)
{
    struct ImprovedBubbleSortState *state =
        &state_union->improved_bubble_sort_state;

    switch (state->action)
    {
    case Go_right:
        go_right(state);
        break;
    case Start_comparing:
        start_comparing(state);
        break;
    case Comparing:
        compare(state);
        break;
    case Done:
        return true;
        break;
    }
    return false;
};

union SortingAlgorithmState improved_bubble_sort_init(int list[],
                                                      size_t list_size)
{
    struct ImprovedBubbleSortState state = {
        .list = list,
        .list_size = list_size,
        .index1 = 0,
        .index2 = 0,
        .sorted = false,
        .action = Go_right,
    };
    union SortingAlgorithmState ret = {.improved_bubble_sort_state = state};
    return ret;
}

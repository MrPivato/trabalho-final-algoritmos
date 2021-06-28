#include "quick-sort.h"
#include "sort-state.h"

struct QuickSortState *qs_new(int list[], int first, int last)
{
    struct QuickSortState *ret = malloc(sizeof(struct QuickSortState));

    ret->action = QS_Working;
    ret->list = list;
    ret->first = first;
    ret->last = last;

    ret->pivot = first;
    ret->i = first;
    ret->j = last;

    return ret;
}

void qs_work(struct QuickSortState *state)
{
    int *list = state->list;
    int pivot = state->pivot;
    int i = state->i;
    int j = state->j;
    int first = state->first;
    int last = state->last;

    if (first >= last)
    {
        state->action = QS_Done;
        return;
    }

    if (state->i < state->j)
        state->action = QS_DoingLeft;
    else
    {
        int temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;

        state->left = qs_new(list, first, j - 1);
        state->right = qs_new(list, j + 1, last);
        state->action = QS_WaitLeft;
    }
}

void qs_do_left(struct QuickSortState *state)
{
    int *list = state->list;

    if (list[state->i] <= list[state->pivot] && state->i < state->last)
        state->i++;
    else
        state->action = QS_DoingRight;
}

void qs_do_right(struct QuickSortState *state)
{
    int *list = state->list;

    if (list[state->j] > list[state->pivot])
    {
        state->j--;
        return;
    }

    if (state->i < state->j)
    {
        int temp = list[state->i];
        list[state->i] = list[state->j];
        list[state->j] = temp;
    }
    state->action = QS_Working;
}

bool quick_sort_iter(union SortingAlgorithmState *state_union)
{
    struct QuickSortState *state = state_union->quick_sort_state;
    union SortingAlgorithmState tmp;

    switch (state->action)
    {
    case QS_Working:
        qs_work(state);
        break;
    case QS_DoingLeft:
        qs_do_left(state);
        break;
    case QS_DoingRight:
        qs_do_right(state);
        break;
    case QS_WaitLeft:
        tmp.quick_sort_state = state->left;
        if (quick_sort_iter(&tmp))
            state->action = QS_WaitRight;
        break;
    case QS_WaitRight:
        tmp.quick_sort_state = state->right;
        if (quick_sort_iter(&tmp))
            state->action = QS_Done;
        break;
    case QS_Done:
        return true;
        break;
    }
    return false;
};

union SortingAlgorithmState quick_sort_init(int list[], size_t list_size)
{
    union SortingAlgorithmState ret = {.quick_sort_state =
                                           qs_new(list, 0, (int)list_size - 1)};
    return ret;
}

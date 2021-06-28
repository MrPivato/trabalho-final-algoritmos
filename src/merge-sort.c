#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <stdarg.h>

#include "merge-sort.h"
#include "sort-state.h"

#include "util.h"

#define ARROWCHAR '🡱'

struct MergeSortListSection *ListSection_new(struct MergeSortListSection *up,
                                             int *data, int data_size)
{
    struct MergeSortListSection *section =
        malloc(sizeof(struct MergeSortListSection));
    section->data = data;
    section->data_size = data_size;
    section->data_capacity = data_size;
    section->tmp_sorted = NULL;

    section->up = up;
    section->left = NULL;
    section->right = NULL;

    section->state = MergeSort_Spliting;
    return section;
}

void MergeSort_split(struct MergeSortListSection *section)
{
    int *data = section->data;
    int data_size = section->data_size;

    if (section->data_size < 2)
    {
        section->state = MergeSort_Done;
        return;
    }

    section->left = ListSection_new(section, data, data_size / 2);
    int free_space = section->data_size - section->left->data_size;
    section->right = ListSection_new(section, &data[data_size / 2], free_space);

    section->state = MergeSort_Waiting;
}

void MergeSort_merge(struct MergeSortListSection *section)
{

    struct MergeSortListSection *left = section->left;
    struct MergeSortListSection *right = section->right;

    if (left->data_size == 0 && right->data_size == 0)
    {
        free(section->left);
        free(section->right);
        for (int i = 0; i < section->data_size; i++)
            section->data[i] = section->tmp_sorted[i];
        if (section->tmp_sorted != NULL)
            free(section->tmp_sorted);
        section->state = MergeSort_Done;
        return;
    }

    if (section->tmp_sorted == NULL)
        section->tmp_sorted = malloc(sizeof(int) * section->data_size);

    struct MergeSortListSection *next_entry_src;
    int dst_index = section->data_size - (left->data_size + right->data_size);

    bool both = left->data_size && left->data_size;
    if ((both && *left->data < *right->data) || right->data_size == 0)
        next_entry_src = left;
    else
        next_entry_src = right;

    section->tmp_sorted[dst_index] = next_entry_src->data[0];
    next_entry_src->data++;
    next_entry_src->data_size--;
}

bool merge_sort_iter(union SortingAlgorithmState *state)
{
    struct MergeSortListSection *section = state->merge_sort_state;

    union SortingAlgorithmState sub_state;
    switch (section->state)
    {
    case MergeSort_Spliting:
        MergeSort_split(section);
        break;
    case MergeSort_Merging:
        MergeSort_merge(section);
        break;
    case MergeSort_Waiting:
        if (section->right->state != MergeSort_Done)
        {
            sub_state.merge_sort_state = section->right;
            merge_sort_iter(&sub_state);
        }
        else if (section->left->state != MergeSort_Done)
        {
            sub_state.merge_sort_state = section->left;
            merge_sort_iter(&sub_state);
        }
        else
            section->state = MergeSort_Merging;
        break;
    case MergeSort_Done:
        return true;
        break;
    }

    return false;
};

union SortingAlgorithmState merge_sort_init(int *list, size_t size)
{
    union SortingAlgorithmState state = {.merge_sort_state =
                                             ListSection_new(NULL, list, size)};

    return state;
}

void merge_sort_draw_segment(WINDOW *win, int y, int x, int maxn,
                             struct MergeSortListSection *section)
{

    int mx_idx;

    wmove(win, y, x);
    mvwprintw(win, y, x - 1, "|");
    for (int i = 0; i < section->data_size; i++)
    {
        wprintw(win, "%*d ", maxn, section->data[i]);
        if (i == section->data_size - 1)
            mvwprintw(win, y, x - 1, "|");
    }
    if (section->left != NULL && section->left->data_size)
    {
        y++;
        merge_sort_draw_segment(win, y, x, maxn, section->left);
        if (section->right != NULL && section->right->data_size)
        {
            x += (maxn + 1) * section->left->data_size;
            merge_sort_draw_segment(win, y, x, maxn, section->right);
            x -= (maxn + 1) * section->left->data_size;
        }
        y--;
    }

    // switch (section->state)
    // {
    // case MergeSort_Spliting:

    // case MergeSort_Merging:
    //     mx_idx = section->data_size -
    //              (section->left->data_size + section->right->data_size) - 1;

    //     wmove(win, y, x);
    //     for (int i = 0; i < mx_idx; i++)
    //         wprintw(win, "%*d ", maxn, section->tmp_sorted[i]);

    //     if (section->right->state == MergeSort_Done)
    //     {
    //         y++;
    //         merge_sort_draw_segment(win, y, x, maxn, section->left);
    //         y--;
    //         x += maxn * section->left->data_size;
    //         merge_sort_draw_segment(win, y, x, maxn, section->right);
    //         x -= maxn * section->left->data_size;
    //     }
    //     else
    //     {
    //         y++;
    //         x += maxn * section->left->data_size;
    //         merge_sort_draw_segment(win, y, x, maxn, section->right);
    //         x -= maxn * section->left->data_size;
    //         y--;
    //     }
    //     break;
    // case MergeSort_Waiting:
    //     if (section->right->state == MergeSort_Done)
    //     {
    //         wmove(win, y, x);
    //         for (int i = 0; i < section->left->data_size; i++)
    //             wprintw(win, "%*d ", maxn, section->left->data[i]);
    //         y++;
    //         x += maxn * section->left->data_size;
    //         merge_sort_draw_segment(win, y, x, maxn, section->right);
    //         x -= maxn * section->left->data_size;
    //         y--;
    //     }
    //     else
    //     {
    //         y++;
    //         merge_sort_draw_segment(win, y, x, maxn, section->left);
    //         x += maxn * section->left->data_size;
    //         merge_sort_draw_segment(win, y, x, maxn, section->right);
    //         x -= maxn * section->left->data_size;
    //         y--;
    //     }
    //     break;
    // case MergeSort_Done:
    //     break;
    // }
}

void merge_sort_draw(WINDOW *win, int *list, size_t list_size,
                     union SortingAlgorithmState *state_union)
{
    int maxn = 0;
    for (int i = 0; i < list_size; i++)

        if (maxn < list[i])

            maxn = list[i];

    int mult10;
    for (mult10 = 0; maxn >= 10; mult10++)
        maxn /= 10;

    struct MergeSortListSection *state = state_union->merge_sort_state;

    int y, x;
    getyx(win, y, x);

    merge_sort_draw_segment(win, y, x, mult10 + 1, state);
}

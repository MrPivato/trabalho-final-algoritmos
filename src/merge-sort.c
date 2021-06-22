#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

#include "util.h"

#define DEBUG false

#define ARROWCHAR '🡱'

typedef enum State
{
    MergeSort_Spliting,
    MergeSort_Merging,
    MergeSort_Waiting,
    MergeSort_Done,
} State;

typedef struct ListSection
{
    int *data;
    int data_size;

    int *tmp_sorted;

    State state;

    struct ListSection *left;
    struct ListSection *right;

    struct ListSection *up;
} ListSection;

ListSection *ListSection_new(ListSection *up, int *data, int data_size)
{
    ListSection *section = malloc(sizeof(ListSection));
    section->data = data;
    section->data_size = data_size;
    section->tmp_sorted = NULL;

    section->up = up;

    section->state = MergeSort_Spliting;
    return section;
}

void MergeSort_split(ListSection *section)
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

void MergeSort_merge(ListSection *section)
{

    ListSection *left = section->left;
    ListSection *right = section->right;

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

    ListSection *next_entry_src;
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

void MergeSort_iter(ListSection *section)
{
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
            MergeSort_iter(section->right);
        else if (section->left->state != MergeSort_Done)
            MergeSort_iter(section->left);
        else
            section->state = MergeSort_Merging;
        break;
    case MergeSort_Done:
        break;
    }
};

void merge_sort(int *list, int size)
{
    ListSection *root = ListSection_new(NULL, list, size);
    while (root->state != MergeSort_Done)
    {
        MergeSort_iter(root);
    }
    free(root);
}

#ifndef merge_sort_state_h_INCLUDED
#define merge_sort_state_h_INCLUDED

struct MergeSortListSection
{
    int *data;
    int data_size;

    int *tmp_sorted;

    enum
    {
        MergeSort_Spliting,
        MergeSort_Merging,
        MergeSort_Waiting,
        MergeSort_Done,
    } state;

    struct MergeSortListSection *left;
    struct MergeSortListSection *right;

    struct MergeSortListSection *up;
};

#endif // merge_sort_state_h_INCLUDED

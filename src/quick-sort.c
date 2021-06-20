#include "quick-sort.h"

void quick_sort(int list[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (list[i] <= list[pivot] && i < last)
                i++;

            while (list[j] > list[pivot])
                j--;

            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[pivot];
        list[pivot] = list[j];
        list[j] = temp;
        
        quick_sort(list, first, j - 1);
        quick_sort(list, j + 1, last);
    }
}
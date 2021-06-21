#include "selection-sort.h"

void selection_sort(int list[], size_t list_size)
{
    int temp = 0;
    for (int i = 0; i < list_size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < list_size; j++)
            if (list[j] < list[min_index])
                min_index = j;
                
        temp = list[i];
        list[i] = list[min_index];
        list[min_index] = temp;
    }
}
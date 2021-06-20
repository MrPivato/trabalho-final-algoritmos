#include "improved-bubble-sort.h"

void improved_bubble_sort(int list[], size_t list_size) {
    int temp = 0;
    for (int i = 0; i < list_size; i++)
    {
        bool sorted = true;
        for (int j = 0; j < list_size - i-1; j++)
        {
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1]=temp;
                sorted = false;
            }
            
        }
        
        if (sorted)
            return;
    }
};
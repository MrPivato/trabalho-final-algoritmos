#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "util.h"
#include "improved-bubble-sort.h"

int main()
{
    // criação da seed pros números randomicos
    time_t t;
    srand((unsigned)time(&t));

    printf("Improved Bubble Sort\n");
    int size = 7;
    int bubble_list[size];
    for (int i = 0; i < size; i++)
    {
        bubble_list[i] = generate_rand(12, 50);
    }
    iprint_arr(bubble_list, size, "Antes");
    improved_bubble_sort(bubble_list, size);
    iprint_arr(bubble_list, size, "Depois");

    return 0;
}

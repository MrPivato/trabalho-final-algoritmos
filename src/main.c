#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "util.h"
#include "improved-bubble-sort.h"
#include "quick-sort.h"
#include "selection-sort.h"

int main()
{
    // criação da seed pros números randomicos
    time_t t;
    srand(time(0));

    printf("Improved Bubble Sort\n");
    int size_bubble = 7;
    int bubble_list[size_bubble];
    for (int i = 0; i < size_bubble; i++)
    {
        bubble_list[i] = generate_rand(12, 50);
    }
    iprint_arr(bubble_list, size_bubble, "Antes");
    improved_bubble_sort(bubble_list, size_bubble);
    iprint_arr(bubble_list, size_bubble, "Depois");

    printf("Selection Sort\n");
    int size_selection = 10;
    int selection_list[size_selection];
    for (int i = 0; i < size_selection; i++)
    {
        selection_list[i] = generate_rand(50, 200);
    }
    iprint_arr(selection_list, size_selection, "Antes");
    selection_sort(selection_list, size_selection);
    iprint_arr(selection_list, size_selection, "Depois");

    printf("Quick Sort\n");
    int size_quick = 7;
    int quick_list[size_quick];
    for (int i = 0; i < size_quick; i++)
    {
        quick_list[i] = generate_rand(10, 70);
    }
    iprint_arr(quick_list, size_quick, "Antes");
    quick_sort(quick_list, 0, size_quick-1);
    iprint_arr(quick_list, size_quick, "Depois");

    return 0;
}

#include "improved-bubble-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "selection-sort.h"
#include "util.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void run_sorter(char *name, void (*alg)(int[], size_t))
{
    printf("%s\n", name);

    size_t size = 10;
    int list[size];
    for (int i = 0; i < size; i++)
        list[i] = generate_rand(0, 100);

    iprint_arr(list, size, "Antes ");
    alg(list, size);
    iprint_arr(list, size, "Depois");
}

int main()
{
    // criação da seed pros números randomicos
    time_t t;
    srand(time(0));

    run_sorter("Improved Bubble Sort", improved_bubble_sort);
    run_sorter("Selection Sort", selection_sort);
    run_sorter("Quick Sort", quick_sort);
    run_sorter("Merge Sort", merge_sort);

    return 0;
}

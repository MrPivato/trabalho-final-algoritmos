#include "improved-bubble-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "run-sorter.h"
#include "selection-sort.h"
#include "util.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

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

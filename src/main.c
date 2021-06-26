#include "run-sorter.h"
#include "algorithms.h"
#include "util.h"
#include <ncurses.h>

int main()
{
    // criação da seed pros números randomicos
    time_t t;
    srand(time(0));

    for (int i = 0; i < ALGORITHMS_count; i++)
    {
        struct SortingAlgorithm alg = ALGORITHMS[i];

        run_sorter(alg.funcname, alg.func);
    }

    return 0;
}

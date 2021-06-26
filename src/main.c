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
        struct SortingAlgorithm algo = ALGORITHMS[i];

        run_sorter(algo);
    }

    return 0;
}

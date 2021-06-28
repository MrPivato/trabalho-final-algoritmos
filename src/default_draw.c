#include "sort-state.h"
#include <ncurses.h>

void default_draw(WINDOW *win, int *list, size_t list_size,
                  union SortingAlgorithmState *state)
{
    for (int i = 0; i < list_size; i++)
        wprintw(win, "%d, ", list[i]);
}

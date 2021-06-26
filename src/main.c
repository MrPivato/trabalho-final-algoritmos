#include "algorithms.h"
#include "run-sorter.h"
#include "util.h"
#include "window.h"

#include <ncurses.h>

int main()
{
    // criação da seed pros números randomicos
    time_t t;
    srand(time(0));

    struct MenuState menu = Menu_start();

    Menu_menu(&menu);

    Menu_end();

    return 0;
}

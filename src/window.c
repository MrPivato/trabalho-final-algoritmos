#include "window.h"
#include "algorithms.h"
#include "run-sorter.h"
#include <ncurses.h>

enum Menu_Colors
{
    DEFAULT = 1,
    CURSOR = 2,
};

struct MenuState Menu_start()
{
    initscr();
    noecho();
    curs_set(false);
    keypad(stdscr, true);
    start_color();
    use_default_colors();

    init_pair(DEFAULT, COLOR_WHITE, COLOR_BLACK);
    init_pair(CURSOR, COLOR_BLACK, COLOR_WHITE);

    timeout(500);

    struct MenuState ret;
    ret.selected = 0;
    ret.window = stdscr;
    return ret;
}

void Menu_end()
{
    endwin();
}

void Menu_draw(struct MenuState *menu)
{
    wclear(menu->window);

    int x, y;
    getyx(menu->window, x, y);

    mvwprintw(menu->window, 0, 0, "Escolha um algoritmo: %d", menu->selected);
    for (int i = 0; i < ALGORITHMS_count; i++)
    {
        if (i == menu->selected)
            wattron(menu->window, COLOR_PAIR(CURSOR));
        mvwprintw(menu->window, i + 2, 0, "%s", ALGORITHMS[i].funcname);
        wattroff(menu->window, COLOR_PAIR(CURSOR));
    }
}

enum MenuAction Menu_handle_input()
{
    int ch = getch();

    switch (ch)
    {
    case KEY_UP:
        return MenuAction_prev;
    case KEY_DOWN:
        return MenuAction_next;
    case '\n':
        return MenuAction_run;
    case 'q':
        return MenuAction_quit;
    default:
        break;
    }

    return MenuAction_none;
}

void Menu_menu(struct MenuState *menu)
{
    bool loop = true;
    struct SortingAlgorithm alg;

    while (loop)
    {
        Menu_draw(menu);

        switch (Menu_handle_input())
        {
        case MenuAction_quit:
            loop = false;
            break;
        case MenuAction_next:
            if (menu->selected < ALGORITHMS_count - 1)
                menu->selected += 1;
            break;
        case MenuAction_prev:
            if (menu->selected > 0)
                menu->selected -= 1;
            break;
        case MenuAction_run:
            alg = ALGORITHMS[menu->selected];
            run_sorter(alg);
            break;
        case MenuAction_none:
            break;
        }
    };
}

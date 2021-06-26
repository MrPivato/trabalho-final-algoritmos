
#include "window.h"
#include "algorithms.h"
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

    // timeout(300);

    struct MenuState ret;
    ret.selected = 0;
    return ret;
}

void Menu_end()
{
    endwin();
}

void Menu_draw(struct MenuState *menu)
{
    clear();

    int x, y;
    int i = 0;
    getyx(stdscr, x, y);

    mvprintw(0, 0, "Escolha um algoritmo: %d", menu->selected);
    for (i = 0; i < ALGORITHMS_count; i++)
    {
        if (i == menu->selected)
            attron(COLOR_PAIR(CURSOR));
        mvprintw(i + 2, 0, "%s", ALGORITHMS[i].funcname);
        attroff(COLOR_PAIR(CURSOR));
    }

    // move(i + 1, 0);
}

enum MenuAction Menu_handle_input()
{
    int ch = getch();

    enum MenuAction ret = MenuAction_none;
    switch (ch)
    {
    case KEY_UP:
        ret = MenuAction_prev;
        break;
    case KEY_DOWN:
        ret = MenuAction_next;
        break;
    case KEY_ENTER:
        break;
    case 'q':
        ret = MenuAction_quit;
        break;
    default:
        break;
    }

    return ret;
}

void Menu_menu(struct MenuState *menu)
{
    bool loop = true;
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
        case MenuAction_none:
            break;
        }
    };
}

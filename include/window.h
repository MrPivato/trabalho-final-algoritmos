#ifndef window_h_INCLUDED
#define window_h_INCLUDED

#include <ncurses.h>

enum MenuAction
{
    MenuAction_none,
    MenuAction_quit,
    MenuAction_next,
    MenuAction_prev,
    MenuAction_run,
};

struct MenuState
{
    int selected;
    WINDOW *window;
};

struct MenuState Menu_start();

void Menu_end();

void Menu_menu();

enum MenuAction Menu_handle_inputt();

#endif // window_h_INCLUDED

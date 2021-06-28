#include "run-sorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "algorithms.h"
#include "util.h"

void run_sorter(struct SortingAlgorithm algo)
{
    // wclear(stdscr);

    int h, w;
    getmaxyx(stdscr, h, w);
    WINDOW *win = newwin(h - 6, w - 12, 3, 6);

    size_t tamanho = 5;

    int *lista = malloc(sizeof(int) * tamanho);
    for (int i = 0; i <= tamanho; i++)
        lista[i] = generate_rand(0, tamanho * 10);

    // iprint_arr(lista, tamanho, "Antes ");
    time_t inicio = clock();
    union SortingAlgorithmState state = algo.init(lista, tamanho);
    while (!algo.iter(&state))
    {
        wclear(win);
        box(win, 0, 0);

        mvwprintw(win, 0, 2, "|%s|", algo.funcname);
        mvwprintw(win, 1, 1, "Here: ");

        if (algo.draw == NULL)
            default_draw(win, lista, tamanho, &state);
        else
            algo.draw(win, lista, tamanho, &state);

        wrefresh(win);
        timeout(100);
        getch();
    }
    time_t fim = clock();

    // iprint_arr(lista, tamanho, "Depois");

    assert_sorted(lista, tamanho);

    time_t tempo_decorrido_ms = (fim - inicio) * 1000 / CLOCKS_PER_SEC;

    char *tempo_decorrido_unidade = "ms";
    long int tempo_decorrido_escala = 1;
    if (tempo_decorrido_ms > 1000)
    {
        tempo_decorrido_unidade = "s";
        tempo_decorrido_escala = 1000;
    }

    int winh, winw;
    getmaxyx(win, winh, winw);
    mvwprintw(win, winh - 2, 1, "%s levou %li%s com %ld itens", algo.funcname,
              tempo_decorrido_ms / tempo_decorrido_escala,
              tempo_decorrido_unidade, tamanho);
    wrefresh(win);
    timeout(-1);
    getch();
}

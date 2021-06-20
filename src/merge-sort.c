#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

#include "util.h"

#define DEBUG false

void merge(int *inicio1, size_t tamanho1, int *inicio2, size_t tamanho2) {
    indent();
    if (tamanho1 == 0 && tamanho2 == 0)
        return;

    if (DEBUG) {
        iprintf("Mesclando:\n");
        iprint_arr(inicio1, tamanho1, "Lado esquerdo");
        iprint_arr(inicio2, tamanho2, "Lado direito");
    }
    int *ponteiro1 = inicio1;
    int *ponteiro2 = inicio2;

    int sorted_size = tamanho1 + tamanho2;
    int *sorted = malloc(sizeof(int) * sorted_size);
    size_t sortedi = 0;

    while (tamanho1 || tamanho2) {
        bool ambos = tamanho1 && tamanho2;
        if (DEBUG)
            iprintf("Comparando: %d, %d\n", *ponteiro1, *ponteiro2);

        bool first = (ambos && *ponteiro1 < *ponteiro2) || (!ambos && tamanho1);

        if (first) {
            if (DEBUG)
                iprintf("Adicionando ao resultado: %d\n", *ponteiro1);
            sorted[sortedi++] = *ponteiro1++;
            tamanho1--;
        } else {
            if (DEBUG)
                iprintf("Adicionando ao resultado: %d\n", *ponteiro2);
            sorted[sortedi++] = *ponteiro2++;
            tamanho2--;
        }
    }

    for (int i = 0; i < sorted_size; i++)
        inicio1[i] = sorted[i];

    if (DEBUG)
        iprint_arr(inicio1, sorted_size, "Result");

    deindent();
}

void merge_sort(int list[], size_t list_size) {
    // Condição de parada da recursão.
    if (list_size < 2)
        return;

    indent();

    if (DEBUG)
        iprint_arr(list, list_size, "Ordenando");

    // Separar a list em duas
    int *l1 = list;
    size_t l1s = list_size / 2;
    int *l2 = &list[list_size / 2];
    size_t l2s = list_size / 2 + (list_size % 2 == 1);

    if (DEBUG) {
        iprint_arr(l1, l1s, "Lado esquerdo");
        iprint_arr(l2, l2s, "Lado direito ");
    }
    merge_sort(l1, l1s);
    merge_sort(l2, l2s);

    merge(l1, l1s, l2, l2s);

    if (DEBUG)
        iprint_arr(list, list_size, "resultado merge-sort");

    deindent();

    assert_sorted(list, list_size);
};

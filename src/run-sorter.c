#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "run-sorter.h"

#include "util.h"

void run_sorter(char *nome_funcao, void (*funcao)(int[], size_t))
{
    size_t tamanho = 40000;

    int lista[tamanho];
    for (int i = 0; i < tamanho; i++)
        lista[i] = generate_rand(0, tamanho * 10);

    iprint_arr(lista, tamanho, "Antes ");
    time_t inicio = clock();
    funcao(lista, tamanho);
    time_t fim = clock();
    iprint_arr(lista, tamanho, "Depois");

    time_t tempo_decorrido_ms = (fim - inicio) * 1000 / CLOCKS_PER_SEC;

    char *tempo_decorrido_unidade = "ms";
    long int tempo_decorrido_escala = 1;
    if (tempo_decorrido_ms > 1000)
    {
        tempo_decorrido_unidade = "s";
        tempo_decorrido_escala = 1000;
    }

    printf("Tempo de Execução %s, com %ld itens: %li%s\n\n", nome_funcao, tamanho,
           tempo_decorrido_ms / tempo_decorrido_escala,
           tempo_decorrido_unidade);
}

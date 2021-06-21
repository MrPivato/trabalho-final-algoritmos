#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"

int indent_width = 0;

void iprintf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    for (int i = 0; i < indent_width; i++)
        printf("    ");
    vprintf(format, args);

    va_end(args);
}

void iprint_arr(int arr[], size_t size, char *msg)
{

    iprintf("%s: {", msg);
    for (int i = 0; i < size; i++)
    {
        int limit = 5;

        bool inrange = (i < limit || size - i < limit);
        bool ellipsis = (size > 2 * limit && (i == size - i || i + 1 == size - i));
        char *comma = (i < size - 1) ? ", " : "";

        if (inrange)
            printf("%6d%s", arr[i], comma);
        else if (ellipsis)
            printf("... ");
    }
    printf("}\n");
}

void indent()
{
    indent_width++;
}

void deindent()
{
    indent_width--;
}

void assert_sorted(int list[], size_t size)
{
    if (size < 2)
        return;
    for (int i = 1; i < size; i++)
        if (list[i - 1] > list[i])
        {
            iprint_arr(list, size, "Failed to sort arrray");
            exit(1);
        }
}

int generate_rand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
};

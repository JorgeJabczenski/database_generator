#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char **argv)
{
    srand(time(NULL));

    int cpf[11];
    int soma;

    /* Gera os 9 primeiros números do cpf */
    for (int i = 0; i < 9; i++) cpf[i] = rand() % 10;

    /* Calcula o 1° dígito verificador */
    soma = 0;
    for (int i = 0; i < 9; i++) soma += cpf[i] * (10-i);
    ((soma % 11) < 2) ? (cpf[9] = 0) : (cpf[9] = (11-(soma % 11)));

    /* Calcula o 2º dígito verificador*/
    soma = 0;
    for (int i = 0; i < 10; i++) soma += cpf[i] * (11-i);
    ((soma % 11) < 2) ? (cpf[10] = 0) : (cpf[10] = (11-(soma % 11)));

    for (int i = 0; i < 11; i++) printf("%d", cpf[i]);
    printf("\n");

    return EXIT_SUCCESS;
}

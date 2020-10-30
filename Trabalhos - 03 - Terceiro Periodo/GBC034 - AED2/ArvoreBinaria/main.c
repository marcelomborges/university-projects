/*
Programa: Arvore Binaria
Aluno: Marcelo Mendonca Borges
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main()
{
    int controle;
    ARVORE_BINARIA arv1, arv2, arv3, arv4;

    arv1 = cria_arvore_binaria(1,NULL,NULL);
    arv2 = cria_arvore_binaria(2,NULL,NULL);
    arv3 = cria_arvore_binaria(3,arv1,arv2);
    arv4 = cria_arvore_binaria(4,NULL,arv3);

    imprime_arvore_binaria(arv4);

    controle = busca_arvore_binaria(arv4, 3);
    printf("Resultado da busca por 3: %d\n\n", controle);

    controle = busca_arvore_binaria(arv4, 5);
    printf("Resultado da busca por 5: %d\n\n", controle);

    controle = remove_folha_arvore_binaria(&arv4, 1);
    printf("Resultado da remocao: %d\n\n", controle);

    imprime_arvore_binaria(arv4);

    libera_arvore_binaria(&arv4);

    return 0;
}


/*
Programa: Dicionario e Algoritmos de Busca
Aluno: Marcelo Mendonca Borges
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmos_de_busca.h"

int main()
{
    /*Declaracao de variaveis*/
    int i, controle;
    REGISTRO *elemento;
    ARQUIVO *arquivo;
    /*-----------------------*/

    elemento = (REGISTRO*) malloc(sizeof(REGISTRO));
    if(elemento == NULL)
    {
        printf("ERRO-00\n");
        return 0;
    }

    arquivo = inicia_arquivo();

    for(i = 0; i < 10; i++)
    {
        elemento->chave = i;
        strcpy(elemento->nome, "RAMDOM_NAME");
        controle = insere_registro(arquivo, *elemento);
        if(controle == 0)
        {
            printf("ERRO-01\n");
        }
    }

    imprime_arquivo(arquivo);

    controle = remove_registro(arquivo, 7);
    if(controle == 0)
    {
        printf("ERRO-02\n");
    }

    imprime_arquivo(arquivo);

    return 0;
}


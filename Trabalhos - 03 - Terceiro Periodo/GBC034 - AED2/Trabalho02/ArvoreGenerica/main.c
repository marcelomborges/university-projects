/*
Programa: Arvore Generica
Aluno: Marcelo Mendonca Borges
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_generica.h"
#include "fila_arvore_generica.h"

int main()
{
    /*Declaracao de Variaveis----------------------------------------------------------------------*/
    int i, controle, operacao, operando;
    ARVORE_GENERICA arvore[7];
    ARVORE_GENERICA arvore_teste = cria_arvore_generica(99);
    ARVORE_GENERICA arvore_teste2 = cria_arvore_generica(100);
    /*---------------------------------------------------------------------------------------------*/

    /*Criacao da Arvore----------------------------------------------------------------------------*/
    for(i = 0; i < 7; i++)
    {
        arvore[i] = cria_arvore_generica(i);
    }

    insere_generica(arvore[3],arvore[6]);
    insere_generica(arvore[2],arvore[5]);
    insere_generica(arvore[2],arvore[4]);
    insere_generica(arvore[0],arvore[3]);
    insere_generica(arvore[0],arvore[2]);
    insere_generica(arvore[0],arvore[1]);
    insere_generica(arvore[1], arvore_teste);
    insere_generica(arvore_teste, arvore_teste2);
    /*-------------------------------------------------------------------------------------------*/
    do
    {
        imprime_cabecalho();
        printf("Arvore Generica Utilizada:----------------------------------------------\n\n");
        exibe_arvore_generica(arvore[0]);
        printf("\n\n------------------------------------------------------------------------\n\n");

        printf("Digite o numero da operacao voce deseja realizar: ");
        scanf("%d", &operacao);
        printf("\n");

        if(operacao == 1)
        {
            imprime_preorder(arvore[0]);
        }
        else if(operacao == 2)
        {
            imprime_postorder(arvore[0]);
        }
        else if(operacao == 3)
        {
            imprime_percorre_nivel(arvore[0]);
        }
        else if(operacao == 4)
        {
            controle = nro_derivacao(arvore[0]);
            printf("-> Numero de Nos de Derivacao: %d\n\n", controle);
        }
        else if(operacao == 5)
        {
            controle = grau_arv(arvore[0]);
            printf("-> Grau da Arvore: %d\n\n", controle);
        }
        else if(operacao == 6)
        {
            do
            {
                printf("Digite o Grau (Grau >= 0): ");
                scanf("%d", &operando);
                printf("\n");
            }
            while(operando < 0);

            controle = qtde_nos_generica(arvore[0], operando);
            printf("-> Quantidade de Nos de Grau %d: %d\n\n", operando, controle);
        }
        else if(operacao == 7)
        {
            do
            {
                printf("Digite a chave do elemento: ");
                scanf("%d", &operando);
                printf("\n");
            }
            while(operando < 0);

            controle = altura_no(arvore[0], operando);
            if(controle == (-1))
            {
                printf("-> Chave inserida nao corresponde a nenhum No.\n\n");
            }
            else
            {
                printf("-> Altura do No de Chave %d: %d\n\n", operando, controle);
            }
        }
        else if(operacao == 8)
        {
            printf("-> Finalizando Programa.\n\n");
        }
        else
        {
            printf("-> Erro: Operacao Invalida.\n\n");
        }
        system("PAUSE");
        system("CLS");
    }
    while(operacao != 8);

    printf("\n-> Pressione qualquer tecla para fechar.\n");

    libera_arvore_generica(&arvore[0]);

    return 0;
}

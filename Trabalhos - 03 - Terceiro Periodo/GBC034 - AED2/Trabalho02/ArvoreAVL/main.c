/*
Programa: Arvore AVL
Aluno: Marcelo Mendonca Borges
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore_avl.h"

int main()
{

    /*Declaracao de Variaveis----------------------------------------------------------------------*/
    int i, verificador, controle, opcao, operacao, operando1, operando2;
    int trafego, capacidade, identificador;
    char localizacao[100];
    REGISTRO elemento[8];
    REGISTRO elemento_usuario;
    REGISTRO *retorno_menor_trafego;
    ARVORE_AVL arvore, arvore1, arvore2;
    /*---------------------------------------------------------------------------------------------*/

    /*Criacao das Arvores--------------------------------------------------------------------------*/
    for(i = 0; i < 8; i++)
    {
        elemento[i].capacidade = i;
        elemento[i].identificador = i;
        elemento[i].trafego = i;
        strcpy(elemento[i].localizacao, "Irrelevante");
    }

    arvore = cria_arvore_avl();
    arvore1 = cria_arvore_avl();
    arvore2 = cria_arvore_avl();

    insere_AVL(&arvore1, elemento[0], &verificador);
    insere_AVL(&arvore1, elemento[1], &verificador);
    insere_AVL(&arvore1, elemento[2], &verificador);
    insere_AVL(&arvore1, elemento[3], &verificador);
    insere_AVL(&arvore1, elemento[4], &verificador);
    insere_AVL(&arvore1, elemento[5], &verificador);
    insere_AVL(&arvore1, elemento[6], &verificador);
    insere_AVL(&arvore1, elemento[7], &verificador);

    insere_AVL(&arvore2, elemento[0], &verificador);
    insere_AVL(&arvore2, elemento[1], &verificador);
    insere_AVL(&arvore2, elemento[2], &verificador);
    insere_AVL(&arvore2, elemento[3], &verificador);
    insere_AVL(&arvore2, elemento[4], &verificador);
    insere_AVL(&arvore2, elemento[5], &verificador);
    insere_AVL(&arvore2, elemento[6], &verificador);
    insere_AVL(&arvore2, elemento[7], &verificador);
    /*---------------------------------------------------------------------------------------------*/

    do
    {
        printf("#------------------------------- Parte 3 - Arvore AVL ------------------------------------#\n");
        printf("|-----------------------------------------------------------------------------------------|\n");
        printf("|Opcoes Disponiveis:----------------------------------------------------------------------|\n");
        printf("|1 - Utilizar Arvores Prontas                                                             |\n");
        printf("|2 - Criar uma Arvore                                                                     |\n");
        printf("#-----------------------------------------------------------------------------------------#\n\n");

        printf("Digite o numero da sua opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if((opcao != 1)&&(opcao != 2))
        {
            printf("-> Erro: Opcao Invalida.\n\n");
        }

        system("PAUSE");
        system("CLS");
    }
    while((opcao <= 0)||(opcao > 2));

    if(opcao == 1)
    {
        do
        {
            imprime_cabecalho_1();
            printf("Arvores AVL Utilizadas:------------------------------------\n\n");
            exibe_arvore_avl(arvore1);
            printf("   (Utilizada Para Realizar Todas as Funcoes)\n\n");
            exibe_arvore_avl(arvore2);
            printf("   (Utilizada Somente Na Funcao de Verificar a Igualdade Entre Arvores)\n\n");
            printf("------------------------------------------------------------------------\n\n");

            printf("Digite o numero da operacao voce deseja realizar: ");
            scanf("%d", &operacao);
            printf("\n");

            if(operacao == 1)
            {
                retorno_menor_trafego = menor_trafego(arvore1);
                printf("-> Ponto da Rede Com Menor Trafego:\n");
                if(retorno_menor_trafego != NULL)
                {
                    printf("Trafego: %d\n", retorno_menor_trafego->trafego);
                    printf("Capacidade: %d\n", retorno_menor_trafego->capacidade);
                    printf("Identificador: %d\n", retorno_menor_trafego->identificador);
                    printf("Localizacao: %s\n\n", retorno_menor_trafego->localizacao);
                }
            }
            else if(operacao == 2)
            {
                controle = qtde_ocioso(arvore1);
                printf("-> Quantidade de Pontos Ociosos: %d\n\n", controle);
            }
            else if(operacao == 3)
            {
                controle = nro_folha(arvore1);
                printf("-> Numero de Nos Folhas: %d\n\n", controle);
            }
            else if(operacao == 4)
            {
                controle = cheia(arvore1);
                if(controle == 1)
                {
                    printf("-> Arvore Eh Cheia.\n\n");
                }
                else
                {
                    printf("-> Arvore Nao Eh Cheia.\n\n");
                }
            }
            else if(operacao == 5)
            {
                do
                {
                    printf("Digite o Campo Chave do No (0 <= Chave  <= 7): ");
                    scanf("%d", &operando1);
                    printf("\n");
                }
                while((operando1 < 0)||(operando1 > 7));

                controle = nivel_no(arvore1, elemento[operando1]);
                printf("-> Nivel do No: %d\n\n", controle);

            }
            else if(operacao == 6)
            {
                controle = iguais(arvore1,arvore2);
                if(controle == 1)
                {
                    printf("-> As Arvores sao Iguais.\n\n");
                }
                else
                {
                    printf("-> As Arvore sao Diferente.\n\n");
                }
            }
            else if(operacao == 7)
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
        while(operacao != 7);
    }
    else
    {
        do
        {
            imprime_cabecalho_2();
            printf("Arvore AVL Atual:-------------------------------------------------------\n\n");
            exibe_arvore_avl(arvore);
            printf("\n\n");
            printf("------------------------------------------------------------------------\n\n");

            printf("Digite o numero da operacao voce deseja realizar: ");
            scanf("%d", &operacao);
            printf("\n");

            if(operacao == 1)
            {
                do
                {
                    printf("Digite o Trafego do Ponto(Trafego >= 0): ");
                    scanf("%d", &trafego);
                    printf("\n");
                }
                while(trafego < 0);

                do
                {
                    printf("Digite a Capacidade do Ponto(Capacidade >= 0): ");
                    scanf("%d", &capacidade);
                    printf("\n");
                }
                while(capacidade < 0);

                do
                {
                    printf("Digite o Identificador do Ponto(Identificador >= 0): ");
                    scanf("%d", &identificador);
                    printf("\n");
                }
                while(identificador < 0);

                printf("Digite a Localizacao do Ponto (ate 100 caracteres): ");
                fflush(stdin);
                gets(localizacao);
                fflush(stdin);
                printf("\n");

                elemento_usuario.trafego = trafego;
                elemento_usuario.capacidade = capacidade;
                elemento_usuario.identificador = identificador;
                strcpy(elemento_usuario.localizacao, localizacao);

                controle = insere_AVL(&arvore, elemento_usuario, &verificador);
                if(controle == 1)
                {
                    printf("-> Insercao Bem Sucedida.\n\n");
                }
                else
                {
                    printf("-> Insercao Mal Sucedida.\n\n");
                }
            }
            else if(operacao == 2)
            {
                printf("-> Operacao Indisponivel na Versao DEMO.\n\n");
                /*Operacao - Remocao AVL*/
            }
            else if(operacao == 3)
            {
                retorno_menor_trafego = menor_trafego(arvore);
                printf("-> Ponto da Rede Com Menor Trafego:\n");
                if(retorno_menor_trafego != NULL)
                {
                    printf("Trafego: %d\n", retorno_menor_trafego->trafego);
                    printf("Capacidade: %d\n", retorno_menor_trafego->capacidade);
                    printf("Identificador: %d\n", retorno_menor_trafego->identificador);
                    printf("Localizacao: %s\n\n", retorno_menor_trafego->localizacao);
                }
            }
            else if(operacao == 4)
            {
                controle = qtde_ocioso(arvore);
                printf("-> Quantidade de Pontos Ociosos: %d\n\n", controle);
            }
            else if(operacao == 5)
            {
                controle = nro_folha(arvore);
                printf("-> Numero de Nos Folhas: %d\n\n", controle);
            }
            else if(operacao == 6)
            {
                controle = cheia(arvore);
                if(controle == 1)
                {
                    printf("-> Arvore Eh Cheia.\n\n");
                }
                else
                {
                    printf("-> Arvore Nao Eh Cheia.\n\n");
                }
            }
            else if(operacao == 7)
            {
                do
                {
                    printf("Digite o Campo Chave do No (Chave >= 0): ");
                    scanf("%d", &operando1);
                    printf("\n");
                }
                while(operando1 < 0);

                elemento_usuario.trafego = operando1;
                elemento_usuario.capacidade = 0;
                elemento_usuario.identificador = 0;
                strcpy(elemento_usuario.localizacao, "Irrelevante");

                controle = nivel_no(arvore, elemento_usuario);
                if(controle != (-1))
                {
                    printf("-> Nivel do No: %d\n\n", controle);
                }
                else
                {
                    printf("-> Nao Foi Encontrado Ponto com Essa Chave\n\n");
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
    }

    libera_arvore_avl(&arvore);
    libera_arvore_avl(&arvore1);
    libera_arvore_avl(&arvore2);

    printf("\n-> Pressione qualquer tecla para fechar.\n");

    return 0;
}

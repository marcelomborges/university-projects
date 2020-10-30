/*
Programa: Arvore Binaria de Busca
Aluno: Marcelo Mendonca Borges
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_bb.h"

int main()
{
    /*Declaracao de Variaveis----------------------------------------------------------------------*/
    int i, idade, controle, opcao, operacao, operando1, operando2;
    char nome[100], curso[100];
    REGISTRO elemento_usuario;
    REGISTRO elemento[10];
    REGISTRO elemento_teste;
    REGISTRO *retorno_maior;
    ARVORE_BB arvore, arvore1, arvore2, auxiliar;
    /*---------------------------------------------------------------------------------------------*/

    /*Criacao das Arvores--------------------------------------------------------------------------*/
    for(i = 0; i < 10; i++)
    {
        elemento[i].idade = 20+i;
        strcpy(elemento[i].nome, "Irrelevante");
        strcpy(elemento[i].curso, "Irrelevante");
    }

    elemento_teste.idade = 18;
    strcpy(elemento_teste.nome, "AlunoIrrelevante");
    strcpy(elemento_teste.curso, "CursoIrrelevante");

    arvore = cria_arvore_bb();
    arvore1 = cria_arvore_bb();
    arvore2 = cria_arvore_bb();

    insere_ordenado_arvore_bb(&arvore1, elemento[3]);
    insere_ordenado_arvore_bb(&arvore1, elemento[1]);
    insere_ordenado_arvore_bb(&arvore1, elemento[0]);
    insere_ordenado_arvore_bb(&arvore1, elemento[2]);
    insere_ordenado_arvore_bb(&arvore1, elemento[5]);
    insere_ordenado_arvore_bb(&arvore1, elemento[4]);
    insere_ordenado_arvore_bb(&arvore1, elemento[6]);

    insere_ordenado_arvore_bb(&arvore1, elemento_teste);

    insere_ordenado_arvore_bb(&arvore2, elemento[8]);
    insere_ordenado_arvore_bb(&arvore2, elemento[7]);
    insere_ordenado_arvore_bb(&arvore2, elemento[9]);
    /*---------------------------------------------------------------------------------------------*/

    do
    {
        printf("#------------------------ Parte 2 - Arvore Binaria de Busca ------------------------------#\n");
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
            printf("Arvores Binarias de Busca Utilizada:------------------------------------\n\n");
            exibe_arvore_bb(arvore1);
            printf("   (Utilizada Para Realizar Todas as Funcoes)\n\n");
            exibe_arvore_bb(arvore2);
            printf("   (Utilizada Somente Na Funcao de Intercalar Arvores)\n\n");
            printf("------------------------------------------------------------------------\n\n");

            printf("Digite o numero da operacao voce deseja realizar: ");
            scanf("%d", &operacao);
            printf("\n");

            if(operacao == 1)
            {
                retorno_maior = maior(arvore1);
                printf("-> Aluno Com a Maior Idade:\n");
                if(retorno_maior != NULL)
                {
                    printf("Idade: %d\n", retorno_maior->idade);
                    printf("Nome: %s\n", retorno_maior->nome);
                    printf("Curso: %s\n\n", retorno_maior->curso);
                }
            }
            else if(operacao == 2)
            {
                controle = de_maior(arvore1);
                printf("-> Quantidade de Alunos Maiores de Idade: %d\n\n", controle);
            }
            else if(operacao == 3)
            {
                do
                {
                    printf("Digite o Limite Inferior de Idade (Idade >= 0): ");
                    scanf("%d", &operando1);
                }
                while(operando1 < 0);

                do
                {
                    printf("Digite o Limite Superior de Idade (Idade >= 0): ");
                    scanf("%d", &operando2);
                }
                while(operando1 < 0);

                controle = qtde_nos_abb(arvore1, operando1, operando2);
                printf("\n-> Quantidade de Alunos Entre %d e %d Anos de Idade: %d\n\n", operando1, operando2, controle);

            }
            else if(operacao == 4)
            {
                controle = um_filho(arvore1);
                printf("Quantidade de Nos que Possuem um Filho: %d\n\n", controle);
            }
            else if(operacao == 5)
            {
                printf("-> Operacao Indisponivel na Versao DEMO.\n");

                /*
                controle = completa(arvore1);
                if(controle == 1)
                {
                    printf("-> Arvore Eh Completa.\n\n");
                }
                else
                {
                    printf("-> Arvore Nao Eh Completa.\n\n");
                }
                */
            }
            else if(operacao == 6)
            {
                controle = altura_arv(arvore1);
                printf("Altura da Arvore: %d\n\n", controle);
            }
            else if(operacao == 7)
            {
                auxiliar = juntar(arvore1, arvore2);

                printf("Arvore Intercalada:-----------------------------------------------------\n\n");
                exibe_arvore_bb(auxiliar);
                printf("\n");
                printf("------------------------------------------------------------------------\n\n");

                printf("Arvore Intercalada Ordenada:--------------------------------------------\n\n");
                exibe_ordenado_arvore_bb(auxiliar);
                printf("\n");
                printf("------------------------------------------------------------------------\n\n");
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
    else
    {
        do
        {
            imprime_cabecalho_2();
            printf("Arvore Binaria de Busca Atual:----------------------------------------\n\n");
            exibe_arvore_bb(arvore);
            printf("\n\n");
            printf("------------------------------------------------------------------------\n\n");

            printf("Digite o numero da operacao voce deseja realizar: ");
            scanf("%d", &operacao);
            printf("\n");

            if(operacao == 1)
            {
                printf("Digite o Nome do Aluno (ate 100 caracteres): ");
                fflush(stdin);
                gets(nome);
                fflush(stdin);
                printf("\n");
                printf("Digite o Curso do Aluno (ate 100 caracteres): ");
                fflush(stdin);
                gets(curso);
                fflush(stdin);
                printf("\n");
                do
                {
                    printf("Digite a Idade do Aluno(Idade >= 0): ");
                    scanf("%d", &idade);
                    printf("\n");
                }
                while(idade < 0);

                elemento_usuario.idade = idade;
                strcpy(elemento_usuario.nome, nome);
                strcpy(elemento_usuario.curso, curso);

                controle = insere_ordenado_arvore_bb(&arvore, elemento_usuario);
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
                do
                {
                    printf("Digite a Idade do Aluno que Voce Deseja Remover(Idade >= 0): ");
                    scanf("%d", &idade);
                    printf("\n");
                }
                while(idade < 0);

                controle = remove_ordenado_arvore_bb(&arvore, idade);
                if(controle == 1)
                {
                    printf("-> Remocao Bem Sucedida.\n\n");
                }
                else
                {
                    printf("-> Remocao Mal Sucedida.\n\n");
                }
            }
            else if(operacao == 3)
            {
                retorno_maior = maior(arvore);
                printf("-> Aluno Com a Maior Idade:\n");
                if(retorno_maior != NULL)
                {
                    printf("Idade: %d\n", retorno_maior->idade);
                    printf("Nome: %s\n", retorno_maior->nome);
                    printf("Curso: %s\n\n", retorno_maior->curso);
                }
            }
            else if(operacao == 4)
            {
                controle = de_maior(arvore);
                printf("-> Quantidade de Alunos Maiores de Idade: %d\n\n", controle);
            }
            else if(operacao == 5)
            {
                do
                {
                    printf("Digite o Limite Inferior de Idade (Idade >= 0): ");
                    scanf("%d", &operando1);
                    printf("\n");
                }
                while(operando1 < 0);

                do
                {
                    printf("Digite o Limite Superior de Idade (Idade >= 0): ");
                    scanf("%d", &operando2);
                    printf("\n");
                }
                while(operando1 < 0);

                controle = qtde_nos_abb(arvore, operando1, operando2);
                printf("-> Quantidade de Pessoas Entre %d e %d Anos de Idade: %d\n\n", operando1, operando2, controle);
            }
            else if(operacao == 6)
            {
                controle = um_filho(arvore);
                printf("Quantidade de Nos que Possuem um Filho: %d\n\n", controle);
            }
            else if(operacao == 7)
            {
                printf("-> Operacao Indisponivel na Versao DEMO.\n");

                /*
                controle = completa(arvore);
                if(controle == 1)
                {
                    printf("-> Arvore Eh Completa.\n\n");
                }
                else
                {
                    printf("-> Arvore Nao Eh Completa.\n\n");
                }
                */
            }
            else if(operacao == 8)
            {
                controle = altura_arv(arvore);
                printf("Altura da Arvore: %d\n\n", controle);
            }
            else if(operacao == 9)
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
        while(operacao != 9);
    }

    libera_arvore_bb(&arvore);
    libera_arvore_bb(&arvore1);
    libera_arvore_bb(&arvore2);

    printf("\n-> Pressione qualquer tecla para fechar.\n");

    return 0;
}

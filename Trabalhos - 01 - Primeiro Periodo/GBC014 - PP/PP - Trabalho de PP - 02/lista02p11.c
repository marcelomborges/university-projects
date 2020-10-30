/*
Programa: Trabalho de PP 02 - Problema 11 (P11)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 06/05/2016
Descricao: Simular o controle de vendas dos assentos de um onibus
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Prototipos de Funcoes*/
void swit_oper(char[][12],int);
void imprime_matriz(char[][12]);
void comprar_assento(char[][12]);

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j;
    char lugares[4][12], opcao;
    /*-----------------------*/
    printf("Realizo o controle de vendas de assentos em um onibus de 48 lugares.\n");
    printf("Lugares marcados com \"0\" estao livre, e lugares marcados com \"X\" estao ocupados.\n\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 12; j++)
        {
            lugares[i][j] = '0';
        }
    }

    printf("Situacao inicial do onibus:\n");
    imprime_matriz(lugares);

    do
    {
        printf("Deseja comprar algum assento? (Digite S para sim, e N para nao): ");
        scanf("%c",&opcao);
        fflush(stdin);
        opcao = toupper(opcao);

        if(opcao == 'S')
        {
            comprar_assento(lugares);
        }
        else if(opcao == 'N')
        {
            printf("\n--->Saindo...\n");
        }
        else
        {
            printf("--->Opcao desconhecida\\invalida\n");
        }
    }
    while(opcao != 'N');

    return 0;
}

void imprime_matriz(char m[][12])
{
    int i, j;

    /*Estrutura exterior da matriz*/
    printf("BUS| ");
    for(j = 0; j < 12; j++)
    {
        printf("%2d ",j + 1);
    }
    printf("\n");

    for(i = 0; i < (12 * 3) + 4; i++)
    {
        if(i == 3) printf("|");
        else printf("-");
    }
    printf("\n");


    for(i = 0; i < 4; i++)
    {
        printf("%2d |",i + 1);/*Parte da estrutura exterior da matriz*/
        for(j = 0; j < 12; j++)
        {
            printf("%3c", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void comprar_assento(char lugares[4][12])
{
    int linha, coluna;

    system("CLS");
    printf("Situacao atual do onibus:\n\n");
    imprime_matriz(lugares);

    printf("Poltronas livres sao indicadas por \"0\" e poltronas ocupadas sao indicadas por \"X\".\n\n");
    printf("Em relacao a posicao que voce deseja:\n");

    do
    {
        printf("Digite a linha da poltrona: ");
        scanf("%d",&linha);
    }
    while((linha < 1)||(linha > 4));

    do
    {
        printf("Digite a coluna da poltrona: ");
        scanf("%d",&coluna);
    }
    while((coluna < 1)||(coluna > 12));

    if(lugares[linha - 1][coluna - 1] == '0')
    {

    }



    if(lugares[linha - 1][coluna - 1] == '0')
    {
        system("CLS");
        lugares[linha - 1][coluna - 1] = 'X';
        printf("Situacao atual do onibus:\n\n");
        imprime_matriz(lugares);
        printf("---> Transacao concluida.\n\n");

    }
    else
    {
        system("CLS");
        printf("Situacao atual do onibus:\n\n");
        imprime_matriz(lugares);
        printf("---> Assento invalido.\n\n");
    }

    system("PAUSE");
    fflush(stdin);

    printf("\n");
}

/*
Programa: Trabalho de PP 02 - Problema 10 (P10)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 03/05/2016
Descricao: Construir o jogo campo-minado utilizando funcoes.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Prototipos de Funcoes*/
void imprime_jogo(char[][100], int, int);
void espalha_minas(int[][100], int, int, int);
int marcar(int[][100], char[][100], int, int);
void revelar(int[][100], char[][100], int, int, int, int);

/*Declaracao de Variaveis Globais*/
int fim_jogo = 0;

int main ()
{
    /*Declaracao de variaveis*/
    char campo_most[100][100];
    int campo_num[100][100];
    int i, j, lin, col, minas, qminas, qmarc = 0, marc_true = 0;
    /*-----------------------*/

    printf("\t\t\t\tJogo: Campo-Minado\n\n");
    printf("Objetivo: Marcar todas as bombas corretamente sem revelar nenhuma delas.\n");
    printf("Fim de Jogo: Voce perde se realizar a marcacao onde nao tem uma bomba ou revelar uma bomba\n\n");

    do
    {
        printf("Digite a quantidade de linhas do campo que voce deseja jogar(3 <= linhas <= 99): ");
        scanf("%d",&lin);
    }
    while((lin < 3) || (lin > 99));
    do
    {
        printf("Digite a quantidade de colunas do campo que voce deseja jogar(3 <= linhas <= 99): ");
        scanf("%d",&col);
    }
    while((col < 3) || (col > 99));

    minas = lin * col / 6; /*Quantidade de minas dependendo do tamanho do campo*/
    qminas = minas;

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            campo_most[i][j] = '*';
        }
    }

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            campo_num[i][j] = 0;
        }
    }

    espalha_minas(campo_num, minas, lin, col);

    do
    {
        imprime_jogo(campo_most, lin, col);
        printf("\nA quantidade de minas no campo-minado eh: %d\n\n", qminas);
        qmarc += marcar(campo_num,campo_most,lin,col);
    }
    while((fim_jogo == 0)&&(qmarc != qminas));

    if(fim_jogo != 0)
    {
        printf("\n---> Voce perdeu porque revelou uma bomba.\n\n");
    }
    else
    {
        for(i = 0; i < lin; i++)
        {
            for(j = 0; j < col; j++)
            {
                if((campo_num[i][j] == -1) && (campo_most[i][j] == 'M'))
                {
                    marc_true++;
                }
            }
        }
        if(marc_true == qminas)
        {
            printf("\n---> Parabens! Voce Venceu!\n\n");
            printf("\a");
        }
        else
        {
            printf("\n---> Voce perdeu por ter marcado uma \"Bomba Falsa\".\n\n");
            printf("\a");
        }
    }

    system("PAUSE");

    return 0;
}

/*AREA DAS DEMAIS FUNCOES----------------------------------------------------------------------------------------------------------*/

void espalha_minas(int campo_num[][100], int minas, int lin, int col)
{
    int i, j, lin_mina, col_mina;

    srand(time(NULL));

    do
    {
        lin_mina = rand() % lin;
        col_mina = rand() % col;
        if(campo_num[lin_mina][col_mina] == 0)
        {
            campo_num[lin_mina][col_mina] = -1;
            minas--;
        }
    }
    while(minas > 0);

    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(campo_num[i][j] == 0)
            {
                /*Numeros da linha de cima*/
                if(i > 0)
                {
                    if(campo_num[i-1][j-1] == -1) campo_num[i][j] += 1;
                    if(campo_num[i-1][j] == -1)   campo_num[i][j] += 1;
                    if(campo_num[i-1][j+1] == -1) campo_num[i][j] += 1;
                }

                /*Numeros da linha de baixo*/

                if(i < lin-1)
                {
                    if(campo_num[i+1][j-1] == -1) campo_num[i][j] += 1;
                    if(campo_num[i+1][j] == -1)   campo_num[i][j] += 1;
                    if(campo_num[i+1][j+1] == -1) campo_num[i][j] += 1;
                }

                /*Numeros da esquerda e da direita*/

                if(j > 0)
                {
                    if(campo_num[i][j-1] == -1) campo_num[i][j] += 1;
                }
                if(j < col-1)
                {
                    if(campo_num[i][j+1] == -1) campo_num[i][j] += 1;
                }
            }
        }
    }
}

void imprime_jogo(char m[][100],int lin, int col)
{
    int i, j;

    system("CLS");

    printf("\t\t\t\tJogo: Campo-Minado\n\n");
    printf("Situacao Atual do Jogo:\n\n");
    /*Estrutura exterior da matriz*/
    printf("JCM| ");

    for(j = 0; j < col; j++)
    {
        printf("%2d ",j);
    }
    printf("\n");

    for(i = 0; i < (col * 3) + 4; i++)
    {
        if(i == 3) printf("|");
        else printf("-");
    }
    printf("\n");


    for(i = 0; i < lin; i++)
    {
        printf("%2d |",i);/*Parte da estrutura exterior da matriz*/
        for(j = 0; j < col; j++)
        {
            printf("%3c", m[i][j]);
        }
        printf("\n");
    }
}

int marcar(int campo_num[][100], char campo_most[][100], int lin, int col)
{
    int lin_marc, col_marc, qmarc = 0;
    char opcao;

    printf("Qual a casa que voce deseja marcar, desmarcar ou revelar?\n");
    do
    {
        printf("Digite a linha dessa casa: ");
        fflush(stdin);
        scanf("%d",&lin_marc);
    }
    while((lin_marc < 0) || (lin_marc >= lin));

    do
    {
        printf("Digite a coluna dessa casa: ");
        fflush(stdin);
        scanf("%d",&col_marc);
    }
    while((col_marc < 0) || (col_marc >= col));

    fflush(stdin);
    printf("\nVoce deseja marcar ou revelar a posicao (%d,%d)? (Digite M para marcar, D para desmarcar ou R para revelar): ",lin_marc,col_marc);
    scanf("%c",&opcao);
    fflush(stdin);
    opcao = toupper(opcao);

    if(opcao == 'M')
    {
        campo_most[lin_marc][col_marc] = 'M';
        imprime_jogo(campo_most,lin,col);
        qmarc++;
    }
    if(opcao == 'D')
    {
        if(campo_most[lin_marc][col_marc] == 'M')
        {
            campo_most[lin_marc][col_marc] = '*';
            imprime_jogo(campo_most,lin,col);
            qmarc--;
        }
    }
    if(opcao == 'R')
    {
        revelar(campo_num,campo_most,lin,col,lin_marc,col_marc);
    }

    return qmarc;
}

void revelar(int campo_num[][100], char campo_most[][100], int lin, int col, int lin_marc, int col_marc)
{
    if(campo_num[lin_marc][col_marc] == -1)
    {
        campo_most[lin_marc][col_marc] = 'B';
        printf("\a");
        fim_jogo++;
    }

    if(campo_num[lin_marc][col_marc] == 0) campo_most[lin_marc][col_marc] = '0';
    if(campo_num[lin_marc][col_marc] == 1) campo_most[lin_marc][col_marc] = '1';
    if(campo_num[lin_marc][col_marc] == 2) campo_most[lin_marc][col_marc] = '2';
    if(campo_num[lin_marc][col_marc] == 3) campo_most[lin_marc][col_marc] = '3';
    if(campo_num[lin_marc][col_marc] == 4) campo_most[lin_marc][col_marc] = '4';
    if(campo_num[lin_marc][col_marc] == 5) campo_most[lin_marc][col_marc] = '5';
    if(campo_num[lin_marc][col_marc] == 6) campo_most[lin_marc][col_marc] = '6';
    if(campo_num[lin_marc][col_marc] == 7) campo_most[lin_marc][col_marc] = '7';
    if(campo_num[lin_marc][col_marc] == 8) campo_most[lin_marc][col_marc] = '8';

    imprime_jogo(campo_most,lin,col);
}


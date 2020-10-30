/*
Programa: Trabalho de PP 02 - Problema 1 (P1)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 04/05/2016
Descricao: Construe uma matriz e define seus elementos usando uma logica especifica e funcoes.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
void matriz(int n, int mtz[100][100]);
void imprime(int n, int mtz[100][100]);

int main ()
{
    /*Declaracao de Variaveis*/
    int n, mtz[100][100];
    /*-----------------------*/
    printf("Construo matriz seguindo uma logica especifica de disposicao dos numeros:\n");
    printf("Observacao: A ordem da matriz (nxn) deve ser um numero (n) inteiro e impar.\n\n");

    do
    {
        printf("Digite a ordem da matriz (numero inteiro, positivo e impar): ");
        scanf("%d", &n);
    }
    while((n <= 0)||(n % 2 == 0));

    matriz(n, mtz);
    imprime(n, mtz);

    return 0;
}

/*AREA DAS DEMAIS FUNCOES----------------------------------------------------------------------------------------------------------*/

void matriz(int n, int mtz[100][100])
{
    int i, j, num, aux, num1, aux1;

    num = 0;
    aux = 0;
    num1 = 0;
    aux1 =- 1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j == 1)
                aux =- 1;
            if(num == 0 || num == n/2 || j == n/2+1)
                aux *= -1;

            if(i == n/2 && j == 1)
                aux=-1;

            if(aux == 1)
                num++;
            else if(aux == -1)
                num--;

            mtz[i][j]=num;
        }

        if(num1 == 0 || num1 == n/2 || i == n/2)
            aux1 *= -1;
        if(aux1 == 1)
            num1++;
        else if(aux1 == -1)
            num1--;

        num = num1;
        aux = 0;
    }
}

void imprime(int n, int mtz[100][100])
{
    int i, j;

    printf("\nMatriz:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%3d", mtz[i][j]);
        }
        printf("\n");
    }
}

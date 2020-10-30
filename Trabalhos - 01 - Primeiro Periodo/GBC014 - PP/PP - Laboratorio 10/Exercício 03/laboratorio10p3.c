/*
Programa: Laboratorio 10 Problema 3
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3], i, j;
    FILE *arq;
    /*Verificando se existe o arquivo !*/

    if ((arq = fopen("dados.txt", "r")) == NULL)
    {
        printf("Erro ao abrir dados.txt \n");
        exit(0); /*termina o programa.*/
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(arq, "%d", &a[i][j]);
        }
    }

    fclose(arq); /*Após ler, fechar arquivo.*/

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

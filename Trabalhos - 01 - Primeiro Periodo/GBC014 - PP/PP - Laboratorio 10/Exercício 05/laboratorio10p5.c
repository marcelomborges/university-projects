/*
Programa: Laboratorio 10 Problema 5
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **A, *b, *x;
    int m, n, i, j, k = 0, o;
    FILE *arq;

    /*Verificando se o arquivo existe!*/
    if ( (arq = fopen("dados3.dat", "r")) == NULL)
    {
        printf("Erro ao abrir dados3.dat\n");
        exit(0); /*termina o programa.*/
    }

    /*Leitura dos dados do arquivo.*/
    fscanf(arq,"%d %d",&m,&n);

    /*Alocação dinâmica.*/
    A = (int **) calloc(m, sizeof(int *));
    for (i = 0; i < m; i++)
        A[i] = (int *) calloc(n,sizeof(int));
    for (i = 0; i < m; i++)
        for (j = 0; j <n; j++)
            fscanf(arq,"%d",&A[i][j]);

    fscanf(arq, "%d", &o);
    b = (int*) calloc(o, sizeof(int));
    if(b == NULL)
    {
        printf("Erro de alocacao de vetor\n");
    }

    for(i = 0; i < o; i++)
    {
        fscanf(arq,"%d",&b[i]);
    }

    /*Fechando o arquivo.*/
    fclose(arq);

    /*Impressao na tela.*/
    printf("A = \n");
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
            printf(" [%4d] ", A[i][j]);
        printf("\n");
    }

    printf("\nb = \n");
    for(i = 0; i < o; i++)
    {
        printf(" [%4d] ",b[i]);
    }
    printf("\n\n");

    system("pause");

    x = (int*) malloc(n * sizeof(int));
    if(x == NULL)
    {
        printf("Erro de alocacao de vetor\n");
    }

    for(i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            x[i] = x[i] + (A[i][j] * b[j]);
        }
    }

    printf("\nx = \n");
    for(i = 0; i < m; i++)
    {
        printf(" [%4d] ",x[i]);
    }
    printf("\n\n");

    system("pause");

    return 0;
}

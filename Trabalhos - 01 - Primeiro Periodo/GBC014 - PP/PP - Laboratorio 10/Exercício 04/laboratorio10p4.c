/*
Programa: Laboratorio 10 Problema 4
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a;
    int m,n, i, j;
    FILE *arq;
    /*Verificando se o arquivo existe!*/
    if ( (arq = fopen("dados2.txt", "r")) == NULL)
    {
        printf("Erro ao abrir dados2.txt \n");
        exit(0); /*termina o programa.*/
    }

    /*Leitura dos dados do arquivo.*/
    fscanf(arq,"%d %d",&m,&n);

    /*Alocação dinâmica.*/
    a = (int **) calloc(m, sizeof(int *));
    for (i = 0; i < m; i++)
        a[i] = (int *) calloc(n,sizeof(int));
    for (i = 0; i < m; i++)
        for (j = 0; j <n; j++)
            fscanf(arq,"%d",&a[i][j]);

    /*Fechando o arquivo.*/
    fclose(arq);

    /*Impressao na tela.*/
    printf("A = \n");
    for (i=0; i < m; i++)
    {
        for (j=0; j < n; j++)
            printf(" [%4d] ", a[i][j]);
        printf("\n");
    }
    system("pause");
}

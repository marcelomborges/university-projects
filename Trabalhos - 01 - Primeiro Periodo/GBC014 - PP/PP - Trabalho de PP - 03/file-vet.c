/*
Programa: Trabalho PP 03 - Problema 01
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
Data: 19/06/2016
Descricao: Cria um vetor e uma matriz, alocados dinamicamente, de elementos aleatorios e coloca em um arquivo
*/


/*Inclusão de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* alocarvetor(int n)
{
    int *v;
    v = (int *) malloc (n * sizeof(int));
    if(v == NULL)
    {
        printf ("Erro na alocacao do vetor!\n");
        exit(EXIT_FAILURE);
    }

    return v;
}
int** alocarmatriz(int col, int lin)
{
    int i, **m;
    m = (int **) malloc (lin * sizeof(int*));
    if (m == NULL)
    {
        printf ("Erro na alocacao da matriz!\n");
        exit(EXIT_FAILURE);

    }
    for (i = 0; i < lin; i++)
    {
        m[i] = (int *) malloc (col * sizeof (int));

    }
    for (i = 0; i < lin; i++)
    {
        if (m[i] == NULL)
        {
            printf ("Erro na alocacao da matriz!\n");
            exit(EXIT_FAILURE);
        }
    }

    return m;
}

void preenchervetor(int *vet, int a, int b, int n)
{
    int j, aux;
    srand(time(NULL));
    for (j = 0; j < n; j++)
    {
        do
        {
            aux = rand() %b;

        }
        while(aux < a);
        vet[j] = aux;

    }

}

void preenchermatriz (int **mat, int a, int b, int n, int lin)
{

    int i, j, aux;
    srand(time(NULL));
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < n; j++)
        {
            do
            {
                aux = rand() %b+1;

            }
            while(aux < a);
            mat[i][j] = aux;

        }
    }
}



int main()
{
    int n, *v, **m, lin;
    int a, b;
    int i, j;

    /*Manipulacao de arquivos*/

    FILE *fd;

    printf("Gero um vetor e uma matriz de elementos aleatorios e os imprimo em um arquivo de texto (.txt).\n\n");

    do
    {
        printf ("Digite o tamanho do vetor e numero de colunas da matriz: ");
        scanf("%d", &n);
    }
    while(n <= 0);

    do
    {
        printf ("Digite o numero de linhas da matriz: ");
        scanf ("%d", &lin);
    }
    while(lin <= 0);

    printf ("\nAlocando...\n\n");

    v = alocarvetor(n);
    m = alocarmatriz(n, lin);

    system("pause");

    printf("\nDigite os valores para definir o intervalo dos elementos do vetor (o primeiro valor deve ser maior que o segundo):\n");
    do
    {
        printf("Primeiro valor do intervalo (a >= 0): ");
        scanf("%d",&a);
    }
    while(a < 0);
    do
    {
        printf("Segundo valor do intervalo (b >= 0): ");
        scanf("%d",&b);
    }
    while(b < 0);
    printf("\n");

    if (a >= b)
    {
        do
        {
            printf ("\nO primeiro valor precisa ser menor que o segundo, digite-os novamente:\n");
            do
            {
                printf("Primeiro valor do intervalo (a >= 0): ");
                scanf("%d",&a);
            }
            while(a < 0);
            do
            {
                printf("Segundo valor do intervalo (b >= 0): ");
                scanf("%d",&b);
            }
            while(b < 0);
        }
        while(a >= b);
    }

    /*Preencher vetor*/

    preenchervetor (v, a, b, n);
    preenchermatriz (m, a, b, n, lin);

    if ((fd = fopen("dados.txt","w+")) == NULL)
    {
        puts("Não posso abrir o Arquivo dados.\n");
        exit(1);
    }
    else
    {
        fprintf(fd,"Escrevendo o vetor:\n");
        fprintf(fd,"Vetor = {");
        for (i = 0; i < n; i++)
        {
            fprintf(fd," %d", v[i]);
        }
        fprintf(fd," }\n\n");

        fprintf(fd,"Escrevendo a matriz:\n");
        fprintf(fd,"Matriz:\n");
        for(i = 0; i < lin; i++)
        {
            for(j = 0; j < n; j++)
            {
                fprintf (fd,"%4d",m[i][j]);
            }
            fprintf(fd,"\n");
        }
    }
    fclose(fd);

    if(v != NULL)
    {
        free(v);
    }

    for(i = 0; i < lin; i++)
    {
        if(m[i] != NULL)
        {
            free(m[i]);
        }
    }
    if(m != NULL)
    {
        free(m);
    }

    return 0;
}

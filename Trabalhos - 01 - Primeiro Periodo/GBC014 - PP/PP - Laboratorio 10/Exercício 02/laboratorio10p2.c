/*
Programa: Laboratorio 10 Problema 2
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

#define MODO "w"

/*Redefiniçao para vetor tipo char: cadeia.*/
typedef char* cadeia;

/*Protótipo de função.*/
FILE *AbreArquivo(cadeia path, cadeia modo);

int main()
{
    FILE *fp;
    cadeia ARQ;

    ARQ = (cadeia) malloc(100 * sizeof(char));
    if(ARQ == NULL)
    {
        printf("Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o nome do arquivo: ");
    gets(ARQ);

    printf("O arquivo e: %s",ARQ);
    fp = AbreArquivo(ARQ,MODO);
    fclose(fp);
    system("PAUSE");
    return 0;
}

FILE *AbreArquivo(cadeia path, cadeia modo)
{
    FILE *arq;
    arq = fopen(path, modo);
    if (arq == NULL)
    {
        printf("\n O arquivo <%s> nao foi criado.\n",path);
        getch();
        exit(1);
    }
    else
    {
        printf("\n Arquivo <%s> foi criado com sucesso.\n",path);
    }

    return arq;
}

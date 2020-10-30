/*
Programa: Laboratorio 10 Problema 8
Aluno: Marcelo Mendonca Borges
Data: 26/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int i, v[10], n;

    /*Abrir o arquivo DADOS.BIN*/
    if ( (fp = fopen("dados.bin", "r")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    n = fread(v, sizeof(int), 10, fp); /*Lê os dados e coloca em v.*/
    fclose(fp);
    if (n != 10) /*Mensagem de erro.*/
        printf("Foram lidos apenas %d elementos !!! \n", n);
    for (i=0; i < n; i++)   /*Apresentando os dados ao usuário.*/
    {
        printf("v[%d] = %d \n", i, v[i]);
    }
}

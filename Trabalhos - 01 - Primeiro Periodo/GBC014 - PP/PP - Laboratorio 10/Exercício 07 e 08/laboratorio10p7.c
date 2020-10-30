/*
Programa: Laboratorio 10 Problema 7
Aluno: Marcelo Mendonca Borges
Data: 26/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int i, v[10];

    /*Lendo dados do teclado.*/
    for (i=0; i<10; i++)
    {
        printf("Elemento %d do vetor: ",i+1);
        scanf("%d",&v[i]);
    }
    /*Abrir o arquivo DADOS.BIN*/
    if ( (fp = fopen("dados.bin", "wb")) == NULL)
    {
        printf("Nao foi possivel criar o arquivo\n");
        exit(1);
    }
    if (fwrite(v, sizeof(int), 10, fp) != 10)
        printf("Nao foram escritos todos os elementos.\n");
    fclose(fp);
}

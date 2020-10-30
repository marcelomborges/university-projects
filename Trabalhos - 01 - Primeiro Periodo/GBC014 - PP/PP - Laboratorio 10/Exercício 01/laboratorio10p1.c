/*
Programa: Laboratorio 10 Problema 1
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char s[100];

    puts("Digite o Nome do Arquivo:");
    gets(s);
    fp = fopen(s, "r"); /* Abrir arquivo.*/

    /*Verificar se foi ou não realizada a abertura do arquivo.*/
    if (fp == NULL)
        printf("Não foi possivel abrir o arquivo %s\n",s);
    else
    {
        printf("Arquivo %s aberto com sucesso!!! \n",s);
        fclose(fp);
    }
    return 0;
}

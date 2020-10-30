/*
Programa: Laboratorio 10 Problema 6
Aluno: Marcelo Mendonca Borges
Data: 24/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *in, *out;
    char c;
    in = fopen("entrada.txt", "r");
    out = fopen("saida.txt", "w");
    if ( in == NULL)
    {
        printf("Erro ao criar %s", in);
        exit(1); /*termina o programa.*/
    }
    while (!feof(in))  /*ate o fim arquivo.*/
    {
        c = fgetc(in); /*le caractere de in.*/
        printf("%c",c);
        if(!feof(in)) fputc(toupper(c),out); /*escreve em out*/
    }
    fclose(in);
    fclose(out);

    return 0;
}

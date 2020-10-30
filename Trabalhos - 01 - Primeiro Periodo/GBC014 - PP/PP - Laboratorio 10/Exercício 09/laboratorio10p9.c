/*
Programa: Laboratorio 10 Exercicio 09
Aluno: Marcelo Mendonca Borges
Data: 26/06/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Declaracao de Estruturas*/
typedef struct
{
    char nome[80];
    float p1;
    float p2;
    float p3;

} ALUNO;

int main ()
{
    int i, cont = 0, aux = 0;
    ALUNO alunos[10];
    FILE *entrada;

    entrada = fopen("alunos.txt","r");

    if(entrada == NULL)
    {
        printf("--> Nao foi possivel abrir o arquivo alunos.txt\n");
        exit(1);
    }
    else
    {

    }
    fclose(entrada);
    return 0;
}

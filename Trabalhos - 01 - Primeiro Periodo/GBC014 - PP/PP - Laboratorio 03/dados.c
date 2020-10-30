/*
Programa: Laboratorio 03 Exercicio 6
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao: Simula 100 arremessos de um dado de 6 faces
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main ()
{
    /* Declaracao de variaveis */
    int i, face;
    /*-------------------------*/

    printf("Simulo 100 arremessos de um dado de 6 faces.\n\n");

    srand(time(NULL));

    for(i = 0; i < 100; i++)
    {
        printf("Rolagem numero %d = ", i + 1);
        face = (rand() % 6) + 1;
        printf("%d\n",face);
    }

    return 0;
}

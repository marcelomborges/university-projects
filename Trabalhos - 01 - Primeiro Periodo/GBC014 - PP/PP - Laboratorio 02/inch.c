/*
Programa:Laboratorio 02 Exercicio 7
Aluno:Marcelo Mendonca Borges
Data:02/04/2016
Descrição:Imprime a tabela de conversao de polegadas para centimetros
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/
int main ()
{
    /*Decalracao de Variaveis*/

    int cont1,cont2;
    float pol,cm;

    /*-----------------------*/
    pol = 1;
    cm = 2.54;
    printf("\tTABELA DE CONVERSAO DE POLEGADAS PARA CENTIMETROS\n\n");
    printf("pol--------------------cm\n");
    for(cont1=0,cont2=38;cont1 <= cont2;cont1++)
    {
        printf("%.2f--------------------%.2f\n",pol,cm);
        pol += 0.5;
        cm = cm + 1.27;
    }
    return 0;
}

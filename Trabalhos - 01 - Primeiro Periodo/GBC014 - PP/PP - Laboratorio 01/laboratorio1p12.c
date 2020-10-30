/*
Programa: Laboratorio 01 Exercicio 12
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/

/* Utilize algum valor negativo que seja menor do que -100, porque o "unsigned" na funcao printfIni tira o sinal do numero.*/

#include <stdio.h>

void printInt(unsigned int i)
{
    if(i > 100)
    {
        printf("Sucesso ! Voce conseguiu!\nValor do Int : %u",i);
        return (0);
    }
}
int main()
{
    int i=0;
    scanf("%d",&i);
    if(i > 100)
    {
        return(-1);
    }
    printInt(i);
    return (0);
}

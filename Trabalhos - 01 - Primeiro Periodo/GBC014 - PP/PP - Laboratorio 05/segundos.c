/*
Programa: Laboratorio 05 Exercicio 2
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Trasformo um horario (h:m:s) em seu correspondente em segundos utilizando uma funcao
*/

#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int segundos(int, int, int);
/*---------------------*/

int segundos(int h, int m, int s)
{
    int tempo = 0;

    h = h * 3600;
    m = m * 60;
    tempo = h + m + s;

    return tempo;
}

int main ()
{
    /*Declaracao de Variaveis*/
    int h, m, s, tempo;
    /*-----------------------*/

    printf("Converto um horario dado para seu correspondente em segundos \"(h:m:s) -> (s)\".\n");
    printf("Lembretes: (0 <= h <= 23) ; (0 <= m <= 59) ; (0 <= s <= 59)\n\n");

    do
    {
        printf("Digite as horas: ");
        scanf("%d",&h);
    }
    while((h < 0) || (h > 23));
    do
    {
        printf("Digite os minutos: ");
        scanf("%d",&m);
    }
    while((m < 0) || (m > 59));
    do
    {
        printf("Digite os segundos: ");
        scanf("%d",&s);
    }
    while((s < 0) || (s > 59));

    tempo = segundos(h,m,s);

    printf("\nO horario digitado eh: %02d:%02d:%02d\n",h,m,s);
    printf("O horario(tempo) em segundos eh: %ds\n",tempo);

    return 0;
}

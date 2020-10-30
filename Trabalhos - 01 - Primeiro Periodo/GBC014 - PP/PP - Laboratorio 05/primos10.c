/*
Programa: Laboratorio 05 Exercicio 6
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Calculo os 10 primeiros numeros primos maiores do que 100 com uma funcao e coloco-s em um vetor
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Prototipos de Funcoes*/
int primos(int);
/*---------------------*/

int primos(int n)
{
    int i, cont = 0, mod;
    float raizq;

    raizq = sqrt(n);

    for(i = 2; i <= raizq; i++)
    {
        mod = n % i;
        if(mod == 0)
        {
            cont++;
        }
    }
    return cont;
}

int main ()
{
    /*Declaracao de Variaveis*/
    int i, j, k = 0, v[10], cont;
    /*-----------------------*/

    printf("Calculo os 10 primeiros numeros primos maiores do que 100 e colocos-os no vetor v[].\n");
    printf("Depois imprimo esse vetor.\n\n");

    for(i = 2; i <= 999; i++)
    {
        cont = primos(i);
        if(cont == 0)
        {
            v[k] = i;
            k++;
        }
        if(k == 10)
        {
            break;
        }
    }

    printf("Vetor v[10] de 10 numeros primos maiores do que 100:\n");
    for(i = 0; i < 10; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}

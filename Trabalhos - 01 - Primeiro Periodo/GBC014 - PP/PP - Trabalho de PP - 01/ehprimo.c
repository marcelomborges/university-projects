/*
Programa: Trabalho de PP Problema 7 (P7)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 15/04/2016
Descricao: Verifica se um numero natual eh primo ou nao
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int cont=0,i,resto=0,n;
    float raizq;

    /*-----------------------*/

    printf("Bem vindo! Verifico se um numero natural eh primo ou nao.\n\n");

    do
    {
        printf("Digite o numero a ser avaliado: ");
        scanf("%d",&n);
    }
    while(n < 0);

    raizq = sqrt(n);

    if((n != 1) && (n != 0))
    {
        for(i = 2; i <= raizq; i++)
        {
            resto = n % i;
            if(resto == 0)
            {
                cont++;
            }
        }

        if (cont == 0)
        {
            printf("\nO numero %d eh primo.\n",n);
        }
        else
        {
            printf("\nO numero %d nao eh primo.\n",n);
        }
    }
    else if ((n == 1) || (n == (-1)))
    {
        printf("\nO numero %d nao eh primo, porque ele so tem um divisor que eh ele mesmo.\n",n);
    }
    else
    {
        printf("\nO numero %d nao eh primo, porque ele pode ser dividido por todos os numeros.\n",n);
    }
    return 0;
}

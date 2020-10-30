/*
Programa: Laboratorio 04 Exercicio 3
Aluno: Marcelo Mendonca Borges
Data: 15/04/2016
Descricao: Le uma matriz e identifica se ela eh de permutacao
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    /* Declaracao de variaveis */
    int i, j, n, perm_lin = 0, perm_col = 0, nao_perm = 0;
    float m[100][100];
    /*-------------------------*/

    do
    {
        printf("Defina a ordem da matriz M(n x n) = ");
        scanf("%d",&n);
    }
    while(n <= 0);


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Digite o valor do elemento M[%d][%d] = ",i,j);
            scanf("%f",&m[i][j]);
        }
        printf("\n");
    }

    printf("Matriz:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%7.02f",m[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(m[i][j] != 0)
            {
                if(m[i][j] == 1)
                {
                    perm_lin++;
                }
                else
                {
                    nao_perm++;
                }
            }
        }
    }
    for(j = 0; j < n; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(m[i][j] != 0)
            {
                if(m[i][j] == 1)
                {
                    perm_col++;
                }
                else
                {
                    nao_perm++;
                }
            }
        }
    }

    if((perm_lin == n)&&(perm_col == n)&&(nao_perm == 0))
    {
        printf("\nA matriz eh de permutacao.\n");
    }
    else
    {
        printf("\nA matriz nao eh de permutacao.\n");
    }

    return 0;
}

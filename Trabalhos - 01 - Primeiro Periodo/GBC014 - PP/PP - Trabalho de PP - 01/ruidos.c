/*
Programa: Trabalho de PP Problema 20 (P20)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 17/04/2016
Descricao: Calcula a media dos ruidos de cada carro, de cada velocidade e a media geral, depois imprimi a tabela e as medias(em decibeis)
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-----------------------*/
int main()
{
    /*Declaracao de variaveis*/

    int mat[6][7];
    int i, j, v = 10,veloc[7] = {50,60,70,80,90,100,110};
    float media1[6], media2[7], media3, soma1[6], media4, soma2[7], soma3, mediagl;

    /*-----------------------*/

    printf("Bem vindo! Recebo os valores de ruidos (em decibeis) de 6 carros em 7 velocidades diferentes.\n");
    printf("Os ruidos de cada carro sao avaliados nas velocidades: 50km/h, 60km/h, 70km/h, 80km/h, 90km/h, 100km/h, 110km/h.\n\n");

    for(i=0 ; i < 6 ; i++)
    {
        for(j=0 ; j < 7; j++)
        {
            printf("Entre com Carro[%d] - Ruido[%d]:",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0 ; i < 6 ; i++ )
    {
        for(j = 0 ; j < 7 ; j++)
        {
            soma1[i] += mat[i][j];
            media1[i] = soma1[i] / 7;
        }

    }
    for (i = 0 ; i < 6 ; i++ )
    {
        for(j = 0 ; j < 7 ; j++)
        {
            soma2[j] += mat[i][j];
            media2[j] = soma2[j] / 6;
        }
    }
    for (i = 0 ; i < 6 ; i++ )
    {
        for(j = 0 ; j < 7 ; j++)
        {
            media3 += mat[i][j];
        }
    }
    mediagl = media3 / 42;


    printf("----------------------------------------------------------\n");
    printf("\t\tVelocidade <<Media>>\n");
    printf("----------------------------------------------------------\n");
    printf("Carro  50      60      70      80      90     100     110\n");
    printf("----------------------------------------------------------\n");

    for( i = 0; i < 6 ; i++)
    {
        printf("%d", i+1);
        for (j = 0; j < 7 ; j++)
        {
            printf("     %3d", mat[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------------\n");
    printf("\n");

    for(i = 0; i < 6; i++)
    {
        printf("A media do carro %d eh: %.2f \n",i+1, media1[i]);
    }
    printf("\n");

    for(i = 0; i < 7; i++)
    {
        printf("A media da velocidade em %d km/h eh: %.2f \n",veloc[i], media2[i]);
    }
    printf("\n");

    printf("A media da velocidade global eh: %.2f \n", mediagl);

    return 0;
}

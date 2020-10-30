/*
Programa: Laboratorio 05 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 29/04/2016
Descricao: Normaliza um vetor dado utilizando funcoes
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Prototipos de Funcoes*/
void ler_vetor(float[], int);
float norma_vet(float[], int);
void normaliza_vet(float[], int);
float escreve_vetor(float[], int);
/*---------------------*/

void ler_vetor(float v[], int n)
{
   int i;

   for(i = 0; i < n; i++)
   {
        printf("Digite o elemento v[%d]: ",i);
        scanf("%f",&v[i]);
   }
}

float norma_vet(float v[], int n)
{
    int i;
    float soma = 0, norma;

    for(i = 0; i < n; i++)
    {
        soma += pow(v[i],2);
    }
    norma = sqrt(soma);

    return norma;
}

void normaliza_vet(float v[], int n)
{
    int i;
    float norma;

    norma = norma_vet(v,n);

    for(i = 0; i < n; i++)
    {
        v[i] = v[i] / norma;
    }
}

float escreve_vetor(float v[], int n)

{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("v[%d]: %f\n", i, v[i]);
    }
}

int main ()
{
    /*Declaracao de Variaveis*/
    int n;
    float v[100];
    /*-----------------------*/

    printf("Recebo um valor para o numero de elementos de um vetor, cada um de seus elementos e o normalizo.\n");
    printf("Observacao: O numero de elementos tem que ser um numero inteiro, maior do que 0.\n\n");

    do
    {
        printf("Digite a quantidade de elementos do vetor: ");
        scanf("%d",&n);
    }
    while ((n <= 0) || (n > 100));

    ler_vetor(v,n);
    normaliza_vet(v,n);
    printf("\nVetor v normalizado:\n");
    escreve_vetor(v,n);

    return 0;
}

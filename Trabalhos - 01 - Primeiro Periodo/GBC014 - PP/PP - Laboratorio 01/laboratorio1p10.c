/*
Programa: Laboratorio 01 Exercicio 10
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/


#include <stdio.h>

int main (void)
{
    float prova;
    float teste1, teste2, teste3;
    float notaFinal;

    printf("Calculo a nota final de uma aluno a partir de uma formula especifica a partir dos valores da prova e dos 3 testes\n");
    printf("Formula: Nota Final = 0.8 * Prova + 0.2 * \"Media dos 3 testes\"\n");
    printf("Tambem dou o valor logico (0 ou 1) da expressao \"Nota Final >= 5\"\n\n");

    printf ("Prova: ");
    scanf("%f",&prova);
    printf ("Teste 1: ");
    scanf("%f",&teste1);
    printf ("Teste 2: ");
    scanf("%f",&teste2);
    printf ("Teste 3: ");
    scanf("%f",&teste3);

    notaFinal = 0.8 * prova + 0.2 * ((teste1 + teste2 + teste3) / 3) ;

    printf ("Nota final %0.2f\n",notaFinal);

    printf("Resultado da expressao: %d\n", notaFinal >= 5.0);

    return 0;
}

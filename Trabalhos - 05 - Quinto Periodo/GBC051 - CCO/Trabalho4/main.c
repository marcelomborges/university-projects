/*
Programa: Trabalho 4 - Exercicio 02
Alunos: Adriano Araujo Martins de Resende 11611BCC015
        Marcelo Mendonca Borges           11611BCC020
Descricao: Implementacao de Metodos de Integracao Numerica
Analise: Analise de erros foi feita a mao e esta presente (como .pdf e .jpg) no arquivo .zip enviado
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho4.h"
/*-----------------------*/

int main()
{
    double resultado_trapezio, resultado_um_terco, resultado_tres_oitavos;

    printf("Metodo de Integracao Numerica utilizando as Regras do Trapezio, de Um Terco de Simpson e de Tres Oitavos de Simpson.\n");
    printf("Passo \"h\" calculado para garantir erro relativo menor que 0,0001 para a integracao da seguinte equacao, no intervalo [-5,0]:\n");
    printf("-> f(x) = x * (e^x)\n\n");

    resultado_trapezio = trapezio((-5), 0, 457);
    resultado_um_terco = um_terco_Simpson((-5), 0, 15);
    resultado_tres_oitavos = tres_oitavos_Simpson((-5), 0, 12);

    printf("Resultado pela Regra do Trapezio:\n");
    printf("-> Resultado: %10.10lf\n\n", resultado_trapezio);

    printf("Resultado pela Regra de Um Terco de Simpson:\n");
    printf("-> Resultado: %10.10lf\n\n", resultado_um_terco);

    printf("Resultado pela Regra de Tres Oitavos de Simpson:\n");
    printf("-> Resultado: %10.10lf\n", resultado_tres_oitavos);

    return 0;
}

/*
Programa: Laboratorio 02 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 02/04/2016
Descrição: Realiza operacoes simples
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    float operando1,operando2;
    char operador;

    /*-----------------------*/
    printf("Bem vindo a calculadora!\n");
    printf("Realizo operacoes de soma, subtracao, multiplicacao e divisao.\n");
    while ((operador != '+') && (operador != '-') && (operador != '*') && (operador != '/'))
    {
        printf("Digite a conta que sera realizada:\n");
        printf("Conta:");
        scanf("%f %c %f",&operando1,&operador,&operando2);

        switch(operador)
        {
            case '+':
                printf("Resultado = %.2f",operando1 + operando2);break;
            case '-':
                printf("Resultado = %.2f",operando1 - operando2);break;
            case '*':
                printf("Resultado = %.2f",operando1 * operando2);break;
            case '/':
                printf("Resultado = %.2f",operando1 / operando2);break;
            default:
                printf("Operacao Desconhecida!\n");
        };
    };
    return 0;
};

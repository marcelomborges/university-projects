/*
Programa: Laboratorio 02 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 02/04/2016
Descricao: Realiza o produto entre dois numeros por somas sucessivas
*/

#include <stdio.h>
#include <stdlib.h>

/*Algoritmo*/

int main ()
{
    /*Declaracao de Variaveis*/

    float n1,n2,produto;
    int contador;

    /*-----------------------*/
    printf("Bem vindo ao multiplicador.\n");
    printf("Realizo multiplicacoes por somas sucessivas.\n");
    printf("Digite o primeiro numero:\n");
    scanf("%f",&n1);
    printf("Digite o segundo numero:\n");
    scanf("%f",&n2);

    contador = 0;
    produto = 0;

    while (contador < n2)
    {
        contador++;
        produto += n1;
    }

    printf("O produto entre %.2f e %.2f eh: ",n1,n2);
    printf("%.2f",produto);

    return 0;
}

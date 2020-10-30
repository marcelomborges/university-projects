/*
Programa: Trabalho de PP 02 - Problema 8 (P8)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 04/05/2016
Descricao: Recebe uma string e procura por numeros nela
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Prototipos de Funcoes*/
void p_num(char[],int);

int main ()
{
    /*Declaracao de Variaveis*/
    int i, n;
    char string[100];
    /*-----------------------*/

    printf("Recebo uma string e, da esqueda para a direita, avalia a posicao de cada numero na string.\n");
    printf("Recebo a posicao do numero desejado e o imprimo na tela.\n");
    printf("Lembrete: Se nao existir um numero na posicao escolhida sera impresso \"-1\".\n\n");

    printf("Digite a string que sera analisada:\n");
    gets(string);
    printf("\n");

    do
    {
        printf("Digite a posicao ordinal do numero que voce desejar dessa string: ");
        scanf("%d",&n);
    }
    while(n <= 0);

    printf("\n");

    printf("O numero, da posicao ordinal %d, dos numeros da string eh: ",n);
    p_num(string,n);

    printf("\n");

    return 0;
}

void p_num(char s[], int n)
{
    int i, prim_num = 0, posicao = 0;

    for(i = 0; i < strlen(s); i++)
    {
        if((s[i] >= '0') && (s[i] <= '9'))
        {
            if(prim_num == 0)
            {
                posicao++;
                prim_num++;
            }
            if(posicao == n)
            {
                printf("%c",s[i]);
            }
        }
        else
        {
            prim_num = 0;
        }
    }
    if(n > posicao)
    {
        printf("-1");
    }
}

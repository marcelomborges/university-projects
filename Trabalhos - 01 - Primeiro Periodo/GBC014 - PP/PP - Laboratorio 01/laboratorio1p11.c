/*
Programa: Laboratorio 01 Exercicio 11
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char c = 'l', C = 'L', a = 'a', A = 'A', z = 'z', Z = 'Z';

    printf("Imprimo os caracteres \"anterior\" e \"posterior\" ao %c e ao %c\n",c, C);
    printf("Imprimo o caracter \"anterior\" ao %c e ao %c\n",a, A);
    printf("Imprimo o caracter \"posterior\" ao %c e ao %c\n\n",z, Z);

    printf("Caractere \"%c\" - Anterior: %c - Proximo: %c\n",c ,c - 1, c + 1);
    printf("Caractere \"%c\" - Anterior: %c - Proximo: %c\n",C ,C - 1, C + 1);
    printf("Caractere \"%c\" - Anterior: %c\n",a ,a - 1);
    printf("Caractere \"%c\" - Anterior: %c\n",A ,A - 1);
    printf("Caractere \"%c\" - Proximo: %c\n",z ,z + 1);
    printf("Caractere \"%c\" - Proximo: %c\n",Z ,Z + 1);

    return 0;
}

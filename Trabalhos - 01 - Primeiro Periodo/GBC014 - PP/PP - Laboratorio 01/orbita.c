/*
Programa: Laboratorio 01 Exercicio 13
Aluno: Marcelo Mendonca Borges
Data: 27/04/2016
*/

/*Nao eh possivel fazer isso sem "long double".*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    double G, M, PI, R, V, T;

    G = 6.7 * pow(10,(-11));
    M = 5.9 * pow(10,24);
    PI = 3.141592;

    printf("%lf %lf %lf\n\n",G,M,PI);

    printf("Inicialmente recebo o raio da orbita de um satelite em torno da terra (em m).\n");
    printf("Depois, com esse valor, calculo a velocidade escalar do movimento orbital do satelite (em m/s).\n");
    printf("Por fim calculo o periodo (T) do movimento orbital (em s).\n\n");

    do
    {
        printf("Digite o raio da orbita do satelite (em metros): ");
        scanf("%lf",&R);
    }
    while(R <= 0);

    V = sqrt((G * M) / R);
    T = 2 * PI * sqrt(pow(R, 3) / (G * M));

    printf("\nA velocidade escalar do movimento orbital desse satelite eh: %lf m/s\n",V);
    printf("O periodo do movimento orbital desse satelite eh: %lf s\n",T);

    return 0;
}

/*
Programa: Trabalho de PP Problema 3 (P3)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 14/04/2016
Descrição: Le o codigo digitado referente ao voto da pessoa e contabiliza cada voto para cada opcao
*/

/*Inclusao de Bibliotecas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-----------------------*/

int main ()
{
    /*Declaracao de variaveis*/

    int voto, codigo1=0, codigo2=0, codigo3=0, codigo4=0, codigo5=0;

    /*-----------------------*/

    printf("Bem vindo a Urna Eletronica do TSE:\n\n");

    printf("Tabela de Candidatos:\n");
    printf("Fulano ---------------- Codigo 1\n");
    printf("Sicrano --------------- Codigo 2\n");
    printf("Beltrano -------------- Codigo 3\n");
    printf("Voto Nulo ------------- Codigo 4\n");
    printf("Voto em Branco -------- Codigo 5\n\n");
    printf("Digite o codigo referente a sua opcao: ");

    while(scanf("%d",&voto) && voto != 99)
    {
        printf("Digite o codigo referente a sua opcao: ");

        switch(voto)
        {
        case 1: codigo1++; break;
        case 2: codigo2++; break;
        case 3: codigo3++; break;
        case 4: codigo4++; break;
        case 5: codigo5++; break;
        }
    }

    printf("\nFulano recebeu:     %d voto(s)\n",codigo1);
    printf("Sicrano recebeu:    %d voto(s)\n",codigo2);
    printf("Beltrano recebeu:   %d voto(s)\n",codigo3);
    printf("Votos Nulos:        %d voto(s)\n",codigo4);
    printf("Votos em Branco:    %d voto(s)\n",codigo5);

    return 0;
}

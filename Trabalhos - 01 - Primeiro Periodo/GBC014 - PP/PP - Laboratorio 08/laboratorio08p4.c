/*
Programa: Laboratorio 08 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 28/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definicao de Estruturas*/
typedef struct trabalhadores
{
    int id;
    char nome[30];
    char sexo;
    float salario;
}
trabalhador;

/*Declaracao de Funcoes*/
void ler_dados(trabalhador*);
void exibir_dados(trabalhador*);
void exibir_dados_sexo(trabalhador*, char);
void atualizar_salarios(trabalhador*, float);

int main ()
{
    int i;
    float perc;
    char letra;
    trabalhador trab[10];

    ler_dados(trab);
    exibir_dados(trab);

    do
    {
        fflush(stdin);
        printf("Digite o sexo para exibir os dados do grupo desse sexo especifico (Digite M para Masculino e F para Feminino): ");
        scanf("%c",&letra);
        fflush(stdin);
        letra = toupper(letra);
    }
    while((letra != 'M') && (letra != 'F'));

    exibir_dados_sexo(trab,letra);

    printf("Digite o percentual de salario que sera aumentado para todos os trabalhadores (em %): ");
    scanf("%f",&perc);
    perc = perc/100;

    atualizar_salarios(trab,perc);

    exibir_dados(trab);
    exibir_dados_sexo(trab,letra);

    return 0;
}

void ler_dados(trabalhador *trab)
{
    int i;

    for(i = 0; i < 10; i++)
    {
        trab[i].id = i;

        fflush(stdin);
        printf("Digite o nome do trabalhador [%d]: ",i);
        gets(trab[i].nome);
        fflush(stdin);

        do
        {
            fflush(stdin);
            printf("Digite o sexo do trabalhador [%d] (M para Masculino e F para Feminino): ",i);
            scanf("%c",&trab[i].sexo);
            fflush(stdin);
            trab[i].sexo = toupper(trab[i].sexo);
        }
        while((trab[i].sexo != 'M') && (trab[i].sexo != 'F'));

        do
        {
            printf("Digite o salario do trabalhador [%d] (em reais): ",i);
            scanf("%f",&trab[i].salario);
        }
        while(trab[i].salario < 0.0);

        printf("\n");
    }
}

void exibir_dados(trabalhador *trab)
{
    int i;

    printf("|ID |Trabalhador                   |Sexo|Salario        |\n");
    printf("|---|------------------------------|----|---------------|\n");
    for(i = 0; i < 10; i++)
    {
        printf("|%3d|",trab[i].id);
        printf("%30s|",trab[i].nome);
        printf("%4c|",trab[i].sexo);
        printf("%15.4f|",trab[i].salario);
        printf("\n");
    }
    printf("|---|------------------------------|----|---------------|\n");
    printf("\n");
}

void exibir_dados_sexo(trabalhador *trab, char letra)
{
    int i;

    printf("Dados dos trabalhadores do sexo [%c]:\n",letra);
    printf("|ID |Trabalhador                   |Sexo|Salario        |\n");
    printf("|---|------------------------------|----|---------------|\n");
    for(i = 0; i < 10; i++)
    {
        if(trab[i].sexo == letra)
        {
            printf("|%3d|",trab[i].id);
            printf("%30s|",trab[i].nome);
            printf("%4c|",trab[i].sexo);
            printf("%15.4f|",trab[i].salario);
            printf("\n");
        }
    }
    printf("|---|------------------------------|----|---------------|\n");
    printf("\n");
}

void atualizar_salarios(trabalhador *trab, float perc)
{
    int i;

    for(i = 0; i < 10; i++)
    {
        trab[i].salario = trab[i].salario + (trab[i].salario * perc);
    }
}


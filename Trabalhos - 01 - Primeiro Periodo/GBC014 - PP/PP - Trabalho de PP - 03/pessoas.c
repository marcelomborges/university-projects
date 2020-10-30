/*
Programa: Trabalho PP 03 - Exercicio 06
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
Data: 22/06/2016
Descricao: Ordena um conjunto de pessoas lidas de um arquivo com formato especifico
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaracao de Estruturas*/
typedef struct
{
    char nome[100];
    int idade;
    float altura;
}PESSOA;

/*Protoripos de Funcoes*/
int compara_pessoas(const void *a, const void *b);

int main ()
{
    int i, j, cont = 0, aux_idade;
    float aux_altura;
    char aux_nome[100], arq_entrada[100], arq_saida[100];
    PESSOA povo[50];
    FILE *entrada, *saida;

    printf("Ordeno um conjunto de pessoas de por ordem crescente de altura, a partir de dados lidos de um arquivo ja existente.\n");
    printf("Observacao: a idade eh medida em anos, como inteiro, e a altura eh medida em metros, como float.\n");
    printf("Formato do arquivo: \"<primeiro nome> <idade(int)> <altura(float)>\\n\"  (sem os caracteres <, >).\n\n");

    do
    {
        printf("Digite o nome do arquivo a ser aberto (junto com a extensao (.txt)):\n");
        fflush(stdin);
        gets(arq_entrada);
        fflush(stdin);
        printf("\n");
    }
    while(strlen(arq_entrada) > 99);

    entrada = fopen(arq_entrada,"r");

    if(entrada == NULL)
    {
        printf("--> Ocorreu um erro na abertura do arquivo de entrada\n");
        exit(1);
    }
    else
    {
        printf("--> Arquivo de entrada (aberto)\n\n");

        while(!feof(entrada))
        {
            fscanf(entrada,"%s %d %f",aux_nome,&aux_idade,&aux_altura);

            strcpy(povo[cont].nome,aux_nome);
            povo[cont].idade = aux_idade;
            povo[cont].altura = aux_altura;

            cont++;
        }

        qsort(povo, cont, sizeof(PESSOA), compara_pessoas);

        do
        {
            printf("Digite o nome do novo arquivo de texto (.txt) que sera criado (ate 90 caracteres):\n");
            fflush(stdin);
            gets(arq_saida);
            fflush(stdin);
            if(strlen(arq_saida) <= 90)
            {
                strcat(arq_saida,".txt");
            }
        }
        while(strlen(arq_saida) > 90);

        printf("\n");

        saida = fopen(arq_saida,"w+");

        if(saida == NULL)
        {
            printf("--> Ocorreu um erro na criacao/abertura do arquivo de saida\n");
            exit(1);
        }
        else
        {
            printf("--> Arquivo de saida (criado)\n\n");

            fprintf(saida,"|---------------------------------------------------|\n");
            fprintf(saida,"|Pessoas ordenadas pela altura----------------------|\n");
            fprintf(saida,"|------------------------------|---------|----------|\n");
            fprintf(saida,"|             Nome             |  Idade  |  Altura  |\n");
            fprintf(saida,"|------------------------------|---------|----------|\n");

            for(i = 0; i < cont; i++)
            {
                fprintf(saida,"|%30s|   %3d   |  %1.4f  |\n",povo[i].nome,povo[i].idade,povo[i].altura);
            }

            fprintf(saida,"|------------------------------|---------|----------|\n\n");

            printf("--> Arquivo que foi criado recebeu o texto\n\n");
        }
    }

    fclose(entrada);
    printf("--> Arquivo de entrada (fechado)\n\n");

    fclose(saida);
    printf("--> Arquivo de saida (fechado)\n\n");

    return 0;
}

int compara_pessoas(const void *a, const void *b)
{
    if((((*(PESSOA*)a).altura) == (*(PESSOA*)b).altura))
    {
        return 0;
    }
    else
    {
        if((((*(PESSOA*)a).altura) < (*(PESSOA*)b).altura))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

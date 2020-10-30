/*
Programa: Trabalho PP 03 - Problema 02
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
Data: 20/06/2016
Descricao: Le uma texto de um arquivo e embaralha as letras das palavras conservando a primeira e a ultima
*/

/*Inclusão de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Prototipos de Funcoes*/
int* alocar_int (int n);
void preencher_vetor(int n, int *vet);
void scrambled (char *str1, int n);
char* alocar_char (int n);

int main()
{
    int n, *vet, i;
    char string[100], aux;
    FILE *entrada, *saida;

    if((entrada = fopen("entrada_scrambled.txt ","r")) == NULL)
    {
        puts("Nao eh possivel abrir o Arquivo.\n");
        exit(1);
    }
    else
    {
        printf("\n--> Arquivo de entrada (aberto)\n\n");
    }

    if((saida = fopen("saida_scrambled.txt ","w+")) == NULL)
    {
        puts("Nao eh possivel abrir o arquivo.\n");
        exit(1);
    }
    else
    {
        printf("--> Arquivo de saida (criado)\n\n");
    }

    while(!feof(entrada))
    {
        fscanf (entrada,"%s",string);

        n = strlen(string);
        if(n > 1)
        {
            if(string[n-1] == ',' || string[n-1] == '.' || string[n-1] == ';' || string [n-1] == '?')
            {
                aux = string[n-1];
                string[n-1] = '\0';
                scrambled(string, n-1);
                fputs(string,saida);
                fputc(aux, saida);
                fputs(" ", saida);
            }
            else
            {
                scrambled(string, n);
                fputs(string,saida);
                fputs(" ", saida);
            }
        }
        else
        {
            fputs(string,saida);
            fputs(" ", saida);
        }
    }
    printf("--> Arquivo que foi criado recebeu o texto\n\n");

    fclose(entrada);
    printf("--> Arquivo de entrada (fechado)\n\n");

    fclose(saida);
    printf("--> Arquivo de saida (fechado)\n\n");

    return 0;
}

void preencher_vetor(int n, int *vet)
{
    int i, j, aux, s = 1;
    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        while(s != 0)
        {
            aux = (rand() % n) + 1;
            s = 0;
            for (j = 0; j < i; j++)
            {
                if (aux == vet[j])
                {
                    s = 1;
                }
            }
        }
        vet[i] = aux;
        aux = 0;
        s = 1;
    }
}

void scrambled (char *str1, int n)
{
    int *num, i, j = 0;
    char *str2;

    num = alocar_int(n-2);
    preencher_vetor(n-2, num);

    str2 = alocar_char(n);

    str2[0] = str1[0];
    str2[n-1] = str1[n-1];

    for(i = 1; i < n-1; i++)
    {
        str2[i] = str1[num[j]];
        j++;
    }
    strcpy(str1,str2);
    str1[n] = '\0';

    if(str2 != NULL)
    {
        free(str2);
    }
    if(num != NULL)
    {
        free(num);
    }
}

int* alocar_int (int n)
{
    int *v;
    v = (int*) malloc (n * sizeof(int));
    if (v == NULL)
    {
        printf ("Problema de alocacao de int!\n");
        exit(EXIT_FAILURE);
    }
    return v;
}

char* alocar_char (int n)
{
    char *v;
    v = (char*) malloc (n * sizeof(char));
    if (v == NULL)
    {
        printf ("Problema de alocacao de char!\n");
        exit(EXIT_FAILURE);
    }
    return v;
}



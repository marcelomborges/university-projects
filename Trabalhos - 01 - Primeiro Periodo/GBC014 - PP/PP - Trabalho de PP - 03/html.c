/*
Programa: Trabalho PP 03 - Exercicio 05
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
Data: 22/06/2016
Descricao: Le um arquivo e o copia em um novo arquivo retirando tudo que estiver delimitado por <> e tambem esses 2 caracteres
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/

int main()
{
    FILE *entrada, *saida;
    char c;
    int cont = 0;

    if((entrada = fopen("entrada_html.txt ","r")) == NULL)
    {
        puts("Nao eh possivel abrir o Arquivo de Entrada.\n");
        exit(1);
    }
    else
    {
        printf("\n--> Arquivo de entrada (aberto)\n\n");
    }

    if((saida = fopen("saida_html.txt ","w+")) == NULL)
    {
        puts("Nao eh possivel criar o arquivo de Saida.\n");
        exit(1);
    }
    else
    {
        printf("--> Arquivo de saida (criado)\n\n");
    }

    while(!feof(entrada))
    {
        c = fgetc(entrada);
        if(c == '<')
        {
            cont = 1;
        }
        if((cont == 0)&&(!feof(entrada)))
        {
            fprintf(saida,"%c",c);
        }
        if(c == '>')
        {
            cont = 0;
        }
    }

    printf("--> Arquivo que foi criado recebeu o texto\n\n");

    fclose(entrada);
    printf("--> Arquivo de entrada (fechado)\n\n");

    fclose(saida);
    printf("--> Arquivo de saida (fechado)\n\n");

    return 0;
}

/*
Programa: Trabalho PP 03 - Exercicio 07
Data: 23/06/2016
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Enumeradores*/
enum Naipe {Paus, Copas, Ouros, Espadas };
enum Face { As=1, Dois, Tres, Quatro, Cinco, Seis, Sete, Oito, Nove, Dez, Valete, Dama, Rei};

/*Declaracao de Estruturas*/
typedef struct carta
{
    enum Naipe naipe;
    enum Face face;
} Carta ;

/*Prototipos de Funcoes*/
void showCarta(Carta c);
void lerCarta(Carta *c);
int lerCartaArq(Carta *col);
void escreveCartaArq(Carta *col, int n);
void ordenaCarta(Carta *col, int n);
int ComparaCartas(const void * c1, const void * c2);

int main(int argc, char *argv[])
{
    Carta c1[100], c2[100];
    int n, i, num_cartas;

    printf("Ordeno um conjunto de cartas pelos \"valores combinados\" de face e naipe, que eh a soma de ambos.\n\n");
    printf("Guia de valores para os naipes:\n");
    printf("|---------|---------|\n");
    printf("|  Naipe  |  Valor  |\n");
    printf("|---------|---------|\n");
    printf("|  Paus   |    0    |\n");
    printf("|  Copas  |    1    |\n");
    printf("|  Ouros  |    2    |\n");
    printf("| Espadas |    3    |\n");
    printf("|---------|---------|\n\n");

    do
    {
        printf("Digite a quantidade de cartas que deseja escrever (ate 100 cartas): ");
        scanf("%d",&n);
    }
    while((n < 0)||(n > 100));

    for(i = 0; i < n; i++)
    {
        printf("Digite o valor de face da carta: ");
        scanf("%d",&c1[i].face);
        printf("Digite o naipe da carta: ");
        scanf("%d",&c1[i].naipe);
    }
    printf("\n");

    printf("Cartas escritas:\n");
    for(i = 0; i < n; i++)
    {
        showCarta(c1[i]);
    }
    printf("\n");

    escreveCartaArq(c1, n);
    num_cartas = lerCartaArq(c2);

    printf("Numero de cartas: %d\n\n", num_cartas);

    qsort(c2, n, sizeof(Carta), ComparaCartas);

    printf("Cartas ordenadas:\n");
    for(i = 0; i < n; i++)
    {
        showCarta(c2[i]);
    }

    return 0;
}

void showCarta(Carta c)
{
    char* faces[] = {"", "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char* naipes[] = {"Paus","Copas", "Ouros","Espadas"};
    printf("%s de %s\n",faces[c.face],naipes[c.naipe]);
}

void escreveCartaArq(Carta *col, int n)
{
    int i;
    FILE *cartas_bin;

    cartas_bin = fopen("cartas.bin","w+b");
    if(cartas_bin == NULL)
    {
        printf("--> Nao foi possivel criar o arquivo\n\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            fprintf(cartas_bin,"%d %d\n",col[i].face,col[i].naipe);
        }
    }

    fclose(cartas_bin);
}

int lerCartaArq(Carta *col)
{
    FILE *entrada;
    int c = 0, i = 0;
    int f,p;

    entrada = fopen("cartas.bin","rb");

    if(entrada == NULL)
    {
        printf("--> Nao foi possivel abrir o arquivo\n\n");
        exit(1);
    }
    else
    {
        while(!feof(entrada))
        {
            fscanf(entrada,"%d %d", &col[i].face, &col[i].naipe);
            c++;
            i++;
        }
        c--;

        return c;
    }

    fclose(entrada);
}

int ComparaCartas(const void * c1, const void * c2)
{
    if(((*(Carta*)c1).face + (*(Carta*)c1).naipe) == ((*(Carta*)c2).face + (*(Carta*)c2).naipe))
    {
        return 0;
    }
    else
    {
        if(((*(Carta*)c1).face + (*(Carta*)c1).naipe) < ((*(Carta*)c2).face + (*(Carta*)c2).naipe))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}


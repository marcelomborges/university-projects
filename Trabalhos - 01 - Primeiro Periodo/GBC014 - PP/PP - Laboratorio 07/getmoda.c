/*
Programa: Laboratorio 07 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 20/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int *Alocar_vetor(int n);
void Liberar_vetor (int *v);
void ler_vetor( int *v, int n, char *str);
void print_vetor(int *v, int n, char *str);
int produto_escalar(int *a, int *b, int n);
int get_moda(int *v, int n);/*Peguei essa função do exemplo do professor.*/

int main(int argc, char* argv[])
{
    /*Declaracao de Variaveis*/
	int *v1, *v2, moda1, moda2, prodescalar, n;
	/*-----------------------*/

	printf("Calculo a moda de 2 vetores e o produto escalar entre eles.\n\n");

	do
    {
        printf("Digite o tamanho dos vetores: ");
        scanf("%d",&n);
    }
    while(n <= 0);
    printf("\n");

	v1 = Alocar_vetor(n);
	v2 = Alocar_vetor(n);

	ler_vetor(v1,n,"v1");
	printf("\n");
	ler_vetor(v2,n,"v2");

	print_vetor(v1,n,"v1");
	print_vetor(v2,n,"v2");

	moda1 = get_moda(v1,n);
	printf("\nModa de v1: %d\n",moda1);
	moda2 = get_moda(v2,n);
	printf("\nModa de v2: %d\n",moda2);

	prodescalar = produto_escalar(v1,v2,n);
	printf("\nProduto escalar de v1.v2: %d\n",prodescalar);

	Liberar_vetor(v1);
	Liberar_vetor(v2);

	return 0;
}


int *Alocar_vetor(int n)
{
    int *v;

    if(n <= 0)
    {
        printf("Parametro incorreto para a funcao.\n");
        return NULL;
    }

    v = (int*) malloc(n * sizeof(int));

    if(v == NULL)
    {
        printf("Memoria insuficiente.\n");
        return NULL;
    }

    return v;
}

void Liberar_vetor (int *v)
{
    if(v != NULL)
    {
        free(v);
    }
}

void ler_vetor(int *v, int n, char *str)
{
    int i;

    printf("Digite os elementos do vetor %s:\n",str);
    for(i = 0; i < n; i++)
    {
        printf("%s[%d]: ",str,i);
        scanf("%d",v++);
    }
}

void print_vetor(int *v, int n, char *str)
{
    int i;

    printf("\nO vetor %s eh:\n",str);
    printf("%s = (");

    for(i = 0; i < n; i++)
    {
        if(i == (n-1)) printf("%d",*v++);
        else printf("%d, ",*v++);
    }
    printf(")\n");
}

int produto_escalar(int *a, int *b, int n)
{
    int i, soma = 0, *vet1 = a, *vet2 = b;
    for(i = 0; i < n; i++)
    {
        soma += (*a++) * (*b++);
    }
    return soma;
}

int get_moda(int *v, int n)
{
    int i, j, k = 0, *vex, *freq;
    int maior, presente;
    if(n > 0)
    {
        vex = Alocar_vetor(n);
        freq = Alocar_vetor(n);

        for(i = 0; i < n; i++)
        {
            presente = 0;
            for(j = 0; j < k; j++)
            {
                if(v[i] == vex[j])
                {
                    presente = 1;
                    freq[j]++;
                }
            }
            if(!presente)
            {
                freq[k] = 1;
                vex[k++] = v[i];
            }
        }
        maior = freq[0];
        j = 0;
        for(i=1; i<k; i++)
        {
            if(freq[i]>maior)
            {
                maior = freq[i];
                j = i;
            }
        }
        maior = vex[j];
        Liberar_vetor(freq);
        Liberar_vetor(vex);

        return maior;
    }
    return -1;
}



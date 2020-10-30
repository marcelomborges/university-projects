/*************************************/
/* program: getmoda.c                   */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2016                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

int *Alocar_vetor(int n);
void Liberar_vetor (int *v);
void ler_vetor(int *v, int n, char *str);
void print_vetor(int *v, int n, char *str);
int produto_escalar(int *a, int *b, int n);
int get_moda(int *v, int n);
void ordenar(int *v, int n);
void trocar(int *a, int *b);



int main(int argc, char* argv[])
{
    int *v1, *v2, moda, prodescalar;

    v1 = Alocar_vetor(10);
    v2 = Alocar_vetor(10);
    ler_vetor(v1,10,"A");
    ler_vetor(v2,10,"B");
    print_vetor(v1,10,"A");
    print_vetor(v2,10,"B");

    moda = get_moda(v1,10);
    printf("Moda de v1: %d\n",moda);
    prodescalar = produto_escalar(v1,v2,10);
    printf("Produto escalar v1.v2: %d\n",prodescalar);

    ordenar(v1,10);
    print_vetor(v1,10,"A");
    Liberar_vetor(v1);
    Liberar_vetor(v2);
    return 0;
}

int *Alocar_vetor(int n)
{
    int *v = NULL;

    if(n<0)
    {
        printf("Parametros incorretos...");
        return NULL;
    }
    v = (int *) malloc(n*sizeof(int));
    if(v==NULL)
    {
        printf("Espaço insuficiente na memória...\n");
        return NULL;
    }
    return v;
}

void Liberar_vetor (int *v)
{
    if(v!=NULL) free(v);
}

void ler_vetor(int *v, int n, char *str)
{
    int i;
    printf("Digite os elementos do vetor %s:\n",str);
    for(i=0; i<n; ++i)
    {
        printf("%s[%d]: ",str,i);
        scanf("%d",v++); //&v[i]
    }
}
void print_vetor(int *v, int n, char *str)
{
    int i;
    printf("Vetor %s:\n",str);
    for(i=0; i<n; ++i)
    {
        printf("%s[%d]: %d\n",str,i,*v++);
    }

}

int produto_escalar(int *a1, int *b1, int n)
{
    int soma=0, i, *a = a1, *b=b1;
    for(i=0; i<n; ++i)
    {
        soma += *a++ * *b++;
    }
    return soma;
}


int get_moda(int *v, int n)
{
    int i, j, k=0, *vex, *freq;
    int maior, presente;
    if(n>0)
    {
        vex = Alocar_vetor(n);
        freq = Alocar_vetor(n);
        for(i=0; i<n; i++)
        {
            presente = 0;
            for(j=0; j<k; j++)
            {
                if(v[i]==vex[j])
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


void ordenar(int *v, int n)
{
    int i, j, *p1 = v, *p2;
    for(i=0; i<n-1; i++)
    {
        p2 = p1;
        for(j=i+1; j<n; j++)
        {
            p2++;
            if(*p1<*p2) trocar(p1,p2);
        }
        p1++;
    }
}

void trocar (int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}



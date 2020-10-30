// Programa : normaliza.c
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

#define size 5
#define true  1
#define false 0

// inserir prototipos de funçoes
void ler_vetor(float v[],int n, char nome[]);
void show_vetor(float v[],int n, char nome[]);
void normaliza_vetor(float v[],int n);
float get_norma(float v[],int n);
void get_primos(int v[],int ini, int n);

// inserir variaveis globais

int main(int argc, char* argv[]){
    int i;
    float vet[size];
    int primos[10];

    ler_vetor(vet,size,"A");
    normaliza_vetor(vet,size);
    show_vetor(vet,size,"An");
    return 0;
}

void ler_vetor(float v[],int n, char vnome[]){
    int i;
    printf("Vetor %s:\n",vnome);
    for(i=0;i<n; i++){
        printf("%s[%d] = ",vnome,i);
        scanf("%f",&v[i]);
    }

}

void show_vetor(float v[],int n, char vnome[]) {
    int i;
    printf("Vetor %s:\n",vnome);
    for(i=0;i<n; i++){
        printf("%s[%d] = %.3f\n",vnome,i,v[i]);
    }
}

void normaliza_vetor(float v[],int n) {
    int i;
    float norma = get_norma(v,n);

    for(i=0;i<n; i++){
        v[i] = v[i]/norma;
    }
}

float get_norma(float v[],int n) {
    int i;
    float norma = 0.0;

    for(i=0;i<n; i++){
        norma = norma + v[i]*v[i];
    }
    norma = sqrt(norma);
    return norma;
}

void get_primos(int v[],int ini, int n){
    int k = 0, i, j=ini, primo;

    while(k<n){
        primo = true;
        for(i=2;i<sqrt(j);i++){
            if(j%i==0){
                primo = false;
                break;
            }
        }
        if(primo) v[k++] = j;
        j++;
    }
}

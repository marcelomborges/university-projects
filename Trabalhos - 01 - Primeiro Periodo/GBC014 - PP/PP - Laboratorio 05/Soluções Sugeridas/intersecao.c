// Programa : intersecao.c
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

#define size 5
#define true  1
#define false 0

// inserir prototipos de funçoes
void ler_vetor(int *v,int n, char nome[]);
void show_vetor(int v[],int n, char nome[]);
void intersecao(int conjunto[][100],int n, int in[]);


// inserir variaveis globais

int main(int argc, char* argv[]){
    int i, j, n;
    int cjs[size][100];
    int inter[100] = {0};
    char num[20], str = "C";

    printf("Digite a quantidade de conjuntos? ");
    scanf("%d",&n);
    for(i=0;i<n; i++){
        printf("#elementos do Conjunto %d: ",i+1);
        scanf("%d", &cjs[i][0]);
        for(j=1;j<=cjs[i][0];j++){
            printf("C%d[%d]: ",i+1,j);
            scanf("%d",&cjs[i][j]);
        }
    }
    intersecao(cjs,n,inter);
    show_vetor(inter,inter[0],"Inter");
    return 0;
}

void ler_vetor(int *v,int n, char vnome[]){
    int i;
    printf("Vetor %s:\n",vnome);
    for(i=1;i<=n; i++){
        printf("%s[%d] = ",vnome,i);
        scanf("%d",&v[i]);
    }

}

void show_vetor(int v[],int n, char vnome[]) {
    int i;
    printf("Vetor %s:\n",vnome);
    for(i=1;i<=n; i++){
        printf("%s[%d] = %d\n",vnome,i,v[i]);
    }
}


void intersecao(int conjunto[][100],int n, int in[]){
    int i, j, m, k=0, inter;

    if(n>1){
        for(i=1;i<=conjunto[0][0];i++){
            for(j=1;j<=conjunto[1][0];j++){
                if(conjunto[0][i]==conjunto[1][j]){
                    in[++k] = conjunto[0][i];
                }
            }
        }
    }
    if(n>2){
        for(m=2;m<n;m++){
            for(j=1;j<=k;j++){
                inter = 0;
                for(i=1;i<=conjunto[m][0];i++){
                    if(conjunto[m][i]==in[j]){
                        inter = 1;
                        break;
                    }
                }
                if(!inter){
                    i = 0;
                    while(in[++i]!=in[j]);
                    for(;i<=k-1;i++) in[i] = in[i+1];
                    k--;
                }
           }
        }
    }
    in[0] = k;
}

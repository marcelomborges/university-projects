// Programa : busca.c
// Autor: Claudio Camargo Rodrigues
// Data: dd/mm/aaaa
// Descricao: bla bla bla

#include <stdlib.h>
#include <stdio.h>

#define SIZE 5
#define VERDADEIRO 1
#define FALSO 0
// inserir prototipos de funçoes

// inserir variaveis globais

int main(int argc, char* argv[]){
    char classificados[SIZE][30];
    char candidato[30], str[30];
    int i, j,colocacao=0, classificado = FALSO;

    printf("Digite a lista de classificados: \n");
    for(i=0;i<SIZE;i++){
        printf("%do. colocado: ",i+1);
        scanf("%29[^\n]s",&classificados[i]);
        fflush(stdin);
    }
    printf("Busca:\n");
    printf("Digite o nome do candidato: ");
    scanf("%29[^\n]",candidato);
    fflush(stdin);
    for(i=0;i<SIZE;i++){
        strcpy(str,classificados[i]);
        j = 0;
        while(str[j]!=' ') j++;
        str[j] = '\0';
        if(strcmp(candidato,str)==0){
            colocacao = i+1;
            classificado = VERDADEIRO;
            printf("%d - %s \n",colocacao, classificados[i]);
  //          break;
        }
    }
 /*
    if(classificado)    {
        printf("O candidato %s foi aprovado em %do. lugar.\n",candidato,colocacao);
    } else printf("Desculpe, o nome %s nao foi encontrado.\n", candidato);
*/
    return 0;
}

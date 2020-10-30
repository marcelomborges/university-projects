#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct no NO;
typedef struct no* ARVORE_BINARIA;

/*Declaracao de Prototipos de Funcoes*/
ARVORE_BINARIA cria_arvore_binaria_vazia();
ARVORE_BINARIA cria_arvore_binaria(int elemento, ARVORE_BINARIA esquerda, ARVORE_BINARIA direita);
int arvore_binaria_vazia(ARVORE_BINARIA arv);
void libera_arvore_binaria(ARVORE_BINARIA *arv);
int busca_arvore_binaria(ARVORE_BINARIA arv, int elemento);
int remove_folha_arvore_binaria(ARVORE_BINARIA *arv, int elemento);
void exibe_arvore_binaria(ARVORE_BINARIA arv);
void imprime_arvore_binaria(ARVORE_BINARIA arvore);

#endif // ARVORE_BINARIA_H_INCLUDED

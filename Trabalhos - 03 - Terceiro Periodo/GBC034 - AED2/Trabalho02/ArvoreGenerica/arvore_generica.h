#ifndef ARVORE_GENERICA_H_INCLUDED
#define ARVORE_GENERICA_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct no NO;
typedef struct no* ARVORE_GENERICA;

/*Declaracao de Prototipos de Funcoes*/
ARVORE_GENERICA cria_arvore(int elemento);
int insere_generica(ARVORE_GENERICA arvore_no, ARVORE_GENERICA subarvore);
int busca_generica(ARVORE_GENERICA arvore, int elemento);
void libera_arvore_generica(ARVORE_GENERICA *arvore);
void exibe_arvore_generica(ARVORE_GENERICA arvore);
void imprime_arvore_generica(ARVORE_GENERICA arvore);

void preorder(ARVORE_GENERICA arvore);
void imprime_preorder(ARVORE_GENERICA arvore);
void postorder(ARVORE_GENERICA arvore);
void imprime_postorder(ARVORE_GENERICA arvore);
void percorre_nivel(ARVORE_GENERICA arvore);
void imprime_percorre_nivel(ARVORE_GENERICA arvore);
int nro_derivacao(ARVORE_GENERICA arvore);
int grau_no(ARVORE_GENERICA arvore);
int grau_arv(ARVORE_GENERICA arvore);
int qtde_nos_generica(ARVORE_GENERICA arvore, int grau);
int altura_arvore_generica(ARVORE_GENERICA arvore);
int altura_no(ARVORE_GENERICA arvore, int elemento);
void imprime_cabecalho();

#endif // ARVORE_GENERICA_H_INCLUDED

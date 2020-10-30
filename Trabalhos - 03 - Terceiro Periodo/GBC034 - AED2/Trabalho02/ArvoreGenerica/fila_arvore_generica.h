#ifndef FILA_ARVORE_GENERICA_H_INCLUDED
#define FILA_ARVORE_GENERICA_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct elemento_fila_arvore_generica
{
    ARVORE_GENERICA arvore_fila;
    ARVORE_GENERICA* proxima_arvore;
}
ELEMENTO_FILA_ARVORE_GENERICA;

typedef struct fila_arvore_generica
{
    int tamanho;
    ELEMENTO_FILA_ARVORE_GENERICA* primeiro;
    ELEMENTO_FILA_ARVORE_GENERICA* ultimo;
}
FILA_ARVORE_GENERICA;

/*Declaracao de Prototipos de Funcoes*/
FILA_ARVORE_GENERICA* cria_fila_arvore_generica();
int insere_fila_arvore_generica(ARVORE_GENERICA arvore, FILA_ARVORE_GENERICA* fila);
ARVORE_GENERICA* remove_fila_arvore_generica(FILA_ARVORE_GENERICA* fila);

#endif // FILA_ARVORE_GENERICA_H_INCLUDED

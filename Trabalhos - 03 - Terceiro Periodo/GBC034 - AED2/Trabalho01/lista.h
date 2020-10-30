#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct elemento ELEMENTO;
typedef struct lista LISTA;

void cria_lista (LISTA* lista);
void insere_elemento_final (LISTA *lista, int vertice, int peso);
int retira_primeiro_elemento(LISTA *lista);

#endif // LISTA_H_INCLUDED

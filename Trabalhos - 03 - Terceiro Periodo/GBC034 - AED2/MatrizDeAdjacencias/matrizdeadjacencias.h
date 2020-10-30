#ifndef MATRIZDEADJACENCIAS_H_INCLUDED
#define MATRIZDEADJACENCIAS_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct grafo GRAFO;

/*Declaracao do Prototipo das Funcoes*/
GRAFO *cria_grafo(int num_vertices);
int insere_aresta(GRAFO *grafo, int vertice1, int vertice2, int peso);
int verifica_aresta(GRAFO *grafo, int vertice1, int vertice2);
int remove_aresta(GRAFO *grafo, int vertice1, int vertice2);
int consulta_aresta(GRAFO *grafo, int vertice1, int vertice2, int *peso);
void libera_grafo(GRAFO **grafo);
void mostra_adjacentes(GRAFO *grafo, int vertice);
void mostra_grafo(GRAFO *grafo);
int get_vertices(GRAFO *grafo);
int get_arestas(GRAFO *grafo);

#endif // MATRIZDEADJACENCIAS_H_INCLUDED

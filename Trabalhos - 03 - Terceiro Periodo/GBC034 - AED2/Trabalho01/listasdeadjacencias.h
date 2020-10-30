#ifndef LISTASDEADJACENCIAS_H_INCLUDED
#define LISTASDEADJACENCIAS_H_INCLUDED

typedef struct elemento ELEMENTO;
typedef struct lista LISTA;

/*Declaracao de Estruturas*/
typedef struct no_la NO_LA;
typedef struct grafo_la GRAFO_LA;

/*Declaracao do Prototipo das Funcoes*/
GRAFO_LA* cria_grafo_la(int num_vertices);
int insere_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2, int custo, int delay, int capacidade, int trafego);
int verifica_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2);
int remove_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2);
int consulta_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2, int *custo, int *delay, int *capacidade, int *trafego);
void libera_grafo_la(GRAFO_LA **grafo);
void mostra_adjacentes_la(GRAFO_LA *grafo, int vertice);
void mostra_grafo_la(GRAFO_LA *grafo);
int numVertices_la(GRAFO_LA *grafo);
int numArestas_la(GRAFO_LA *grafo);
int grauVertice_la(GRAFO_LA *grafo, int vertice);
int ehAdjacente_la(GRAFO_LA *grafo, int vertice1, int vertice2);
GRAFO_LA* leitura_arquivo_la(char *arquivo_entrada);
int escrita_arquivo_la(GRAFO_LA* grafo, char *arquivo_saida);
int procura_menor_distancia(float *distancias, int *visitados, int num_vertices);
int pegar_peso_la(GRAFO_LA *grafo, int vertice1, int vertice2, int peso);
void dijkstra_la_aux(GRAFO_LA *grafo, int origem, int *anteriores, float *distancias, int peso);
int** dijkstra_la(GRAFO_LA *grafo, int origem, int *receptores, int num_receptores, int peso);
void busca_profundidade_aux(GRAFO_LA* grafo, int vertice1, int vertice2, int* visitados, int* caminho, int* controle, int* parada);
int** busca_profundidade(GRAFO_LA *grafo, int origem, int *receptores, int num_receptores);
int custo_total(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento);
int delay_maximo_la(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento);
float utilizacao_maxima_enlace(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento, float tam_mensagem);

#endif // LISTASDEADJACENCIAS_H_INCLUDED

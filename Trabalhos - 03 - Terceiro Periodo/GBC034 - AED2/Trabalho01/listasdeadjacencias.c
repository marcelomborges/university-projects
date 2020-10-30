/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "listasdeadjacencias.h"

/*Implementacao do TAD---------------------------------------------------------------------------*/
struct no_la
{
    int vertice;

    int custo;
    int delay;
    int capacidade;
    int trafego;

    NO_LA *proximo;
};

struct grafo_la
{
    int num_vertices;
    int num_arestas;
    int *grau;
    NO_LA **aresta;
};

GRAFO_LA* cria_grafo_la(int num_vertices)
{
    int i;
    GRAFO_LA *grafo;

    /*Verifica o valor da quantidade de vertices*/
    if(num_vertices <= 0)
    {
        printf("-> Erro: Numero de vertices invalido.\n");
        return NULL;
    }

    /*Alocacao do Grafo*/
    grafo = (GRAFO_LA*) malloc(sizeof(GRAFO_LA));
    if(grafo == NULL)
    {
        printf("-> Erro: Falha na alocacao do grafo.\n");
        return NULL;
    }

    /*Iniciando valores no grafo*/
    grafo->num_vertices = num_vertices;
    grafo->num_arestas = 0;

    /*Alocacao do vetor de graus*/
    grafo->grau = (int*) calloc(num_vertices, sizeof(int));
    if(grafo->grau == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de graus.\n");
        free(grafo);
        return NULL;
    }

    grafo->aresta = (NO_LA**) malloc(num_vertices * sizeof(NO_LA*));
    if(grafo->aresta == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de ponteiros.\n");
        free(grafo->grau);
        free(grafo);
        return NULL;
    }

    for(i = 0; i < num_vertices; i++)
    {
        grafo->aresta[i] = NULL;
    }

    return grafo;
}

int insere_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2, int custo, int delay, int capacidade, int trafego)
{
    NO_LA *aux, *novo_no_1, *novo_no_2;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }
    if(vertice1 == vertice2)
    {
        printf("-> Erro: Vertices iguais, lacos nao sao permitidos.\n");
        return (-1);
    }

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }
    if(aux != NULL)
    {
        printf("-> Aresta ja existe.\n");
        return 0;
    }

    novo_no_1 = (NO_LA*) malloc(sizeof(NO_LA));
    if(novo_no_1 == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no 1.\n");
        return (-1);
    }
    novo_no_2 = (NO_LA*) malloc(sizeof(NO_LA));
    if(novo_no_1 == NULL)
    {
        printf("-> Erro: Falha na alocacao do novo no 2.\n");
        return (-1);
    }

    /*Inserindo a primeira aresta, de acordo com a entrada*/
    novo_no_1->vertice = vertice2;
    novo_no_1->custo = custo;
    novo_no_1->delay = delay;
    novo_no_1->capacidade = capacidade;
    novo_no_1->trafego = trafego;

    novo_no_1->proximo = grafo->aresta[vertice1];
    grafo->aresta[vertice1] = novo_no_1;

    /*Inserindo a segunda aresta, complementar a entrada*/
    novo_no_2->vertice = vertice1;
    novo_no_2->custo = custo;
    novo_no_2->delay = delay;
    novo_no_2->capacidade = capacidade;
    novo_no_2->trafego = trafego;

    novo_no_2->proximo = grafo->aresta[vertice2];
    grafo->aresta[vertice2] = novo_no_2;

    /*Atualizando os Dados da Estrutura*/
    grafo->num_arestas++;
    grafo->grau[vertice1]++;
    grafo->grau[vertice2]++;

    return 1;
}

int verifica_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2)
{
    NO_LA* aux;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }
    if(vertice1 == vertice2)
    {
        printf("-> Erro: Vertices iguais, lacos nao sao permitidos.\n");
        return (-1);
    }

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int remove_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2)
{
    NO_LA *ant, *aux;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }
    if(vertice1 == vertice2)
    {
        printf("-> Erro: Vertices iguais, lacos nao sao permitidos.\n");
        return (-1);
    }

    /*Removendo a primeira aresta, de acordo com a entrada*/
    ant = NULL;
    aux = grafo->aresta[vertice1];

    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        ant = aux;
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    if(ant == NULL)
    {
        grafo->aresta[vertice1] = aux->proximo;
    }
    else
    {
        ant->proximo = aux->proximo;
    }

    if(aux != NULL)
    {
        free(aux);
    }

    /*Removendo a segunda aresta, complementar a entrada*/
    ant = NULL;
    aux = grafo->aresta[vertice2];

    while((aux != NULL)&&(aux->vertice != vertice1))
    {
        ant = aux;
        aux = aux->proximo;
    }
    if(aux == NULL)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    if(ant == NULL)
    {
        grafo->aresta[vertice2] = aux->proximo;
    }
    else
    {
        ant->proximo = aux->proximo;
    }

    if(aux != NULL)
    {
        free(aux);
    }

    /*Atualizando os Dados da Estrutura*/
    grafo->num_arestas--;
    grafo->grau[vertice1]--;
    grafo->grau[vertice2]--;

    return 1;
}

int consulta_aresta_la(GRAFO_LA *grafo, int vertice1, int vertice2, int *custo, int *delay, int *capacidade, int *trafego)
{
    NO_LA* aux;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }
    if(vertice1 == vertice2)
    {
        printf("-> Erro: Vertices iguais, lacos nao sao permitidos.\n");
        return (-1);
    }

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        printf("-> Aresta inexistente.\n");
        return 0;
    }

    *custo = aux->custo;
    *delay = aux->delay;
    *capacidade = aux->capacidade;
    *trafego = aux->trafego;

    return 1;
}

void libera_grafo_la(GRAFO_LA **grafo)
{
    int i;
    NO_LA *aux, *aux2;

    for(i = 0; i < (*grafo)->num_vertices; i++)
    {
        aux = (*grafo)->aresta[i];
        while(aux != NULL)
        {
            aux2 = aux;
            aux = aux->proximo;
            if(aux2 != NULL)
            {
                free(aux2);
            }
        }
    }

    if((*grafo)->aresta != NULL)
    {
        free((*grafo)->aresta);
    }

    if((*grafo)->grau != NULL)
    {
        free((*grafo)->grau);
    }

    if((*grafo) != NULL)
    {
        free(*grafo);
    }

    grafo = NULL;
}

void mostra_adjacentes_la(GRAFO_LA *grafo, int vertice)
{
    NO_LA *aux;

    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inexistente.\n");
    }
    else if((vertice < 0)||(vertice > (grafo->num_vertices - 1)))
    {
        printf("-> Erro: Vertice invalido.\n");
    }
    else
    {
        aux = grafo->aresta[vertice];
        if(aux == NULL)
        {
            printf("-> O vertice %d nao possui adjacentes.", vertice);
        }
        else
        {
            while(aux != NULL)
            {
                printf("(%d -> %d = %d, %d, %d, %d) ", vertice, aux->vertice, aux->custo, aux->delay, aux->capacidade, aux->trafego);
                aux = aux->proximo;
            }
        }
    }
}

void mostra_grafo_la(GRAFO_LA *grafo)
{
    int i;

    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inexistente.\n");
    }
    else if(grafo->num_arestas == 0)
    {
        printf("-> Grafo vazio.\n");
    }
    else
    {
        printf("\nGrafo:--------------------------------------------------\n");
        for(i = 0; i < grafo->num_vertices; i++)
        {
            printf("Vertice %d: ", i);
            mostra_adjacentes_la(grafo, i);
            printf("\n");
        }
        printf("--------------------------------------------------------\n");
    }
}

int numVertices_la(GRAFO_LA *grafo)
{
    return grafo->num_vertices;
}

int numArestas_la(GRAFO_LA *grafo)
{
    return grafo->num_arestas;
}

int grauVertice_la(GRAFO_LA *grafo, int vertice)
{
    return grafo->grau[vertice];
}

int ehAdjacente_la(GRAFO_LA *grafo, int vertice1, int vertice2)
{
    NO_LA* aux;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(aux == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*Manipulacao de Arquivos------------------------------------------------------------------------*/
GRAFO_LA* leitura_arquivo_la(char *arquivo_entrada)
{
    int token = 0, controle, vertice1, vertice2;
    int num_vertices;
    int custo, delay, capacidade, trafego;
    FILE *arquivo;
    GRAFO_LA *grafo;

    arquivo = fopen(arquivo_entrada,"r");
    if(arquivo == NULL)
    {
        printf("-> Erro: Falha na abertura do arquivo de entrada.\n\n");
        return NULL;
    }
    else
    {
        printf("-> Arquivo \"%s\" aberto.\n", arquivo_entrada);
    }

    while(!feof(arquivo))
    {
        if(token == 0)
        {
            fscanf(arquivo,"Vertices = %d\n", &num_vertices);
            grafo = cria_grafo_la(num_vertices);
            if(grafo == NULL)
            {
                printf("-> Erro: Falha na criacao do grafo.\n");
                return NULL;
            }
            else
            {
                printf("-> Grafo criado.\n");
            }
            token = 1;
        }
        else
        {
            fscanf(arquivo,"(%d -> %d = %d, %d, %d, %d)\n", &vertice1, &vertice2, &custo, &delay, &capacidade, &trafego);
            controle = insere_aresta_la(grafo, vertice1, vertice2, custo, delay, capacidade, trafego);
            if(controle == 1)
            {
                printf("Inserindo aresta: (%d -> %d = %d, %d, %d, %d)\n", vertice1, vertice2, custo, delay, capacidade, trafego);
            }
        }
    }

    controle = fclose(arquivo);
    if(controle != 0)
    {
        printf("-> Erro: Falha no fechamento do arquivo.\n");
    }
    else
    {
        printf("-> Arquivo \"%s\" fechado.\n", arquivo_entrada);
    }
    return grafo;
}

int escrita_arquivo_la(GRAFO_LA* grafo, char *arquivo_saida)
{
    int i;
    NO_LA *aux;
    FILE *arquivo;

    arquivo = fopen(arquivo_saida,"w");
    if(arquivo == NULL)
    {
        printf("-> Erro: Falha na criacao do arquivo de saida.\n\n");
        return 0;
    }
    else
    {
        printf("-> Arquivo \"%s\" criado.\n", arquivo_saida);
    }

    fprintf(arquivo, "Vertices = %d\n", grafo->num_vertices);
    for(i = 0; i < grafo->num_vertices; i++)
    {
        aux = grafo->aresta[i];
        while(aux != NULL)
        {
            if(aux->vertice > i)
            {
                fprintf(arquivo,"(%d -> %d = %d, %d, %d, %d)\n",i, aux->vertice, aux->custo, aux->delay, aux->capacidade, aux->trafego);
            }
            aux = aux->proximo;
        }
    }

    return 1;
}

/*Percorrimentos---------------------------------------------------------------------------------*/
/*Dijkstra---------------------------------------------------------------------------------------*/
int pegar_peso_la(GRAFO_LA *grafo, int vertice1, int vertice2, int peso)
{
    NO_LA* aux;

    /*Verificacao dos Parametros de Entrada*/
    if(grafo == NULL)
    {
        printf("-> Erro: Grafo inconsistente.\n");
        return (-1);
    }
    if((vertice1 < 0)||(vertice1 > ((grafo->num_vertices) - 1))||(vertice2 < 0)||(vertice2 > ((grafo->num_vertices) - 1)))
    {
        printf("-> Erro: Vertices invalidos.\n");
        return (-1);
    }
    if(vertice1 == vertice2)
    {
        printf("-> Erro: Vertices iguais, lacos nao sao permitidos.\n");
        return (-1);
    }

    aux = grafo->aresta[vertice1];
    while((aux != NULL)&&(aux->vertice != vertice2))
    {
        aux = aux->proximo;
    }

    if(peso == 1) return aux->custo;
    if(peso == 2) return aux->delay;
    if(peso == 3) return aux->capacidade;
    if(peso == 4) return aux->trafego;

    return 0;
}

int procura_menor_distancia(float *distancias, int *visitados, int num_vertices)
{
    int i, menor = -1, primeiro = 1;
    for(i = 0; i < num_vertices; i++)
    {
        if((distancias[i] >= 0)&&(visitados[i] == 0))
        {
            if(primeiro)
            {
                menor = i;
                primeiro = 0;
            }
            else
            {
                if(distancias[menor] > distancias[i])
                {
                    menor = i;
                }
            }
        }
    }

    return menor;
}

void dijkstra_la_aux(GRAFO_LA *grafo, int origem, int *anteriores, float *distancias, int peso)
{
    int i, contador, num_vertices, indice, *visitado, vertice, adjacente = 0;
    num_vertices = grafo->num_vertices;
    contador = num_vertices;
    visitado = (int*) malloc(num_vertices * sizeof(int));
    for(i = 0; i < num_vertices; i++)
    {
        anteriores[i] = -1;
        distancias[i] = -1;
        visitado[i] = 0;
    }
    distancias[origem] = 0;
    while(contador > 0)
    {

        vertice = procura_menor_distancia(distancias, visitado, num_vertices);
        if(vertice == -1) break;
        visitado[vertice] = 1;
        contador--;
        for(i = 0; i < num_vertices ; i++)
        {
            adjacente = ehAdjacente_la(grafo,vertice,i);
            if(adjacente == 1)
            {
                indice = i;
                if(distancias[indice] < 0)
                {
                    distancias[indice] = distancias[vertice] + pegar_peso_la(grafo, indice, vertice, peso);
                    anteriores[indice] = vertice;
                }
                else if(distancias[indice] > distancias[vertice] + pegar_peso_la(grafo, indice, vertice, peso))
                {
                    distancias[indice] = distancias[vertice] + pegar_peso_la(grafo, indice, vertice, peso);
                    anteriores[indice] = vertice;
                }
            }
        }
    }

    free(visitado);
}

int** dijkstra_la(GRAFO_LA *grafo, int origem, int *receptores, int num_receptores, int peso)
{
    int i, j, aux, n = 0;
    int *anteriores;
    int **caminhos;
    float *distancias;

    anteriores = (int*) malloc(grafo->num_vertices * sizeof(int));
    if(anteriores == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de anteriores.\n");
        return NULL;
    }
    distancias = (float*) malloc(grafo->num_vertices * sizeof(float));
    if(distancias == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de distancias.\n");
        return NULL;
    }

    dijkstra_la_aux(grafo, origem, anteriores, distancias, peso);

    caminhos = (int**) malloc(grafo->num_vertices*sizeof(int*));
    if(caminhos == NULL)
    {
        printf("-> Erro: Falha na alocacao da matriz de caminhos.\n");
        return NULL;
    }
    for(i = 0; i < grafo->num_vertices; i++)
    {
        caminhos[i] = (int*) malloc(grafo->num_vertices * sizeof(int));
        if(caminhos[i] == NULL)
        {
            printf("-> Erro: Falha na alocacao de um dos vetores da matriz.\n");
            return NULL;
        }
    }

    for(i = 0; i < grafo->num_vertices; i++)
    {
        for(j = 0; j < grafo->num_vertices; j++)
        {
            caminhos[i][j] = -1;
        }
    }

    for(i = 0; i < num_receptores; i++)
    {
        aux = receptores[i];
        while(aux != -1)
        {
            n++;
            aux = anteriores[aux];
        }
        aux = receptores[i];
        while(aux >= 0)
        {
            caminhos[receptores[i]][n-1] = aux;
            n--;
            aux = anteriores[aux];
        }
    }

    return caminhos;
}

/*Profundidade-----------------------------------------------------------------------------------*/
void busca_profundidade_aux(GRAFO_LA* grafo, int vertice1, int vertice2, int* visitados, int* caminho, int* controle, int* parada)
{
    visitados[vertice1] = 1;
    caminho[*controle] = vertice1;
    (*controle)++;
    NO_LA* aux = (NO_LA*)malloc(sizeof(NO_LA));
    aux = grafo->aresta[vertice1];
    while((aux != NULL) && (*parada != 1))
    {
        if(visitados[aux->vertice] == 0)
        {
            if(aux->vertice == vertice2)
            {
                caminho[*controle] = aux->vertice;
                *parada = 1;
            }
            else
            {
                busca_profundidade_aux(grafo,aux->vertice,vertice2,visitados,caminho,controle,parada);
            }
        }
        else
        {
            aux = aux->proximo;
            if(aux != NULL)
            {
                if(aux->vertice == vertice2)
                {
                    caminho[*controle] = aux->vertice;
                    (*parada) = 1;
                }
            }
        }
    }

    if(aux == NULL)
    {
        caminho[*controle] = 0;
        (*controle)--;
    }
}

int** busca_profundidade(GRAFO_LA *grafo, int origem, int *receptores, int num_receptores)
{
    int i, j, controle = 0, parada = 0;
    int *visitados;
    int **caminhos;

    visitados = (int*) calloc(grafo->num_vertices, sizeof(int));
    if(visitados == NULL)
    {
        printf("-> Erro: Falha na alocacao do vetor de visitados na busca em profundidade");
        return NULL;
    }
    caminhos = (int**) malloc(grafo->num_vertices*sizeof(int*));
    if(caminhos == NULL)
    {
        printf("-> Erro: Falha na alocacao da matriz de caminhos.\n");
        return NULL;
    }
    for(i = 0; i < grafo->num_vertices; i++)
    {
        caminhos[i] = (int*) malloc(grafo->num_vertices * sizeof(int));
        if(caminhos[i] == NULL)
        {
            printf("-> Erro: Falha na alocacao de um dos vetores da matriz.\n");
            return NULL;
        }
    }

    for(i = 0; i < grafo->num_vertices; i++)
    {
        for(j = 0; j < grafo->num_vertices; j++)
        {
            caminhos[i][j] = -1;
        }
    }

    for(i = 0; i < num_receptores; i++)
    {
        busca_profundidade_aux(grafo, origem, receptores[i], visitados, caminhos[receptores[i]], &controle, &parada);
        controle = 0;
        parada = 0;
        for(j = 0; j < grafo->num_vertices; j++)
        {
            visitados[j] = 0;
        }
    }

    return caminhos;
}

/*Metricas---------------------------------------------------------------------------------------------------------*/
int custo_total_la(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento)
{
    int i, vertice1, vertice2, aux = 0, peso_retorno = 0;
    int **caminhos, **pesos;
    if(grafo == NULL)
    {
        printf("->Erro: Grafo inconsistente.\n");
        return -1;
    }
    if((percorrimento != 1)&&(percorrimento != 2))
    {
        printf("->Erro: Percorrimento invalido.\n");
        return -1;
    }
    if(num_receptores <= 0)
    {
        printf("Erro: Numero de receptores invalido.\n");
        return -1;
    }
    if(percorrimento == 1)
    {
        caminhos = busca_profundidade(grafo, origem, receptores, num_receptores);
    }
    if(percorrimento == 2)
    {
        caminhos = dijkstra_la(grafo, origem, receptores, num_receptores, 1); //ultimo argumento -> peso = 1 -> custo
    }

    pesos = (int**) malloc(grafo->num_vertices*sizeof(int*));
    if(pesos == NULL)
    {
        printf("-> Erro: Falha na alocacao da matriz de pesos.\n");
        return -1;
    }
    for(i = 0; i < grafo->num_vertices; i++)
    {
        pesos[i] = (int*) calloc(grafo->num_vertices, sizeof(int));
        if(pesos[i] == NULL)
        {
            printf("-> Erro: Falha na alocacao de um dos vetores da matriz de pesos.\n");
            return -1;
        }
    }

    for(i = 0; i < grafo->num_vertices; i++)
    {
        vertice1 = caminhos[i][aux];
        while((caminhos[i][aux] != i)&&(caminhos[i][aux] != -1))
        {
            vertice2 = vertice1;
            aux++;
            vertice1 = caminhos[i][aux];
            if(pesos[vertice1][vertice2] == 0)
            {
                pesos[vertice1][vertice2] = 1;
                pesos[vertice2][vertice1] = 1;
                peso_retorno = peso_retorno + pegar_peso_la(grafo, vertice1, vertice2,1);
            }
        }
        aux = 0;
    }

    return peso_retorno;
}

int delay_maximo_la(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento)
{
    int i, aux = 0, vertice1, vertice2, peso_retorno = 0, maior = -1;
    int **caminhos;

    if(grafo == NULL)
    {
        printf("->Erro: Grafo inconsistente.\n");
        return -1;
    }
    if((percorrimento != 1)&&(percorrimento != 2))
    {
        printf("->Erro: Percorrimento invalido.\n");
        return -1;
    }
    if(num_receptores <= 0)
    {
        printf("Erro: Numero de receptores invalido.\n");
        return -1;
    }
    if(percorrimento == 1)
    {
        caminhos = busca_profundidade(grafo, origem, receptores, num_receptores);
    }
    if(percorrimento == 2)
    {
        caminhos = dijkstra_la(grafo, origem, receptores, num_receptores, 2); //ultimo argumento -> peso = 1 -> custo
    }

    for(i = 0; i < grafo->num_vertices; i++)
    {
        vertice1 = caminhos[i][aux];
        while((caminhos[i][aux] != i)&&(caminhos[i][aux] != -1))
        {
            vertice2 = vertice1;
            aux++;
            vertice1 = caminhos[i][aux];
            peso_retorno = peso_retorno + pegar_peso_la(grafo, vertice1, vertice2,2);
        }
        if(peso_retorno > maior)
        {
            maior = peso_retorno;
        }
        peso_retorno = 0;
        aux = 0;
    }

    return maior;
}

float utilizacao_maxima_enlace(GRAFO_LA *grafo, int origem, int* receptores, int num_receptores, int percorrimento, float tam_mensagem)
{
    int i, aux = 0, vertice1, vertice2;
    float peso_retorno = 0, maior = -1;
    int **caminhos;

    if(grafo == NULL)
    {
        printf("->Erro: Grafo inconsistente.\n");
        return -1;
    }
    if((percorrimento != 1)&&(percorrimento != 2))
    {
        printf("->Erro: Percorrimento invalido.\n");
        return -1;
    }
    if(num_receptores <= 0)
    {
        printf("Erro: Numero de receptores invalido.\n");
        return -1;
    }
    if(percorrimento == 1)
    {
        caminhos = busca_profundidade(grafo, origem, receptores, num_receptores);
    }
    if(percorrimento == 2)
    {
        caminhos = dijkstra_la(grafo, origem, receptores, num_receptores, 3); //ultimo argumento -> peso = 1 -> custo
    }

    for(i = 0; i < grafo->num_vertices; i++)
    {
        vertice1 = caminhos[i][aux];
        while((caminhos[i][aux] != i)&&(caminhos[i][aux] != -1))
        {
            vertice2 = vertice1;
            aux++;
            vertice1 = caminhos[i][aux];
            peso_retorno = peso_retorno + ((pegar_peso_la(grafo, vertice1, vertice2,4)+tam_mensagem)/(pegar_peso_la(grafo, vertice1, vertice2,3)));
        }
        if(peso_retorno > maior)
        {
            maior = peso_retorno;
        }
        peso_retorno = 0;
        aux = 0;
    }

    return maior;
}

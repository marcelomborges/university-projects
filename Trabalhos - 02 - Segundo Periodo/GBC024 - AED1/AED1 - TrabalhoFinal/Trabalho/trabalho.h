#ifndef TRABALHO_H_INCLUDED
#define TRABALHO_H_INCLUDED

/*Definicao de Estruturas*/
typedef struct posicao POSICAO;
typedef struct elemento ELEMENTO;
typedef struct pilha PILHA;

typedef struct posicao
{
    int linha;
    int coluna;
}
POSICAO;

typedef struct elemento
{
    POSICAO *posicao;
    ELEMENTO *proximo;
}ELEMENTO;

typedef struct pilha
{
    int quantidade;
    ELEMENTO *primeiro;
    ELEMENTO *ultimo;
}PILHA;

/*Funcoes de criacao do labirinto*/
void imprime_labirinto(int **labirinto, int linhas, int colunas);
POSICAO desenvolve_labirinto(int **labirinto, int ordem);
void gera_caminho(int **labirinto, int ordem, int linha, int coluna, int tamanho);
int verifica_posicao(int **labirinto, int ordem, int linha, int coluna);

/*Funcoes do tipo abstrato de dados "pilha"*/
void inicia_pilha(PILHA *pilha);
void insere_elemento_pilha(PILHA *pilha, POSICAO *posicao);
POSICAO* remove_elemento_pilha(PILHA *pilha);

/*Funcoes de resolucao do labirinto*/
void resolve_labirinto(int **labirinto, int ordem, POSICAO *posicao_inicial);
int verifica_arredores(int **labirinto, int ordem, int linha, int coluna);
POSICAO* realiza_movimento(int **labirinto, int ordem, int linha, int coluna);
int avalia_final(int **labirinto, int ordem, int linha, int coluna);

#endif // TRABALHO_H_INCLUDED

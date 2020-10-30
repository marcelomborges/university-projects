#ifndef ARVORE_AVL_H_INCLUDED
#define ARVORE_AVL_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct registro REGISTRO;
struct registro
{
    int trafego;
    int identificador;
    int capacidade;
    char localizacao[100];
};

typedef struct no NO;
struct no
{
    REGISTRO info;
    NO* sae;
    NO* sad;
    int fb;
};

typedef struct no* ARVORE_AVL;

/*Declaracao de Prototipos de Funcoes*/
ARVORE_AVL cria_arvore_avl();
int arvore_avl_vazia(ARVORE_AVL *arvore);
ARVORE_AVL busca_binaria_arvore_avl(ARVORE_AVL arvore, int trafego);
void exibe_arvore_avl(ARVORE_AVL arvore);
void exibe_ordenado_arvore_avl(ARVORE_AVL arvore);
void libera_arvore_avl(ARVORE_AVL *arvore);

int rotacao_direita(ARVORE_AVL *arvore);
int rotacao_esquerda(ARVORE_AVL *arvore);
int rotacao_direita_esquerda(ARVORE_AVL *pai);
int rotacao_esquerda_direita(ARVORE_AVL *pai);
int balancear_esquerda(ARVORE_AVL *arvore);
int balancear_direita(ARVORE_AVL *arvore);
int insere_AVL(ARVORE_AVL *arvore, REGISTRO elemento, int *verificador);

REGISTRO* menor_trafego(ARVORE_AVL arvore);
int qtde_ocioso(ARVORE_AVL arvore);
int nro_folha(ARVORE_AVL arvore);
int altura_arvore_avl(ARVORE_AVL arvore);
int quantidade_nos_arvore_avl(ARVORE_AVL arvore);
int cheia(ARVORE_AVL arvore);
int nivel_no(ARVORE_AVL arvore, REGISTRO elemento);
int iguais(ARVORE_AVL arvore1, ARVORE_AVL arvore2);

#endif // ARVORE_AVL_H_INCLUDED

#ifndef ARVORE_BB_H_INCLUDED
#define ARVORE_BB_H_INCLUDED

/*Declaracao de Estruturas*/
typedef struct registro REGISTRO;
struct registro
{
    int idade;
    char nome[100];
    char curso[100];
};

typedef struct no NO;
struct no
{
    REGISTRO info;
    NO* sae;
    NO* sad;
};

typedef struct no* ARVORE_BB;

/*Declaracao de Prototipos de Funcoes*/
ARVORE_BB cria_arvore_bb();
int arvore_bb_vazia(ARVORE_BB *arvore);
void libera_arvore_bb(ARVORE_BB *arvore);
void exibe_arvore_bb(ARVORE_BB arvore);
void exibe_ordenado_arvore_bb(ARVORE_BB arvore);
int insere_ordenado_arvore_bb(ARVORE_BB *arvore, REGISTRO elemento);
int remove_ordenado_arvore_bb(ARVORE_BB *arvore, int idade);
ARVORE_BB busca_binaria_arvore_bb(ARVORE_BB arvore, int idade);
void imprime_arvore_bb(ARVORE_BB arvore);
void imprime_ordenado_arvore_bb(ARVORE_BB arvore);

REGISTRO* maior(ARVORE_BB arvore);
int de_maior(ARVORE_BB arvore);
int qtde_nos_abb(ARVORE_BB arvore, int ini, int fim);
int um_filho(ARVORE_BB arvore);
int verifica_numero_filhos(ARVORE_BB arvore);
int completa(ARVORE_BB arvore);
int altura_arv(ARVORE_BB arvore);
ARVORE_BB juntar(ARVORE_BB arvore1, ARVORE_BB arvore2);
void imprime_cabecalho_1();
void imprime_cabecalho_2();

#endif // ARVORE_BB_H_INCLUDED

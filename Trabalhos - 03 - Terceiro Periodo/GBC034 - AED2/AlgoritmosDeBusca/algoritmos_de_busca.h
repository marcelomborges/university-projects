#ifndef ALGORITMOS_DE_BUSCA_H_INCLUDED
#define ALGORITMOS_DE_BUSCA_H_INCLUDED

/*Definicao de Valores*/
#define MAXIMO 10

/*Declaracao de Estruturas*/
typedef struct registro REGISTRO;
struct registro
{
    int chave;
    char nome[100];
};

typedef struct arquivo ARQUIVO;
struct arquivo
{
    int tamanho;
    /*REGISTRO itens[MAXIMO];  Para busca sem sentinela*/
    REGISTRO itens[MAXIMO+1];/*Para busca com sentinela*/
};

/*Prototipos de Funcoes*/
ARQUIVO* inicia_arquivo();
int insere_registro(ARQUIVO *arquivo, REGISTRO elemento);
int remove_registro(ARQUIVO *arquivo, int chave);
void imprime_arquivo(ARQUIVO *arquivo);
int busca_sequencial(ARQUIVO *arquivo, int chave);
int busca_sequencial_sentinela(ARQUIVO *arquivo, int chave);
int busca_sequencial_ordenada(ARQUIVO *arquivo, int chave);
int busca_binaria(ARQUIVO *arquivo, int chave);

#endif // ALGORITMOS_DE_BUSCA_H_INCLUDED

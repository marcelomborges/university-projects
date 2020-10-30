/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_de_busca.h"

/*Definicao de Funcoes*/
ARQUIVO* inicia_arquivo()
{
    ARQUIVO *arquivo = (ARQUIVO*) malloc(sizeof(ARQUIVO));
    if(arquivo == NULL)
    {
        printf("Erro: Falha na alocacao do arquivo na funcao \"inicia_arquivo\".\n");
        return NULL;
    }

    arquivo->tamanho = 0;

    return arquivo;
}

int insere_registro(ARQUIVO *arquivo, REGISTRO elemento)
{
    if(arquivo->tamanho == MAXIMO)
    {
        printf("Erro: Arquivo cheio na funcao \"insere_registro\".\n");
        return 0;
    }

    arquivo->itens[arquivo->tamanho] = elemento;
    arquivo->tamanho++;
    return 1;
}

int remove_registro(ARQUIVO *arquivo, int chave)
{
    int i, posicao;

    if(arquivo->tamanho == 0)
    {
        printf("Erro: Arquivo vazio na funcao \"remove_registro\".\n");
        return 0;
    }

    posicao = busca_binaria(arquivo, chave);

    for(i = posicao; i < arquivo->tamanho; i++)
    {
        arquivo->itens[i] = arquivo->itens[i+1];
    }

    arquivo->tamanho--;
    return 1;
}

void imprime_arquivo(ARQUIVO *arquivo)
{
    int i;

    printf("Arquivo:----------------------\n\n");

    for(i = 0; i < arquivo->tamanho; i++)
    {
        printf("Chave: %d\n", arquivo->itens[i].chave);
        printf("Nome: %s\n\n", arquivo->itens[i].nome);
    }

    printf("------------------------------\n\n");
}

int busca_sequencial(ARQUIVO *arquivo, int chave)
{
    int posicao = 0;

    if(arquivo->tamanho == 0)
    {
        printf("Erro: Arquivo vazio na funcao \"busca_sequencial\".\n");
        return (-1);
    }

    while((posicao < arquivo->tamanho)&&(arquivo->itens[posicao].chave != chave))
    {
        posicao++;
    }

    if(posicao == arquivo->tamanho)
    {
        printf("Elemento nao encontrado na \"busca_sequencial\".\n");
        return (-1);
    }

    return posicao;
}

int busca_sequencial_sentinela(ARQUIVO *arquivo, int chave)
{
    int posicao = 0;

    if(arquivo->tamanho == 0)
    {
        printf("Erro: Arquivo vazio na funcao \"busca_sequencial_sentinela\".\n");
        return (-1);
    }

    arquivo->itens[arquivo->tamanho].chave = chave;

    while(arquivo->itens[posicao].chave != chave)
    {
        posicao++;
    }

    if(posicao == arquivo->tamanho)
    {
        printf("Elemento nao encontrado na \"busca_sequencial_sentinela\".\n");
        return (-1);
    }

    return posicao;
}

int busca_sequencial_ordenada(ARQUIVO *arquivo, int chave)
{
    int posicao = 0;

    if((arquivo->tamanho == 0)||(arquivo->itens[posicao].chave > chave)||(arquivo->itens[arquivo->tamanho - 1].chave < chave))
    {
        printf("Erro: Arquivo vazio na funcao \"busca_sequencial_ordenada\".\n");
        return (-1);
    }

    while(arquivo->itens[posicao].chave < chave)
    {
        posicao++;
    }

    if(arquivo->itens[posicao].chave > chave)
    {
        printf("Elemento nao encontrado na \"busca_sequencial_ordenada\".\n");
        return (-1);
    }

    return posicao;
}

int busca_binaria(ARQUIVO *arquivo, int chave)
{
    int inicio, meio, fim;

    if(arquivo->tamanho == 0)
    {
        printf("Erro: Arquivo vazio na funcao \"busca_binaria\".\n");
        return (-1);
    }

    inicio = 0;
    fim = arquivo->tamanho-1;

    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;
        if(arquivo->itens[meio].chave == chave)
        {
            return meio;
        }
        else if(arquivo->itens[meio].chave > chave)
        {
            fim = meio-1;
        }
        else
        {
            inicio = meio+1;
        }
    }

    printf("Elemento nao encontrado na \"busca_binaria\".\n");
    return (-1);
}

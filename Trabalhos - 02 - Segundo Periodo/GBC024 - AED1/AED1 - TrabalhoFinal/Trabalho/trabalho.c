/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "trabalho.h"

/*Funcoes de criacao do labirinto--------------------------------------------------------------------------------------------------*/
void imprime_labirinto(int **labirinto, int linhas, int colunas)
{
    int i, j;

    /*Estrutura exterior da matriz*/
    printf("LBR|");

    for(j = 0; j < colunas; j++)
    {
        printf(" %2d ",j);
    }
    printf("\n");

    for(i = 0; i < (colunas * 4) + 4; i++)
    {
        if(i == 3) printf("|");
        else printf("-");
    }
    printf("\n");


    for(i = 0; i < linhas; i++)
    {
        printf("%2d |",i);/*Parte da estrutura exterior da matriz*/
        for(j = 0; j < colunas; j++)
        {
            if(labirinto[i][j] == 9) printf("  - ");
            else printf(" %2d ", labirinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

POSICAO desenvolve_labirinto(int **labirinto, int ordem)
{
    int quantidade, tamanho;
    int linha_inicial, coluna_inicial;
    int linha_auxiliar, coluna_auxiliar;
    POSICAO primeira_posicao;

    srand(time(NULL));

    /*Define o inicio do labirinto*/
    linha_inicial = 0;
    coluna_inicial = rand() % ordem;
    printf("Posicao Inicial = (%d,%d)\n", linha_inicial, coluna_inicial);

    /*Gera o caminho principal*/
    gera_caminho(labirinto, ordem, linha_inicial, coluna_inicial, -1);

    /*Gerando caminhos aleatorios*/
    for(linha_auxiliar = 0; linha_auxiliar < ordem; linha_auxiliar++)
    {
        for(coluna_auxiliar = 0; coluna_auxiliar < ordem; coluna_auxiliar++)
        {
            if(labirinto[linha_auxiliar][coluna_auxiliar] == 0)
            {
                /*Tamanho dos caminhos aleatorios*/
                tamanho = (rand() % ordem) + 1;

                gera_caminho(labirinto, ordem, linha_auxiliar, coluna_auxiliar, tamanho);
            }
        }
    }

    /*Marcando a primeira posicao*/
    labirinto[linha_inicial][coluna_inicial] = 1;
    primeira_posicao.linha = linha_inicial;
    primeira_posicao.coluna = coluna_inicial;

    return primeira_posicao;
}

void gera_caminho(int **labirinto, int ordem, int linha, int coluna, int tamanho)
{
    int movimento, teste, travou = 0, tamanho_aux = tamanho;
    int linha_atual, coluna_atual;
    int nova_linha, nova_coluna;
    int cima = 0, baixo = 0, esquerda = 0, direita = 0;

    srand(time(NULL));

    linha_atual = linha;
    coluna_atual = coluna;
    labirinto[linha_atual][coluna_atual] = 0;

    do
    {
        movimento = rand() % 4;

        if(movimento == 0)
        {
            /*Tentativa de ir para cima*/
            nova_linha = linha_atual - 1;
            nova_coluna = coluna_atual;
            cima = 1;

            if(tamanho == -1) teste = 0;
            else teste = verifica_posicao(labirinto, ordem, nova_linha, nova_coluna);

            if(teste == 1)
            {
                linha_atual = nova_linha;
                coluna_atual = nova_coluna;
                labirinto[linha_atual][coluna_atual] = 0;

                tamanho_aux--;
                cima = 0;
            }
        }
        else if(movimento == 1)
        {
            /*Tentativa de ir para direita*/
            nova_linha = linha_atual;
            nova_coluna = coluna_atual + 1;
            direita = 1;

            teste = verifica_posicao(labirinto, ordem, nova_linha, nova_coluna);

            if(teste == 1)
            {
                linha_atual = nova_linha;
                coluna_atual = nova_coluna;
                labirinto[linha_atual][coluna_atual] = 0;

                tamanho_aux--;
                direita = 0;
            }
        }
        else if(movimento == 2)
        {
            /*Tentativa de ir para baixo*/
            nova_linha = linha_atual + 1;
            nova_coluna = coluna_atual;
            baixo = 1;

            teste = verifica_posicao(labirinto, ordem, nova_linha, nova_coluna);

            if(teste == 1)
            {
                linha_atual = nova_linha;
                coluna_atual = nova_coluna;
                labirinto[linha_atual][coluna_atual] = 0;

                tamanho_aux--;
                baixo = 0;
            }
        }
        else if(movimento == 3)
        {
            /*Tentativa de ir para esquerda*/
            nova_linha = linha_atual;
            nova_coluna = coluna_atual - 1;
            esquerda = 1;

            teste = verifica_posicao(labirinto, ordem, nova_linha, nova_coluna);

            if(teste == 1)
            {
                linha_atual = nova_linha;
                coluna_atual = nova_coluna;
                labirinto[linha_atual][coluna_atual] = 0;

                tamanho_aux--;
                esquerda = 0;
            }
        }

        /*Verifica se o programa testou todas as possibilidades e travou*/
        if( (cima == 1)&&(baixo == 1)&&(esquerda == 1)&&(direita == 1) )
        {
            travou = 1;
        }
    }
    while( (linha_atual != (ordem - 1)) && (tamanho_aux != 0) && (travou == 0) );

    if(tamanho == -1)
    {
        labirinto[linha_atual][coluna_atual] = 2;
        printf("Posicao Final = (%d,%d)\n\n", linha_atual, coluna_atual);
    }
}

int verifica_posicao(int **labirinto, int ordem, int linha, int coluna)
{
    int cont = 0;

    if((linha < 0)||(linha >= ordem)) return -1;
    if((coluna < 0)||(coluna >= ordem)) return -1;
    if((labirinto[linha][coluna] == 0)||(labirinto[linha][coluna] == 1)||(labirinto[linha][coluna] == 2)) return -1;

    /*Testa posicao de cima*/
    if( ((linha - 1) >= 0) && ((labirinto[linha - 1][coluna] == 0) || (labirinto[linha - 1][coluna] == 2)) ) cont++;

    /*Testa posicao da direita*/
    if( ((coluna + 1) < ordem) && ((labirinto[linha][coluna + 1] == 0) || (labirinto[linha][coluna + 1] == 2)) ) cont++;

    /*Testa posicao de baixo*/
    if( ((linha + 1) < ordem) && ((labirinto[linha + 1][coluna] == 0) || (labirinto[linha + 1][coluna] == 2)) ) cont++;

    /*Testa posicao da esquerda*/
    if( ((coluna - 1) >= 0) && ((labirinto[linha][coluna - 1] == 0) || (labirinto[linha][coluna - 1] == 2)) ) cont++;

    /*verifica situacao da posicao*/
    if(cont == 1) return 1;
    else return -1;
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
/*Funcoes do tipo abstrato de dados "pilha"----------------------------------------------------------------------------------------*/
void inicia_pilha(PILHA *pilha)
{
    pilha->quantidade = 0;
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
}

void insere_elemento_pilha(PILHA *pilha, POSICAO *posicao)
{
    ELEMENTO *elemento;

    elemento = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    if(elemento == NULL)
    {
        printf("--> Erro na alocacao do elemento.\n");
        return 1;
    }

    elemento->posicao = posicao;

    if(pilha->quantidade == 0)
    {
        elemento->proximo = NULL;
        pilha->primeiro = elemento;
        pilha->ultimo = elemento;
        pilha->quantidade++;
    }
    else
    {
        elemento->proximo = pilha->primeiro;
        pilha->primeiro = elemento;
        pilha->quantidade++;
    }
}

POSICAO* remove_elemento_pilha(PILHA *pilha)
{
    ELEMENTO *elemento;

    if(pilha->quantidade == 0)
    {
        printf("--> Lista vazia, impossivel retornar elemento.\n");
        return NULL;
    }
    else if(pilha->quantidade == 1)
    {
        elemento = pilha->primeiro;
        pilha->primeiro = NULL;
        pilha->ultimo = NULL;
        pilha->quantidade--;
    }
    else
    {
        elemento = pilha->primeiro;
        pilha->primeiro = pilha->primeiro->proximo;
        pilha->quantidade--;
    }

    return elemento->posicao;
}
/*Funcoes do tipo abstrato de dados "pilha"*/

/*---------------------------------------------------------------------------------------------------------------------------------*/
/*Funcoes de resolucao do labirinto------------------------------------------------------------------------------------------------*/
void resolve_labirinto(int **labirinto, int ordem, POSICAO *posicao_inicial)
{
    int fim = 0, possibilidades;
    int linha_atual, coluna_atual;
    int nova_linha, nova_coluna;
    POSICAO *posicao_aux;
    PILHA *pilha_aux;

    posicao_aux = (POSICAO*) malloc(sizeof(POSICAO));
    if(posicao_aux == NULL)
    {
        printf("--> Erro na alocacao da posicao.\n");
        exit(1);
    }
    pilha_aux = (PILHA*) malloc(sizeof(PILHA));
    if(pilha_aux == NULL)
    {
        printf("--> Erro na alocacao da pilha.\n");
        exit(1);
    }

    linha_atual = posicao_inicial->linha;
    coluna_atual = posicao_inicial->coluna;

    while(fim != 1)
    {
        system("PAUSE");
        system("CLS");
        printf("\nLabirinto:\n");

        /*Contabilizando quantidade de possibilidades de se mover*/
        possibilidades = verifica_arredores(labirinto, ordem, linha_atual, coluna_atual);

        if(possibilidades == 0)
        {
            /*Realiza backtracking*/
            posicao_aux = remove_elemento_pilha(pilha_aux);
            linha_atual = posicao_aux->linha;
            coluna_atual = posicao_aux->coluna;
            printf("\n--> Backtracking para: (%d,%d)\n", linha_atual, coluna_atual);
        }
        else if(possibilidades == 1)
        {
            /*Realiza movimento trocando os valores 0 para 1*/
            posicao_aux = realiza_movimento(labirinto, ordem, linha_atual, coluna_atual);
            linha_atual = posicao_aux->linha;
            coluna_atual = posicao_aux->coluna;
        }
        else if(possibilidades > 1)
        {
            posicao_aux->linha = linha_atual;
            posicao_aux->coluna = coluna_atual;
            insere_elemento_pilha(pilha_aux, posicao_aux);
            posicao_aux = realiza_movimento(labirinto, ordem, linha_atual, coluna_atual);
            linha_atual = posicao_aux->linha;
            coluna_atual = posicao_aux->coluna;
        }
        fim = avalia_final(labirinto, ordem, linha_atual, coluna_atual);

        printf("\nPosicao inicial: (%d,%d)\n", posicao_inicial->linha, posicao_inicial->coluna);
        printf("Posicao atual: (%d,%d)\n\n", linha_atual, coluna_atual);
        imprime_labirinto(labirinto, ordem, ordem);
    }

    printf("--> Fim do labirinto encontrado.\a\n");

    /*Desalocando o que foi alocado dinamicamente*/
    free(posicao_aux);
    free(pilha_aux);
}

int verifica_arredores(int **labirinto, int ordem, int linha, int coluna)
{
    int cont = 0;

    /*Testa posicao de cima*/
    if(((linha - 1) >= 0) && (labirinto[linha - 1][coluna] == 0)) cont++;

    /*Testa posicao da direita*/
    if(((coluna + 1) < ordem) && (labirinto[linha][coluna + 1] == 0)) cont++;

    /*Testa posicao de baixo*/
    if(((linha + 1) < ordem) && (labirinto[linha + 1][coluna] == 0)) cont++;

    /*Testa posicao da esquerda*/
    if(((coluna - 1) >= 0) && (labirinto[linha][coluna - 1] == 0))  cont++;

    return cont;
}

POSICAO* realiza_movimento(int **labirinto, int ordem, int linha, int coluna)
{
    POSICAO *posicao;

    posicao = (POSICAO*) malloc(sizeof(POSICAO));
    if(posicao == NULL)
    {
        printf("-->Erro na alocacao da posicao.\n");
        exit(1);
    }

    /*Move para a posicao de cima*/
    if(((linha - 1) >= 0) && (labirinto[linha - 1][coluna] == 0))
    {
        posicao->linha = linha - 1;
        posicao->coluna = coluna;
        labirinto[linha - 1][coluna] = 1;
    }
    /*Move para a posicao da direita*/
    else if(((coluna + 1) < ordem) && (labirinto[linha][coluna + 1] == 0))
    {
        posicao->linha = linha;
        posicao->coluna = coluna + 1;
        labirinto[linha][coluna + 1] = 1;
    }
    /*Move para a posicao de baixo*/
    else if(((linha + 1) < ordem) && (labirinto[linha + 1][coluna] == 0))
    {
        posicao->linha = linha + 1;
        posicao->coluna = coluna;
        labirinto[linha + 1][coluna] = 1;
    }
    /*Move para a posicao da esquerda*/
    else if(((coluna - 1) >= 0) && (labirinto[linha][coluna - 1] == 0))
    {
        posicao->linha = linha;
        posicao->coluna = coluna - 1;
        labirinto[linha][coluna - 1] = 1;
    }

    return posicao;
}

int avalia_final(int **labirinto, int ordem, int linha, int coluna)
{
    int cont = 0;
    /*Testa posicao de cima*/
    if(((linha - 1) >= 0) && (labirinto[linha - 1][coluna] == 2)) cont++;

    /*Testa posicao da direita*/
    if(((coluna + 1) < ordem) && (labirinto[linha][coluna + 1] == 2)) cont++;

    /*Testa posicao de baixo*/
    if(((linha + 1) < ordem) && (labirinto[linha + 1][coluna] == 2)) cont++;

    /*Testa posicao da esquerda*/
    if(((coluna - 1) >= 0) && (labirinto[linha][coluna - 1] == 2))  cont++;

    if(cont > 0) return 1;
    else return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
Programa: Laboratorio 08 Exercicio 5
Aluno: Marcelo Mendonca Borges
Data: 28/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definicoes*/
#define NMAXALUNOS	50
#define TAMMAXNOME	30
#define NNOTAS		4

/*Definicao de Estruturas*/
typedef  struct aluno
{
    char nome[TAMMAXNOME];
    float nota[NNOTAS];
    float media;
} Aluno;

/*Declaracao de Funcoes*/
int  MostrarMenu();
void LimparPlanilha(Aluno *cad);
void CadastrarAlunos(Aluno *cad, int* NAlunos );
void RegistrarNotas(Aluno *cad, int NAlunos);
void MostrarRelatorio(Aluno *cad, int NAlunos);
void CalcularMedias(Aluno *cad, int NAlunos);

int main(int argc, char *argv[])
{
    Aluno cadastro[NMAXALUNOS];
    int op, QAlunos = 0;

    LimparPlanilha(cadastro);

    do
    {
        op = MostrarMenu();
        switch (op)
        {
        case 1:
            CadastrarAlunos(cadastro,&QAlunos);
            break;
        case 2:
            RegistrarNotas(cadastro,QAlunos);
            break;
        case 3:
            CalcularMedias(cadastro,QAlunos);
            break;
        case 4:
            MostrarRelatorio(cadastro,QAlunos);
            break;
        case 5:
            printf("\nSaindo.....\n");
            break;
        default :
            printf("\nError.....Opcao desconhecida\n");
            system("PAUSE");
            break;
        }
    }
    while(op!=5);

    return 0;
}

int MostrarMenu()
{
    int op;
    system("cls");
    printf("Menu de Funcionalidades\n");
    printf("[1]. Cadastrar Alunos\n");
    printf("[2]. Registrar Notas\n");
    printf("[3]. Calcular Medias\n");
    printf("[4]. Mostrar Relatorio\n");
    printf("[5]. Sair\n");
    printf("\nEscolha a operacao ---> ");
    scanf("%d",&op);
    getchar();
    return op;
}

void LimparPlanilha(Aluno *cad)
{
    int i, j;
    for(i=0; i<NMAXALUNOS; i++)
    {
        strcpy(cad[i].nome,"");
        for(j=0; j<NNOTAS+1; j++) cad[i].nota[j]=0.0;
    }
}

void CadastrarAlunos(Aluno *cad, int *NAlunos)
{
    int pos = *NAlunos;
    int i, n;

    do
    {
        printf("\nDigite o numero de alunos que serao cadastrados: ");
        scanf("%d",&n);
    }
    while((n < 0)||(n > 30));
    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("Digite o nome do aluno %d:\n",pos + 1);
        fflush(stdin);
        gets(cad[pos].nome);
        fflush(stdin);
        printf("\n");
        pos++;
    }

    *NAlunos = pos;

    system("PAUSE");
}

void RegistrarNotas(Aluno *cad,int NAlunos)
{
    int i, j;

    for(i = 0; i < NAlunos; i++)
    {
        printf("Digite as notas do aluno %s:\n",cad[i].nome);
        for(j = 0; j < NNOTAS; j++)
        {
            printf("Nota %d: ",j);
            scanf("%f",&cad[i].nota[j]);
        }
        printf("\n");
    }

    system("PAUSE");
}

void MostrarRelatorio(Aluno *cad, int NAlunos)
{
    int i, j;

    printf("%20s %5c NOTA 1 %2c NOTA 2 %2c NOTA 3 %2c NOTA 4 %2c MEDIA\n","NOMES",' ',' ',' ',' ',' ');
    printf("          -------------------------------------------------------------------\n");
    for(i = 0; i < NAlunos; i++)
    {
        printf("%20s  ",cad[i].nome);
        for(j = 0; j < NNOTAS; j++)
        {
            printf("%10.2f",cad[i].nota[j]);

        }
        printf("%10.2f",cad[i].media);
        printf("\n");
    }
    printf("\n");

    system("PAUSE");
}

void CalcularMedias(Aluno *cad, int NAlunos)
{
    int i, j;
    float soma = 0.0;

    for(i = 0; i < NAlunos; i++)
    {
        for(j = 0; j < NNOTAS; j++)
        {
            soma += cad[i].nota[j];
        }
        cad[i].media = soma / 4;
        soma = 0.0;
    }

    printf("\nMedias calculadas ...\n\n");

    system("PAUSE");
}



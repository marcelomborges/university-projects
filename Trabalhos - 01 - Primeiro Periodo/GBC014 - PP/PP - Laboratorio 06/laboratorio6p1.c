/*
Programa: Laboratório 06 Exercicio 1
Aluno: Marcelo Mendonca Borges
Data: 06/05/2016
Descricao:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NMAXALUNOS	50		// Numero Maximo de Alunos
#define TAMMAXNOME	30		// Tamanho Maxino de um nome
#define NNOTAS		4		// Quantidade de Notas


int MostrarMenu();
void LimparPlanilha(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1]);
void CadastrarAlunos(char Nomes[][TAMMAXNOME], int* NAlunos );
void RegistrarNotas(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1], int NAlunos);
void MostrarRelatorio(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1], int NAlunos);
void CalcularMedias(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1], int NAlunos);

int main(int argc, char *argv[])
{
    char Nomes[NMAXALUNOS][TAMMAXNOME];
    float Notas[NMAXALUNOS][NNOTAS+1];
    int op, QAlunos = 0;

	LimparPlanilha(Nomes,Notas);

    do{
        op = MostrarMenu();
        switch (op)
        {
               case 1: CadastrarAlunos(Nomes,&QAlunos);
                       break;
               case 2: RegistrarNotas(Nomes,Notas,QAlunos);
                       break;
               case 3: CalcularMedias(Nomes,Notas,QAlunos);
                       break;
               case 4: MostrarRelatorio(Nomes,Notas,QAlunos);
                       break;
               case 5: printf("\nSaindo.....\n");
                       break;
               default : printf("\nError.....Opcao desconhecida\n\n");
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

void LimparPlanilha(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1])
{
	int i, j;
    for(i=0;i<NMAXALUNOS;i++) {
        strcpy(Nomes[i],"");
        for(j=0;j<NNOTAS+1;j++) Notas[i][j]=0.0;
    }
}

void CadastrarAlunos(char Nomes[][TAMMAXNOME], int *NAlunos)
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
        printf("Digite o nome do aluno %d:\n",i + 1);
        fflush(stdin);
        scanf("%[^\n]",&Nomes[pos]);
        fflush(stdin);
        printf("\n");
        pos++;
    }

    *NAlunos = pos;

    system("PAUSE");
}

void RegistrarNotas(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1],int NAlunos)
{
    int i, j;

    for(i = 0; i < NAlunos; i++)
    {
        printf("Digite as notas do aluno %s:\n",Nomes[i]);
        for(j = 0; j < NNOTAS; j++)
        {
            printf("Notas[%d][%d]: ",i,j);
            scanf("%f",&Notas[i][j]);
        }
        printf("\n");
    }

    system("PAUSE");
}

void MostrarRelatorio(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1], int NAlunos)
{
    int i, j;

    printf("%20s %5c NOTA 1 %2c NOTA 2 %2c NOTA 3 %2c NOTA 4 %2c MEDIA\n","NOMES",' ',' ',' ',' ',' ');
    printf("          -------------------------------------------------------------------\n");
    for(i = 0; i < NAlunos; i++)
    {
        printf("%20s  ",Nomes[i]);
        for(j = 0; j < 5; j++)
        {
            printf("%10.2f",Notas[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    system("PAUSE");
}

void CalcularMedias(char Nomes[][TAMMAXNOME], float Notas[][NNOTAS+1], int NAlunos)
{
    int i, j;
    float soma = 0.0;

    for(i = 0; i < NAlunos; i++)
    {
        for(j = 0; j < NNOTAS; j++)
        {
            soma += Notas[i][j];
        }
        Notas[i][4] = soma / 4;
        soma = 0;
    }

    printf("\nMedias calculadas ...\n\n");

    system("PAUSE");
}






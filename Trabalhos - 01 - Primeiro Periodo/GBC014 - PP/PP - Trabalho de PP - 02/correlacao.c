/*
Programa: Trabalho de PP 02 - Problema 4 (P4)
Alunos: Marcelo Mendonca, Matheus Pimenta, Dalmo Hussid
Data: 12/05/2016
Descricao: Cria uma funcao que calcula correlacao entre dois conjuntos de dados.
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*Prototipos de Funcoes*/
float correlacao(int, int, int, int);

int main ()
{
    /*Declaracao de Variaveis*/
    int i,j;
    float mat[6][5], mediaca = 0, mediagl = 0, mediali = 0,mediapr = 0;
    float somaca = 0, somagl = 0, somali = 0, somapr = 0;
    float inica = 0, inigl = 0, inili = 0, inipr = 0;
    char ali[6][10] = {"Pao","Arroz","Banana","Maca","CouveFlor","Tomate"};
    char tip[4][10] = {"Calorias","Glicidios","Lipidios","Proteinas"};
    char calorias, glicidios, lipidios, proteinas, dado1[2], dado2[2];
    /*-----------------------*/

    printf("Calculo o fator de correlacao entre 2 conjuntos de dados de 4 nutrientes em 6 alimentos diferentes.\n");
    printf("Os alimentos sao: Pao, Arroz, Banana, Maca, CouveFlor, Tomate.\n");
    printf("Os nutrientes sao: Calorias, Glicidios, Lipidios, Proteinas.\n\n");

    for(i=0 ; i < 6; i++)
    {
        for(j=0 ; j < 4; j++)
        {
            printf("Digite a quantidade de %3s para %3s: ", tip[j], ali[i]);
            scanf("%f", &mat[i][j]);
        }
        printf("\n");
    }
    system("CLS");

    for(i=0 ; i < 6; i++)
    {
        somaca  += mat[j][0];
        mediaca = somaca / 6;
    }
    for(i=0 ; i < 6; i++)
    {
        somagl  += mat[j][1];
        mediagl = somagl / 6;
    }
    for(i=0 ; i < 6; i++)
    {
        somali += mat[j][2];
        mediali = somali / 6;
    }
    for(i=0 ; i < 6; i++)
    {
        somapr  += mat[j][3];
        mediapr = somapr / 6;
    }

    inica = mat[0][0];
    inigl = mat[0][1];
    inili = mat[0][2];
    inipr = mat[0][3];

    printf("\t\t\tTabela Nutricional 100g\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("   Alimento           Calorias       Glicidios        Lipidios        Proteinas\n");
    printf("----------------------------------------------------------------------------------\n");

    for(i=0 ; i < 6; i++)
    {
        printf("%10s",ali[i]);
        for(j=0 ; j < 4; j++)
        {
            printf("\t\t%4.1f", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    do
    {
        printf("Primeiro dado a relacionar (C para Caloria ,G para Glicidio, L para Lipidio, P para Proteina): ");
        scanf("%s", dado1);
        fflush(stdin);
        for(i = 0; i < strlen(dado1);i++)
        {
            dado1[i] = toupper(dado1[i]);
        }
        printf("\n");
    }
    while((dado1[0] != 'C') && (dado1[0] != 'G') && (dado1[0] != 'L') && (dado1[0] != 'P'));

    do
    {
        printf("Segundo dado a relacionar (C para Caloria ,G para Glicidio, L para Lipidio, P para Proteina): ");
        scanf("%s", dado2);
        fflush(stdin);
        for(i = 0; i < strlen(dado2);i++)
        {
            dado2[i] = toupper(dado2[i]);
        }
        printf("\n");
    }
    while((dado2[0] != 'C') && (dado2[0] != 'G') && (dado2[0] != 'L') && (dado2[0] != 'P'));

    /*Teste com Caloria*/

    if((strcmp(dado1,"C")== 0) && (strcmp(dado2,"G")==0) || (strcmp(dado1,"G")== 0) && (strcmp(dado2,"C")==0) )
    {
        printf("A correlacao eh : ");
        correlacao(inica,mediaca,inigl,mediagl);
        printf("\n");
    }

    else if((strcmp(dado1,"C")== 0) && (strcmp(dado2,"L")==0) || (strcmp(dado1,"L")== 0) && (strcmp(dado2,"C")==0))
    {
        printf("A correlacao eh : ");
        correlacao(inica,mediaca,inili,mediali);
        printf("\n");
    }

    else if((strcmp(dado1,"C")== 0) && (strcmp(dado2,"P")==0) || (strcmp(dado1,"P")== 0) && (strcmp(dado2,"C")==0))
    {
        printf("A correlacao eh : ");
        correlacao(inica,mediaca,inipr,mediapr);
        printf("\n");
    }


    /*Teste com Glicidio*/

    if((strcmp(dado1,"G")== 0) && (strcmp(dado2,"L")==0) || (strcmp(dado1,"L")== 0) && (strcmp(dado2,"G")==0))
    {
        printf("A correlacao eh : ");
        correlacao(inigl,mediagl,inili,mediali);
        printf("\n");
    }

    else if((strcmp(dado1,"G")== 0) && (strcmp(dado2,"P")==0) || (strcmp(dado1,"P")== 0) && (strcmp(dado2,"G")==0) )
    {
        printf("A correlacao eh : ");
        correlacao(inigl,mediagl,inipr,mediapr);
        printf("\n");
    }


    /*Teste com Lipidio*/
    if((strcmp(dado1,"L")== 0) && (strcmp(dado2,"P")==0) || (strcmp(dado1,"P")== 0) && (strcmp(dado2,"L")==0) )
    {
        printf("A correlacao eh : ");
        correlacao(inili,mediali,inipr,mediapr);
        printf("\n");
    }
    return 0;
}

float correlacao(int inix,int mediax,int iniy,int mediay)
{
    float Sxy=0, Sxx=0, Syy=0, Pxy=0;

    Sxy += (inix - mediax)*(iniy - mediax);
    Sxx +=  (inix * inix) - (2* inix * mediax) + (mediax * mediax);
    Syy += (iniy * iniy) - (2* iniy * mediay) + (mediay * mediay);

    Pxy = ((Sxy)/sqrt(Sxx*Syy));

    printf("%.0f", Pxy);
}






/*
Programa: Trabalho PP 03 - Exercicio 04
Alunos: Lucas Rossi, Marcelo Mendonca, Paulo Renato
Data: 21/06/2016
Descricao: Agenda
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaracao de Estruturas*/
typedef struct data
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct horario
{
    int hora;
    int minuto;
} HORARIO;

typedef struct compromisso
{
    DATA data;
    HORARIO horario;
    char descricao[100];

} COMPROMISSO;

/*Prototipos de Funcoes*/
int cadastrar_compromisso(COMPROMISSO *agenda, int n);
COMPROMISSO pegar_data(char *data);
COMPROMISSO pegar_hora(char *horario);
void ordenar_agenda(COMPROMISSO *agenda, int n);
int compara_compr(COMPROMISSO inicial, COMPROMISSO secundario);

int main ()
{
    /*Declaracao de Variaveis*/
    int i, n = 1, error = 0;
    char opcao[100];
    COMPROMISSO agenda[100];
    FILE *fd;
    /*-----------------------*/

    printf("Construo um cadastro de compromissos em um arquivo de texto (.txt).\n\n");

    if((fd = fopen("agenda.txt","w+")) == NULL)
    {
        printf("\n--> Erro na criacao do arquivo!\n\n");
        exit(1);
    }
    else
    {
        do
        {
            error = cadastrar_compromisso(agenda, n - 1);

            printf("\nDeseja cadastrar um compromisso? (Digite SIM ou NAO (sem acentuacao))\n");
            fflush(stdin);
            gets(opcao);
            fflush(stdin);
            printf("\n");

            for(i = 0; i < strlen(opcao); i++)
            {
                opcao[i] = toupper(opcao[i]);
            }

            while((strcmp(opcao,"NAO") != 0) && (strcmp(opcao,"SIM") != 0)||(strlen(opcao) > 3))
            {
                system("CLS");
                printf("\n--> Opcao desconhecida.\n\n");
                printf("Deseja cadastrar um compromisso? (Digite SIM ou NAO (sem acentuacao))\n");
                fflush(stdin);
                gets(opcao);
                fflush(stdin);
                printf("\n");

                for(i = 0; i < strlen(opcao); i++)
                {
                    opcao[i] = toupper(opcao[i]);
                }
            }
            if(error == 0)
            {
                n++;
            }

        }
        while(strcmp(opcao,"NAO") != 0);

        n--;

        ordenar_agenda(agenda,n);

        fprintf(fd,"|-------------------------------------------------------------------------|\n");
        fprintf(fd,"|-Agenda Ordenada---------------------------------------------------------|\n");
        fprintf(fd,"|------------|---------|--------------------------------------------------|\n");
        fprintf(fd,"|    Data    | Horario |                    Descricao                     |\n");
        fprintf(fd,"|------------|---------|--------------------------------------------------|\n");

        for(i = 0; i < n; i++)
        {
            fprintf(fd,"| %02d/%02d/%04d ",agenda[i].data.dia,agenda[i].data.mes,agenda[i].data.ano);
            fprintf(fd,"|  %02d:%02d  ",agenda[i].horario.hora,agenda[i].horario.minuto);
            fprintf(fd,"| %49s|",agenda[i].descricao);
            fprintf(fd,"\n");
        }

        fprintf(fd,"|------------|---------|--------------------------------------------------|\n");

    }

    fclose(fd);

    return 0;
}

int cadastrar_compromisso(COMPROMISSO *agenda, int n)
{
    COMPROMISSO compr;
    char data[11], horario[6];

    /*DATA--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    do
    {
        printf("Digite a data do compromisso (Formato: dd/mm/aaaa):\n");
        fflush(stdin);
        gets(data);
        fflush(stdin);
        printf("\n");

        if((data[2] != '/')||(data[5] != '/')||(strlen(data) > 10))
        {
            printf("\n--> Formato Incorreto da Data!\n\n");
            return 1;
        }

        compr.data = pegar_data(data).data;

        if(((compr.data.dia <= 0)||(compr.data.dia > 31))||((compr.data.mes <= 0)||(compr.data.mes > 12))||(compr.data.ano <= 0))
        {
            printf("\n--> Digitou uma data invalida.\n\n");
        }

    }
    while(((compr.data.dia <= 0)||(compr.data.dia > 31))||((compr.data.mes <= 0)||(compr.data.mes > 12))||(compr.data.ano <= 0));



    /*HORARIO-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
    do
    {
        printf("Digite o horario do compromisso (Formato: hh:mm):\n");
        fflush(stdin);
        gets(horario);
        fflush(stdin);
        printf("\n");

        if((horario[2] != ':')||(strlen(horario) > 5))
        {
            printf("--> Formato Incorreto do Horario!\n\n");
            return 1;
        }
        compr.horario = pegar_hora(horario).horario;

        if(((compr.horario.hora < 0)||(compr.horario.hora > 23))||((compr.horario.minuto < 0)||(compr.horario.minuto > 59)))
        {
            printf("--> Digitou um horario invalido.\n\n");
        }
    }
    while(((compr.horario.hora < 0)||(compr.horario.hora > 23))||((compr.horario.minuto < 0)||(compr.horario.minuto > 59)));

    /*DESCRICAO---------------------------------------------------------------------------------------------------------------------------------------------------------*/

    printf("Digite a descricao do compromisso (ate 100 caracteres):\n");
    fflush(stdin);
    gets(compr.descricao);
    fflush(stdin);
    printf("\n");

    system("CLS");

    agenda[n] = compr;

    return 0;
}

COMPROMISSO pegar_data(char *data)
{
    int i;
    char dia[3], mes[3], ano[5];
    COMPROMISSO data_compr;

    for(i = 0; i < 2; i++)
    {
        dia[i] = data[i];
    }
    for(i = 0; i < 2; i++)
    {
        mes[i] = data[i+3];
    }
    for(i = 0; i < 4; i++)
    {
        ano[i] = data[i+6];
    }
    dia[2] = '\0';
    mes[2] = '\0';
    ano[4] = '\0';

    data_compr.data.dia = atoi(dia);
    data_compr.data.mes = atoi(mes);
    data_compr.data.ano = atoi(ano);

    return data_compr;
}

COMPROMISSO pegar_hora(char *horario)
{
    int i;
    char hora[3], minuto[3];
    COMPROMISSO hora_compr;

    for(i = 0; i < 2; i++)
    {
        hora[i] = horario[i];
    }
    for(i = 0; i < 2; i++)
    {
        minuto[i] = horario[i+3];
    }

    hora[2] = '\0';
    minuto[2] = '\0';

    hora_compr.horario.hora = atoi(hora);
    hora_compr.horario.minuto = atoi(minuto);

    return hora_compr;
}

void ordenar_agenda(COMPROMISSO *agenda, int n)
{
    int i, j;
    COMPROMISSO aux;

    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(compara_compr(agenda[i],agenda[j]) == 1)
            {
                aux = agenda[j];
                agenda[j] = agenda[i];
                agenda[i] = aux;
            }
        }
    }
}

int compara_compr(COMPROMISSO inicial, COMPROMISSO secundario)
{
    if(inicial.data.ano < secundario.data.ano) return 0;
    if(inicial.data.ano > secundario.data.ano) return 1;
    if(inicial.data.ano == secundario.data.ano)
    {
        if(inicial.data.mes < secundario.data.mes) return 0;
        if(inicial.data.mes > secundario.data.mes) return 1;
        if(inicial.data.mes == secundario.data.mes)
        {
            if(inicial.data.dia < secundario.data.dia) return 0;
            if(inicial.data.dia > secundario.data.dia) return 1;
            if(inicial.data.dia == secundario.data.dia)
            {
                if(inicial.horario.hora < secundario.horario.hora) return 0;
                if(inicial.horario.hora > secundario.horario.hora) return 1;
                if(inicial.horario.hora == secundario.horario.hora)
                {
                    if(inicial.horario.minuto < secundario.horario.minuto) return 0;
                    if(inicial.horario.minuto > secundario.horario.minuto) return 1;
                    if(inicial.horario.minuto == secundario.horario.minuto) return 0;
                }
            }
        }
    }
}

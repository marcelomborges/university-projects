#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[3][3], i, j;
    FILE *arq;
// Verificando se existe o arquivo !
    if ( (arq=fopen("dados.txt", "r")) == NULL)
    {
        printf("Erro ao abrir dados.txt \n");
        exit(0); // termina o programa.
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(arq,"%d ", &a[i][j]);
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
 fclose(arq); // Após ler, fechar arquivo.
 return 0;
}

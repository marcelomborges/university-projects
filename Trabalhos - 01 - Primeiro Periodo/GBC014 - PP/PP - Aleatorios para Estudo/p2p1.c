#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int achar(char *frase, char *palavra);

int main ()
{
    int vezes;
    char *frase = "arara rara em araraquara";
    char *palavra = "ara";
    puts(frase);
    printf("\n");
    puts(palavra);
    printf("\n");

    vezes = achar(frase,palavra);

    printf("%d",vezes);

    return 0;
}

int achar(char *frase, char *palavra)
{
    int i,j,c=0,aux=0,cont=0;

    for(i = 0; i < strlen(frase); i++)
    {
        j = i;
        do
        {
            if(frase[j] == palavra[c])
            {
                aux++;
            }
            c++;
            j++;
        }
        while(c < strlen(palavra));

        if(aux == strlen(palavra))
        {
            cont++;
            i = j-1;
        }

        c = 0;
        aux=0;
    }
    return cont;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
     /*Comentario*/
     int num, leitura;
     
     num = 100;
     
     printf("num: %d\n", num);
     
     printf("Digite um numero inteiro: ");
     
     scanf("%d", &leitura);
     
     printf("LEITURA: %d\n", leitura);
     
     if(leitura >= 0)
     {
          num = num/2;
          leitura = num-1;
     }
     else
     {
          num = num*2;
          leitura = num+1;
     }
     
     while(leitura > 0)
     {
          leitura--;
     }
     
     do
     {
          leitura++;
     }
     while(leitura < 100);
     
     for(num = 0; num < 100; num++)
     {
          printf("%d\n",num);
     }
     
     return 0;
}

L     T       .text           P  �   d           0`.data                               @ 0�.bss                                � 0�.rdata          $  ,              @ 0@/4                 P              @ 0@U��S�����P  �    Ǆ$H      Ǆ$D      �$    �    �$0   �    ��$�   �$�    Ǆ$L      �:��$�   ��$L  �� ���$�    ����$�   ��$L  Ј��$L  ��$L  ��$�   �$�    9�r�Ǆ$L      �w��$�   ��$L  �� <`~��$�   ��$L  �� <z~��$�   ��$L  �� ��u*��$�   ��$L  �� �L$x��$H  ʈ��$H  ��$L  ��$L  ��$�   �$�    9��k����D$x�$�    ����$@  ��$@  ��$L  �/�T$x��$D  �� �L$��$L  ʈ��$D  ��$L  ��$L   yǍD$x�$�    �D �$T   �    �D$x�$�    �$�   �    �D$�$�    �D$�D$�D$x�$�    ��u��$�   �D$�$�   �    ���$�   �D$�$�   �    �$  �    �    �]���Avalio se uma string eh ou nao eh palindroma.
  Digite a frase que sera invertida:  
A string com letras minusculas (sem outros caracteres) eh: A string com letras minusculas (sem outros caracteres) e invertida eh:  
A string "%s" eh palindroma.

 
A string "%s" nao eh palindroma.

 PAUSE   GCC: (tdm-1) 4.9.2         +   
    0       7   
    <       K       v       �       F      Z      �      �  
    �      �      �  
    �      �              
          1  
    6      =  
    B      .file       ��  gpalindromo.c      _main                            .text          P               .data                            .bss                             .rdata         "                                               ___main          _gets            _tolower         _strlen          _puts            _strcmp          _printf          _system             .rdata$zzz .rdata$zzz                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       /*
Programa: Revisao para prova 02
Aluno: Marcelo Mendonca Borges
Data: 29/05/2016
*/

/*Inclusao de Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>

/*Prototipos de Funcoes*/
int fatorial(int);

int main ()
{
    /*Declaracao de Variaveis*/
    int num, fat_num;
    /*-----------------------*/

    printf("Calculo o fatorial de um numero utilizando funcao recursiva.\n\n");
    do
    {
        printf("Digite um numero: ");
        scanf("%d",&num);
    }
    while(num < 0);

    fat_num = fatorial(num);

    printf("\n%d! = %d\n",num,fat_num);

    return 0;
}

int fatorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return n;
    }
    else
    {
        return n * fatorial(n - 1);
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 /*
Programa: Simulado 02 Exercicio 4
Aluno: Marcelo Mendonca Borges
Data: 24/04/2016
Descricao:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    /*Declaracao de Variaveis*/

    int r[10], s[10], x[20];
    int i, j, k = 0, presente = 0;

    /*-----------------------*/

    printf("Vetor r:\n");
    for(i = 0; i < 10; i++)
    {
        printf("r[%d]: ",i);
        scanf("%d", &r[i]);
    }

    printf("\nVetor s:\n");
    for(j = 0; j < 10; j++)
    {
        printf("s[%d]: ",j);
        scanf("%d", &s[j]);
    }

    for(i = 0; i < 10; i++)
    {
        presente = 0;
        for(j = 0; j < k; j++)
        {
            if(r[i] == x[i])
            {
                presente = 1;
                break;
            }
            if (!presente)
            {
                x[k] = s[i];
                ++k;
            }
        }
    }

    printf("\nVetor x:\n");
    for(i = 0; i < k; i++)
    {
        printf("x[%d]: %d\n",i,x[i]);
    }
    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        L     �       .text           �  �               0`.data                               @ 0�.bss                                � 0�.rdata          <   �              @ 0@/4                               @ 0@U�������   �    Ǆ$�       Ǆ$�       �$    �    Ǆ$�       �B��$�   �D$�$	   �    ��$�   ��$�   ��ЉD$�$   �    ��$�   ��$�   	~��$   �    Ǆ$�       �?��$�   �D$�$   �    �D$`��$�   ��ЉD$�$   �    ��$�   ��$�   	~�Ǆ$�       �   Ǆ$�       Ǆ$�       �Z��$�   ����   ��$�   �D�9�uǄ$�      �@��$�    u��$�   �T�`��$�   �T���$�   ��$�   ��$�   ;�$�   |���$�   ��$�   	�h����$&   �    Ǆ$�       �.��$�   �D��D$��$�   �D$�$0   �    ��$�   ��$�   ;�$�   |¸    ��Vetor r: r[%d]:  %d 
Vetor s: s[%d]:  
Vetor x: x[%d]: %d
  GCC: (tdm-1) 4.9.2         *   
    /       N   
    S       q   
    v       �   
    �       �   
    �       �   
    �       �  
    �      �  
    �      .file       ��  gsim2p4.c          _main                            .text          �               .data                            .bss                             .rdata         ;                                                ___main          _puts            _printf          _scanf              .rdata$zzz .rdata$zzz                                                       
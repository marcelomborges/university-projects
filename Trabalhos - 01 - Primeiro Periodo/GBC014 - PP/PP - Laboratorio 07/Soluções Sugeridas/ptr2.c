#include <stdio.h>


int main(int argc, char *argv[])
{
    int i, *p, *q;
    i = 9;
    p = &i;     // p aponta para i.
    q = p;      // q tamb�m aponta para i.
    printf("i  = %d \n",i);      // valor de i
    printf("&i = %X\n", &i);     // end de i
    printf("p  = %p \n", p);     // end apontado
    printf("q  = %p \n", q);     // end apontado
    printf("p  = %d\n", *p);     // conteudo do end apontado por p.
    return 0;
}

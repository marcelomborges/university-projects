#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 5;
    int *p_x = NULL; // Ponteiro de x.
    int **pp_x = NULL; // Ponteiro para ponteiro de x.

    printf("&x: (%p)\n&p_x:(%p)\n&pp_x:(%p)\n",&x,&p_x,&pp_x);
    getch();
    p_x = &x; // Carga inicial dos ponteiros
    pp_x = &p_x;
//    **pp_x = 33;
    printf("x= %d -\t&x   = %x \n",x,&x);
    printf("x= %d -\tp_x  = %p \n",*p_x,p_x);
    printf("x= %d -\t*p_x = %d\n",**pp_x,*p_x);
    printf("&p_x= %p -\t&p_x = %p\n",&(*pp_x),&p_x);
    return 0;
}

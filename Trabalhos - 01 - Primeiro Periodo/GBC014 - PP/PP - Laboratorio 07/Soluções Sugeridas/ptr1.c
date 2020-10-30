#include <stdio.h>

int main(int argc, char *argv[]){
    int *p, i = 4;
    p = &i;
    printf("i \t= %d \n",i);
    printf("&i\t= %x \n",&i);
    printf("p \t= %p \n",p);
    printf("&p\t= %X \n",&p);
    return 0;
}

#include <stdio.h>


int main(int argc, char *argv[])
{
    int v[3] = {10, 20, 30};
    int *ptr = NULL;
    ptr = v;
    printf("v[0] = %d \n", *(ptr));
    printf("v[1] = %d \n", *(++ptr));
    scanf("%d",ptr);
    printf("v[1] = %d \n", *(ptr));
    ptr++;
    printf("v[2] = %d \n", *(ptr));
    return 0;
}

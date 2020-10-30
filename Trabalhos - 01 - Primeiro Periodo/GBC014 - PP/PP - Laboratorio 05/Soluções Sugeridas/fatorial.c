/*************************************/
/* program: fatorial.c               */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2016                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

unsigned long int fatorial(unsigned long int n);

int main(int argc, char* argv[]) {
	int n, fat;
	
	printf("Calculo do fatoria de n (n!) \n");
	printf("Digite o valor de n (n>0) ? ");
	scanf("%d",&n); 
 	fat = fatorial(n);

 	printf("%d! = %ld\n",n,fat);
 	
 	return 0;
}

unsigned long int fatorial(unsigned long int n){
	unsigned long int fat = 1;
	for(;n>0;n--) fat = fat*n;
	return fat;
}

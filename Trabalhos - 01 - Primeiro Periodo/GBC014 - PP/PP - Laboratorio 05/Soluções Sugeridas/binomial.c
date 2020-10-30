/*************************************/
/* program: binomial.c               */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2016                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

int fatorial(int n);

int main(int argc, char* argv[]) {
	int n, k , bin;

	printf("Calculo de Combinacao simples C(n,k) = (n!)/(k!(n-k)! \n");
	printf("Digite o valor de n (n>0) ? ");
	scanf("%d",&n);
	printf("Digite o valor de k (0<k<=n) ? ");
	scanf("%d",&k);
 	bin = binomial2(n,k);

 	printf("C(%d,%d) = %d\n",n,k,bin);

 	return 0;
}

int fatorial(int n){
	long int fat = 1;
	for(;n>0;n--) fat = fat*n;
	return fat;
}

int binomial(int n, int k){
	return fatorial(n)/(fatorial(k)*fatorial(n-k));
}

int binomial2(int n, int k){
	int i, num=1, div=1;
	if(n-k>k){
		for(i=n;i>n-k;i--) num = num*i;
		for(i=k;i>0;i--) div = div*i;
	} else {
		for(i=n;i>k;i--) num = num*i;
		for(i=n-k;i>0;i--) div = div*i;
	}
	return num/div;
}

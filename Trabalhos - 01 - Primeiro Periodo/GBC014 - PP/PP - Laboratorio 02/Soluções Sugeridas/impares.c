/*************************************/
/* program: nome.c                   */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2013                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n, i, impares=0;
	
	for(i=0;i<10;i++){
		printf("valor %d: ",i);
		scanf("%d",&n);
//		if(n%2) impares++;
		impares += n&1;
	}
	printf("impares: %d\n",impares);

	return 0;
}



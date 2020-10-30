// Programa - data1.c
// Autor: Claudio C. Rodrigues
// Data: dd/mm/aaaa

//declaração de bibliotecas utilizadas
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int d1,m1,a1;
	int d2,m2,a2;
	int flag;
	do {
		flag = 0;
		printf("Digite a 1a. data (dd mm aaaa): ");
		scanf("%d%*c%d%*c%d", &d1,&m1,&a1);
		if((d1<1)||(d1>31)||(m1<1)||(m1>12)||(a1>2013)||((d1>29)&&(m1==2))) {
			flag = 1;
			printf("Data invalida...\n");
		} 
	} while(flag);
	do {
		flag = 0;
		printf("Digite a 2a. data (dd mm aaaa): ");
		scanf("%d%*c%d%*c%d", &d2,&m2,&a2);
		if((d2<1)||(d2>31)||(m2<1)||(m2>12)||(a2>2013)||((d2>29)&&(m2==2))) {
			flag = 1; 
			printf("Data invalida...\n");
		} 
	} while(flag);
	printf("Data 1: %02d/%02d/%4d \n",d1,m1,a1);
	printf("Data 2: %02d/%02d/%4d \n",d2,m2,a2);
	if(a1>a2) printf("A data %02d/%02d/%4d eh a mais recente\n",d1,m1,a1);
	else if (a2>a1) printf("A data %02d/%02d/%4d eh a mais recente\n",d2,m2,a2);
	else if (m1>m2) printf("A data %02d/%02d/%4d eh a mais recente\n",d1,m1,a1);
	else if (m2>m1) printf("A data %02d/%02d/%4d eh a mais recente\n",d2,m2,a2);
	else if (d1>d2) printf("A data %02d/%02d/%4d eh a mais recente\n",d1,m1,a1);
	else if (d2>d1) printf("A data %02d/%02d/%4d eh a mais recente\n",d2,m2,a2);
	else printf("As datas %02d/%02d/%4d sao iguais\n",d1,m1,a1);

	getch();
   return 0;
}

#include <stdlib.h>
#include <stdio.h>

int segundos(int,int,int);


void main() {
	int hh, mm, ss;

	printf("Conversao de Horas:Minutos:Segundos para Segundos\n");

	printf("Digite a hora (hh:mm:ss) ? ");
	scanf("%d %d %d",&hh,&mm,&ss);
	printf("%02d:%02d:%02d ==> %d segundos\n",hh,mm,ss,segundos(hh,mm,ss));

}


int segundos(int h, int m, int s){
	return h*3600+m*60 + s;
}

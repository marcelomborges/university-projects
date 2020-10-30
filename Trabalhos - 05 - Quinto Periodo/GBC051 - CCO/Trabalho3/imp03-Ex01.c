#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* For All --------------------------------------------------------------------------------------------------------------------------------------*/

void printm(float m[][6],int s){

	int i,j;

	for(i = 0; i < s; i++){
		for(j = 0; j < (s+1); j++){
			if(j == s){
				printf("= %f\n",m[i][j]);
			}
			else {
				if(j == s-1 ) printf("(%f)*X%d  ",m[i][j],j);
				else printf("(%f)*X%d + ",m[i][j],j);
			}
		}
	}

	printf("\n\n");
}

void printr(float *r,int s){

	int i;

	for(i=0;i<s;i++) printf("X%d = %f\n",i,r[i]);

	printf("\n\n");

}

void printm2(float r[][6],int s){

	int i,j;

	for(i=0;i<s;i++) {

		for(j=0;j<s;j++){
			if(j == (s-1)) printf(" %f \n",r[i][j]);
			else printf(" %f ",r[i][j]);
		}

	}

	printf("\n\n");

}

/* Gauss ----------------------------------------------------------------------------------------------------------------------------------------*/

float* metGauss(float m[][6],int s){

	float *vs;
	float aux1,aux2;
	int i,j,k;

	for(i = 0;i < s;i++){

		aux1 = m[i][i];

		for(j = (i+1);j < s; j++){

			aux2 = m[j][i];
			
			for(k = i;k < (s+1); k++){
				m[j][k] = m[j][k] - ((aux2/aux1)*m[i][k]);
			}
		}
	}

	printf("\n\nEscalonada :\n\n");
	printm(m,s);
	printf("\n\n");

	vs = (float *) malloc(sizeof(float)*s);
	
	for(i = (s-1); i >= 0; i--){
		
		float tot = 0;
		
		for(j = (s-1); j > i; j--){
			tot = tot - m[i][j]*vs[j];
		}
	
		tot += m[i][s];

		vs[i] = tot/m[i][i];

	}

	printr(vs,s);
}

/* Main ----------------------------------------------------------------------------------------------------------------------------------------*/

int main(){

	float m[5][6] = { {2, 1,-1,-1,-3, 7},
			  {1, 0, 2,-1, 1, 2},
			  {0,-2,-1, 1,-1,-5},
			  {3, 4,-4, 0, 5, 6},
			  {1,-1,-1,-1, 1, 3} };
	float **mg;

	int v = 5,i;

	mg = (float **) malloc(sizeof(float *)*5);
	for(i=0;i<5;i++) mg[i] = (float *) malloc(sizeof(float)*6);

	printf("\n\n");

	printm(m,v);
	metGauss(m,v);

}

/*
	printf("Digite o numero de variaveis : ");
	while(v < 2) scanf("%d",&v);

	m = (float **) malloc(sizeof(float*)*v);
	r = (float  *) malloc(sizeof(float )*v);
	for(i = 0;i < v;i++) m[i] = (float *) malloc(sizeof(float)*(v+1));

	for(i = 0;i < v;i++) {
		for(j = 0;j < (v+1);j++){
			if(j == v) { 
				printf("Digite o valor da equacao %d : ",i);
				scanf("%f",&m[i][j]);
			}
			else {
				printf("[Eq %d] Digite o coeficiente da variavel %d : ",i,j);
				scanf("%f",&m[i][j]);
			}
		}
	}

	system("clear");
*/


/*
	mg = (float **) malloc(sizeof(float*)*6);
	for(i = 0;i < 6;i++) mg[i] = (float*) malloc(sizeof(float)*7);

	for(i = 0;i < 6;i++){

		for(j = 0;j < 7;j++){
			if(j != 6) mg[i][j] = pow((i+1),abs(j-5));
			else {
				if(i == 5) mg[i][j] = 0;
				else mg[i][j] = 1;
			}
		}
	}

*/

#include <stdlib.h>
#include <stdio.h>
// x^a + y^b + (x - y)^(a+b).

float potencia(float, int);


void main() {
	int a, b;
	float x, y, xa, yb, xyab, resposta=0;

	printf("Calculo de Potência - base elevado a expoente (X^y):");
	printf("Expressao de teste: x^a + y^b + (x - y)^(a+b)\n");
	printf("Digite dois valores reais (x e y) ? ");
	scanf("%f %f",&x,&y);
	do{
		printf("Digite doiS valores inteiros positivos (a e b) ? ");
		scanf("%d %d",&a,&b);
	} while(a<0 || b<0);
	xa = potencia(x,a);
	yb = potencia(y,b);
	xyab = potencia(x-y,a+b);
	resposta = xa + yb + xyab;
	printf("%.2f^%d + %.2f^%d + (%.2f - %.2f)^(%d+%d) = %.3f",x,a,y,b,x,y,a,b,resposta);

}

float potencia(float base, int expoente)
{
	float i = 1.0;
	if(expoente<0) return;
	for(;expoente;expoente--) i = base*i;
	return i;
}

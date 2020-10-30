/*************************************/
/* program: nome.c                   */
/* autor: Claudio C. Rodrigues       */
/* data: dd/mm/2013                  */
/*************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;
	char c;
	
	for(i=0;i<5;i++) {
		printf("Digite um caracter:");
		scanf("%c",&c);
		c = tolower(c);
		if(c>='a' && c<='z'){
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
				printf("%c eh uma vogal\n",c);
			}else printf("%c eh uma consoante\n",c);
		} else puts("erro...nao eh letra do alfabeto");
		fflush(stdin);
	}
	


	return 0;
}



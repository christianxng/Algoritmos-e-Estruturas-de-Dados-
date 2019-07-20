
//  +++++++++++++++++++++   Questão 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fibonacci (int x){
	if(x==1 || x==2){
		return 1;
	}else{
		return Fibonacci(x-1)+Fibonacci(x-2);
	}
}

int main(){
	int n, z, i;
	printf ("Digite o elemento\t");
	scanf ("%d", &n);
	for(i=1; i<=n; i++){
		z=Fibonacci(i);
    	printf ("%d\n", z);
	}
	return 0;
	system("pause>>null");
}



//  +++++++++++++++++++++   Questão 2)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fibonacci (int x){
	int i, ant=0, num=1, aux;
	if(x==0){
		printf("0\n");
		return;
	}
	if(x==1){
		printf("1\n");
		return;
	}
	
	printf("1\n");
	for(i=2; i<=x; i++){
		aux=ant+num;
		ant=num;
		num=aux;
		printf ("%d\n", aux);
	}	
}

int main(){
	int n;
	printf ("Digite o elemento\t");
	scanf ("%d", &n);
	Fibonacci(n);
	return 0;
	system("pause>>null");
}




//  +++++++++++++++++++++   Questão 3)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maior(int v[], int tam){
	if(tam==1){
		return v[0];
	}
	else{
		int x;
		x=maior(v, tam-1);
		if(x>v[tam-1]){
			return x;
		}
	}
			return v[tam-1];
}

int main(){
	int n, i, num;
	printf ("Digite o tamanho do vetor\t");
	scanf ("%d", &n);
	int x[n];
	for(i=0; i<n; i++){
		printf ("Digite o valor\t");
		scanf("%d", &x[i]);
	}
	num=maior(x, n);
	printf ("%d", num);
	return 0;
	system("pause>>null");
}




//  +++++++++++++++++++++   Questão 4)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin (int x){
	if(x/2!=0){
	    bin(x/2);
	}
	printf ("%d", x%2);
}

int main(){
	int num;
	printf("Digite um numero\n");
	scanf("%d", &num);
	bin(num);
	return 0;
	system("pause>>null");
}



//  +++++++++++++++++++++   Questão 5)
void imprimirLista (CELULA **lista){
	if(listaVazia(lista)){
		printf ("Lista Vazia\n");
		return;
	}
	printf ("\n");
	if(lista != NULL){
		printf ("%d", (*lista)->info);
		imprimirLista(&(*lista)->next);
	}
	
}
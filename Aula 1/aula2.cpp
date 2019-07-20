#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct sSeriado{
	char nome[20];
	int ne;
	Data D;
}sSeriado;


void setaValores(sSeriado * seriado, int n){
	
	int i;
	for(i=0;i<n;i++){
		printf ("Digite o nome do episódio\n");
		scanf ("%s", seriado[i].nome);
		fflush (stdin);
    	printf ("Digite o numero de episodios\n");
		scanf ("%d", &seriado[i].ne);
		printf ("Digite o dia\n");
		scanf ("%d", &seriado[i].D.dia);
		printf ("Digite o mes\n");
		scanf ("%d", &seriado[i].D.mes);
		printf ("Digite o ano\n");
		scanf ("%d", &seriado[i].D.ano);	
	}
	for(i=0;i<n;i++){
		printf ("Nome: %s\n", seriado[i].nome);
		printf ("Numero do episódio: %d\n", seriado[i].ne);
		printf ("Data: %d/%d/%d\n", seriado[i].D.dia, seriado[i].D.mes, seriado[i].D.ano);	
	}
	
}

int main(){
	sSeriado * seriado;
	char n[20];
	int num, d,numEP, m, a;
	printf("digite a quantidade de seriados\n");
	scanf("%d", &numEP);
	seriado= (sSeriado*) malloc(numEP* sizeof(sSeriado));
	if(seriado==NULL){
		printf("impossivel de allocar memoria");
		exit(1);
	}
	setaValores(seriado, numEP);
	free(seriado);
	seriado=NULL;
	
	system ("pause");
	return 0;
}

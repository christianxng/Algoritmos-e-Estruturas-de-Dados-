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

void preencheSeriado (sSeriado *seriado, char *n, int num, int d, int m, int a){
	strcpy (seriado->nome, n);
	seriado->ne=num;
	seriado->D.ano=a;
	seriado->D.dia=d;
	seriado->D.mes=m;	
}

void imprimeSeriado (sSeriado seriado){
	printf ("Nome: %s\n", seriado.nome);
	printf ("Numero do episódio: %d\n", seriado.ne);
	printf ("Data: %d/%d/%d\n", seriado.D.dia, seriado.D.mes, seriado.D.ano);	
}


int main(){
	sSeriado seriado;
	char n[20];
	int num, d, m, a;
	
	printf ("Digite o nome do episódio\n");
	scanf ("%s", n);
	fflush (stdin);
    printf ("Digite o numero de episodios\n");
	scanf ("%d", &num);
	fflush (stdin);
	printf ("Digite o dia\n");
	scanf ("%d", &d);
	fflush (stdin);
	printf ("Digite o mes\n");
	scanf ("%d", &m);
	fflush (stdin);
	printf ("Digite o ano\n");
	scanf ("%d", &a);
	fflush (stdin);
	preencheSeriado (&seriado, n, num, d, m, a);
	imprimeSeriado (seriado);	
	
	system ("pause");
	return 0;
}

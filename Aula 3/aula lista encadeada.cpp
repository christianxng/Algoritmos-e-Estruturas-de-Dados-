

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
	char nome[30];
	int mat;
	float p1, p2, p3;
}INFO;

typedef struct sCell{
	INFO info;
	struct sCell *next;
}CELULA;

void inicializar (CELULA **lista){
	(*lista)=NULL;
}

int listaVazia (CELULA **lista){
	if ((*lista)==NULL){
		//lista vazia
		return 1;
	}
	return 0;
}

INFO preencher (){
	INFO item;
	printf ("Digite o nome\n");
	scanf ("%s", item.nome);
	printf ("Digite a matricula\n");
	scanf ("%d", &item.mat);
	printf ("P1:\n");
	scanf ("%.2f", &item.p1);
	printf ("P2:\n");
	scanf ("%.2f", &item.p2);
	printf ("P3:\n");
	scanf ("%.2f", &item.p3);
	return item;
}

CELULA *criarCelula(){
	CELULA *nova=(CELULA*) malloc (sizeof(CELULA));
	return nova;
}

int inserirFim (CELULA **lista){
	CELULA *novaCelula;
	CELULA *auxiliar;
	novaCelula=criarCelula();
	if (novaCelula==NULL){
		printf ("Mem�ria cheia!\n");
		return 0;
	}
	novaCelula->next=NULL;
	novaCelula->info=preencher();
	if (listaVazia(lista)){
		(*lista)=novaCelula;
		return 1;
	}
	auxiliar = (*lista);
	while (auxiliar->next != NULL){
		auxiliar = auxiliar->next;
	}
	auxiliar->next=novaCelula;
	return 1;
}

int inserirInicio (CELULA **lista){
	CELULA *novaCelula = criarCelula();
	if (novaCelula==NULL){
		printf ("Memoria cheia");
		return 0;
	}
	if (listaVazia(lista)){
		return inserirFim(lista);
	}
	novaCelula->info=preencher();
	novaCelula->next=(*lista);
	(*lista)=novaCelula;
	return 1;
}

INFO removerInicio (CELULA **lista){
	CELULA *removida;
	INFO removido;
	strcpy(removido.nome, " ");
	removido.mat=0;
	removido.p1=-1;
	removido.p2=-2;
	removido.p3=-3;
	if (listaVazia(lista)){
		printf ("Lista Vazia/n");
		return removido;
	}
	removida=(*lista);
	removido=removida->info;
	(*lista)=(*lista)->next;
	free(removida);
	return removido;
}

INFO criarInfo(char nome[2], int mat, float p1, float p2, float p3){
	INFO info;
	strcpy(info.nome, nome);
	info.mat=mat;
	info.p1=p1;
	info.p2=p2;
	info.p3=p3;
	return info;
}

INFO removerFinal (CELULA **lista){
	CELULA *removida;
	CELULA *anterior;
	INFO removido = criarInfo("  ", 0, -1, -2, -3);
	if (listaVazia(lista)){
		printf("Lista Vazia\n");
		return removido;
	}
	if((*lista)->next == NULL){
		return removerInicio(lista);
	}
	removida=(*lista);
	while(removida->next != NULL){
		anterior=removida;
		removida=removida->next;
	}
	removido=removida->info;
	anterior->next=NULL;
	free(removida);
	return removido;
}

void imprimirElemento (INFO info){
	printf ("Nome: %s\n", info.nome);
	printf ("Matricula: %d\n", info.mat);
	printf ("P1: %.2f\n", info.p1);
	printf ("P2: %.2f\n", info.p2);
	printf ("P3: %.2f\n", info.p3);
}

void imprimirLista (CELULA **lista){
	CELULA *auxiliar = (*lista);
	if(listaVazia(lista)){
		printf ("Lista Vazia\n");
	}
	else{
		printf ("LISTA:\n");
		while(auxiliar != NULL){
			imprimirElemento(auxiliar->info);
			auxiliar=auxiliar->next;
		}
		printf("\n");
	}
}

CELULA *pesquisarNota(CELULA **lista){
	CELULA *auxiliar;
	if(listaVazia(lista)){
		printf ("Lista Vazia!");
		return NULL;
	}
	auxiliar = (*lista);
	while (auxiliar != NULL){
		if(auxiliar->info.p1>60){
			return auxiliar;
		}
		auxiliar = auxiliar->next;
	}
	return NULL;
}

int inserirK (CELULA **lista, int k){ //??????????????????????????????????????????????????
	CELULA *auxiliar;
	CELULA *novaCelula=criarCelula();
	int cont=0, x;
	
	if(novaCelula==NULL){
		printf("Mem�ria cheia!\n");
		return 0;
	}
	auxiliar = (*lista);
	while (auxiliar != NULL){
		auxiliar = auxiliar->next;
		cont++;
	}
	if(k<0||k>cont+1){
		printf ("Posi��o inv�lida\n");
		return 0;
	}
	auxiliar=(*lista);
	cont=0;
	while(cont<k){
		auxiliar=auxiliar->next;
		cont++;
	}
	if(auxiliar->next==NULL){
		x=inserirFim(lista);
		return x;
	}
	if(k==1){
		x=inserirInicio(lista);
		return x;
	}
	novaCelula->next=auxiliar->next;
	auxiliar->next=novaCelula;
	return 1;
	
}

int tamanho (CELULA **lista){
	CELULA *auxiliar;
	int cont=0;
	if (listaVazia(lista)){
		printf ("Lista vazia!\n");
		return 0;
	}
	auxiliar = (*lista);
	while (auxiliar != NULL){
		auxiliar = auxiliar->next;
		cont++;
	}
	return cont;
}

void liberarLista (CELULA **lista){ //n�o vai mudar se for circular
	int x;
	do{
		x=removerFinal(lista);
	}while (listaVazia(lista) != 1);
}

int inserirOrdenadoMat (CELULA **lista, INFO elemento){ //vai mudar se for circular
	CELULA *nova, *aux, *anterior;
	
	nova=criarCelula();
	if(nova==NULL){
		printf ("Mem�ria Cheia\n");
		return 0;
	}
	nova->info=elemento;
	nova->next=NULL;
	aux=(*lista);
	while(aux != NULL){
		if (nova->info.mat <= aux->info.mat){
			break;
		}
		anterior=aux;
		aux= aux->next;
	}
	nova->next=aux;
	if(aux==(*lista)){
		(*lista)=nova;
	}else{
		anterior->next=nova;
	}
	return 1;
}

int inserirOrdenadoNome (CELULA **lista, INFO elemento){ //vai mudar se for circular
	CELULA *nova, *aux, *anterior;
	
	nova=criarCelula();
	if(nova==NULL){
		printf ("Mem�ria Cheia\n");
		return 0;
	}
	nova->info=elemento;
	nova->next=NULL;
	aux=(*lista);
	while(aux != NULL){
		if (strcpm(nova->info.nome, aux->info.nome)==0 || strcpm(nova->info.nome, aux->info.nome)== -1){
			break;
		}
		anterior=aux;
		aux= aux->next;
	}
	nova->next=aux;
	if(aux==(*lista)){
		(*lista)=nova;
	}else{
		anterior->next=nova;
	}
	return 1;
}

void imprimirElemento (INFO info){ //n�o vai mudar se for circular
	printf ("Nome: %s\n", info.nome);
	printf ("Matricula: %d\n", info.mat);
	printf ("P1: %.2f\n", info.p1);
	printf ("P2: %.2f\n", info.p2);
	printf ("P3: %.2f\n", info.p3);
	printf ("M�dia das notas: %.2f", (info.p1+info.p2+info.p3)/3);
}

void imprimirLista (CELULA **lista){ //vai mudar se for circular
	CELULA *auxiliar = (*lista);
	if(listaVazia(lista)){
		printf ("Lista Vazia\n");
	}
	else{
		printf ("LISTA:\n");
		while(auxiliar != NULL){
			imprimirElemento(auxiliar->info);
			auxiliar=auxiliar->next;
		}
		printf("\n");
	}
}


int main (){
	CELULA *lista;
	CELULA *aux;
	INFO temp;
	int t;
	
	int n, k;
	do{
		
		printf("1- Inicilizar\n");
		printf("2- Inserir item no inicio\n");
		printf("3- Inserir no final\n");
		printf("4- Remover item no inicio\n");
		printf("5- Remover no final\n");
		printf("6- Imprmir\n");
		printf("7- Pesquisar elemento com P1>60\n");
		printf("8- Inserir na posi��o K\n");
		printf("9- Imprimir Tamanho da Lista\n");
		printf("10- Sair do programa\n");
		scanf ("%d", &n);
		switch (n){
			case 1:
				inicializar(&lista);
				printf ("Lista Incializada!\n");
				break;
			case 2:
				inserirInicio(&lista);
				printf ("Elemento inserido!\n");
				break;
			case 3:
				inserirFim(&lista);
				printf("Elemento inserido!\n");
				break;
			case 4:
				removerInicio(&lista);
				printf ("Elemento removido!\n");
				break;
			case 5:
			    removerFinal(&lista);
			    printf ("Elemento removido!\n");
				break;
			case 6:
			    imprimirLista(&lista);
				break;
			case 7:
			    aux=pesquisarNota(&lista);
			    if(aux!=NULL){
			    	printf ("Primeiro aluno com P1>60", aux->info.nome);
				}else{
					printf("Aluno n�o encontrado");
				}
				break;
			case 8:
			    
				break;
			case 9:
			    t=tamanho(&lista);
			    printf ("Tamanho da lista: %d\n", t);
				break;
			case 10:
			    exit (1);		
		}
	}while (n!=10);
	free(lista);
	system ("pause>>null");
	return 0;
}

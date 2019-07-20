//Christian Rodrigues Moura
//3629
//Turma 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode{
	int info;
	struct sNode *esq;
	struct sNode *dir;
}NO;

void inicializar (NO **arvore){
	(*arvore)=NULL;
}

int vazia (NO **arvore){
	if((*arvore)==NULL){
		return 1;
	}
	return 0;
}

NO* criarno (){
	NO *novo=(NO*)malloc(sizeof(NO));
	return novo;
}

void inserir_rec (NO **arvore, int elemento){

	if((*arvore)==NULL){
		NO *novo=criarno();
		if(novo==NULL){
	    	printf ("Memoria cheia\n");
	    	return;
     	}
		novo->info=elemento;
     	novo->dir=NULL;
    	novo->esq=NULL;
		(*arvore)=novo;
		printf ("Elemento Inserido!\n");
		return;
	}
	if(elemento > (*arvore)->info){
		return inserir_rec(&(*arvore)->esq, elemento);
	}else{
		return inserir_rec(&(*arvore)->dir, elemento);
	}
}
void removerRec(NO **arvore, int elemento)
{
	NO * aux;
	
	if(vazia(arvore))
	{
		printf("Erro: ");
		return;
	}
	if(elemento < (*raiz))
}


void incrementar (NO **arvore){
	if((*arvore)!=NULL){
		incrementar(&(*arvore)->dir);
		(*arvore)->info++;
		incrementar(&(*arvore)->esq);
	}
}




void imprimirEmOrdem (NO **arvore){
	if((*arvore)!=NULL){
		imprimirEmOrdem(&(*arvore)->dir);
		printf("%d\n", (*arvore)->info);
		imprimirEmOrdem(&(*arvore)->esq);
	}
}

void imprimirFolha (NO **arvore){
	if((*arvore)!=NULL){
		imprimirEmOrdem(&(*arvore)->dir);
		if((*arvore)->dir==NULL && (*arvore)->esq==NULL){
			printf("%d\n", (*arvore)->info);
		}		
		imprimirEmOrdem(&(*arvore)->esq);
	}
}

int contaElem (NO **arvore, int elemento){
    if(vazia(arvore)){
    	return 0;
	}
	if (elemento==(*arvore)->info){
    	return 1+contaElem(&(*arvore)->esq, elemento)+contaElem(&(*arvore)->dir, elemento);
	}
	return contaElem(&(*arvore)->esq, elemento)+contaElem(&(*arvore)->dir, elemento);
}

int main(){
	int temp, n;
	NO *arvore;
	
	do{
		
		printf("1- Inicilizar\n");
		printf("2- Inserir Recursivo\n");
		printf("3- Remover\n");
		printf("4- Imprmir\n");
		printf("5- Imprimir Folhas\n");
		printf("6- Contar Elemento\n");
		printf ("8 - Incrementar um em cada nó");
		printf("0- Sair do programa\n");
		scanf ("%d", &n);
		switch (n){
			case 1:
				inicializar(&arvore);
				printf ("Arvore Incializada!\n");
				system("pause>>null");
				break;
			case 2:
				printf("Digite o elemento a ser inserido\n");
				scanf("%d", &temp);
				inserir_rec(&arvore, temp);
				break;
			case 3:
				
				break;
			case 4:
				imprimirEmOrdem(&arvore);
				break;
			case 5:
			    imprimirFolha(&arvore);
				break;
			case 6:
				printf ("Digite o elemento a ser procura\n");
				scanf("%d", &temp);
				n=contaElem(&arvore, temp);
				printf("%d\n", n);
				break;
			case 8: 
					incrementar(&arvore);
					printf ("Numeros incrementados\n");
					break;
			case 0:
			    exit (1);		
		}
	}while (n!=0);
	free(arvore);
	system ("pause>>null");
	return 0;
}

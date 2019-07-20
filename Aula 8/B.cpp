#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
	char nome[20];
	int mat;
	float saldo;
}ALUNO;

typedef struct sCell{
	ALUNO info;
	struct sCell *prev, *next;
}CELULA;

typedef struct sDeque{
	CELULA *inicio, *fim;
	int cont;
}DEQUE;

void inicializar (DEQUE *deque){
	deque->inicio=NULL;
	deque->fim=NULL;
	deque->cont=0;
}

int dequeVazia (DEQUE *deque){
	if(deque->inicio==NULL){
		return 1;
	}
	return 0;
}

CELULA *criarCelula(){
	CELULA *nova=(CELULA*) malloc (sizeof(CELULA));
	return nova;
}

int enfileirarFim (DEQUE *deque, ALUNO elemento){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memória Cheia!\n");
		return 0;
	}
	nova->info=elemento;
	nova->next=NULL;
	if(dequeVazia(deque)){
	    nova->prev=NULL;
		deque->inicio=nova;
	    deque->fim=nova;
	    deque->cont++;
	    return 1;
	}
	deque->fim->next=nova;
	nova->prev=deque->fim;
	deque->fim=nova;
	deque->cont++;
	return 1;
}

ALUNO desenfileirarInicio (DEQUE *deque){
	ALUNO removido;
	CELULA *aux;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return removido;
	}
	deque->inicio->info.saldo=deque->inicio->info.saldo-2;
	aux=deque->inicio;
	removido = aux->info;
	deque->inicio=deque->inicio->next;
	if(deque->inicio==NULL){
		deque->fim=NULL;
		free(aux);
    	deque->cont--;
     	return removido;
	}
	deque->inicio->prev=NULL;
	free(aux);
	deque->cont--;
	return removido;
}

int enfileirarInicio (DEQUE *deque, ALUNO elemento){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memória Cheia!\n");
		return 0;
	}
	nova->info=elemento;
	if(dequeVazia(deque)){
	    enfileirarFim(deque, elemento);
	    return 1;
	}
	nova->prev=NULL;
	deque->inicio->prev=nova;
	nova->next=deque->inicio;
	deque->inicio=nova;
	deque->cont++;
	return 1;
}

ALUNO desenfileirarFim (DEQUE *deque){
	ALUNO removido;
	CELULA *aux;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return removido;
	}
	deque->inicio->info.saldo=deque->inicio->info.saldo-2;
	aux=deque->fim;
	removido = aux->info;
	deque->fim=deque->fim->prev;
	if(deque->fim==NULL){
		deque->inicio=NULL;
		free(aux);
      	deque->cont--;
    	return removido;
	}
	deque->fim->next=NULL;
	free(aux);
	deque->cont--;
	return removido;
}

void imprimirInicio (DEQUE *deque){
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return;
	}
	printf ("NOME: %s\n", deque->inicio->info.nome);
	printf ("MATRICULA\n: %d", deque->inicio->info.mat);
	printf ("SALDO: %.2f\n", deque->inicio->info.saldo);
}

void imprimirFim (DEQUE *deque){
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return;
	}
	printf ("NOME: %s\n", deque->fim->info.nome);
	printf ("MATRICULA\n: %d", deque->fim->info.mat);
	printf ("SALDO: %.2f\n", deque->fim->info.saldo);
}

void imprimirdoInicio (DEQUE *deque){
	while(!dequeVazia(deque)){ //enquanto o deque não for vazia
		imprimirInicio(deque);
		desenfileirarInicio(deque);
	}
}

void imprimirdoFim (DEQUE *deque){
	while(!dequeVazia(deque)){ //enquanto o deque não for vazia
		imprimirFim(deque);
		desenfileirarFim(deque);
	}
}

int main (){
	DEQUE d;
	ALUNO temp;
	int menu, n;
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar Deque");
        printf("\n2-Enfileirar Inicio");
        printf("\n3-Desenfileirar Inicio");
        printf("\n4-Enfileirar Fim");
        printf("\n5-Desenfileirar Fim");
        printf("\n6-Imprimir Inicio");
        printf("\n7-Imprimir Fim");
        printf("\n8-Imprimir do Inicio Desenfileirando");
        printf("\n9-Imprimir do Fim Desenfileirando");
        printf("\n10-Tamanho do Deque");
        printf("\n(-1 para fechar o programa)\n");
        scanf("%d", &menu);
        if(menu != -1){
                switch(menu){
                    case 1:
                        inicializar(&d);
                        printf("\nDeque Inicializado!\n");
                        system("pause>>null");
                   		break;
                    case 2:
                    	printf ("Digite o nome:\n");
                    	scanf ("%s", temp.nome);
                    	printf ("Digite a matricula:\n");
                    	scanf ("%d", &temp.mat);
                    	printf ("Digite o saldo:\n");
                    	scanf ("%f", &temp.saldo);
                        enfileirarInicio(&d, temp);
                        system("pause>>null");
                   		break;
                    case 3:
                        temp=desenfileirarInicio(&d);
                        printf("Nome removido: %s \n",temp.nome);
					    system("pause>>null");
                    	break;
                    case 4:
                    	printf ("Digite o nome:\n");
                    	scanf ("%s", temp.nome);
                    	printf ("Digite a matricula:\n");
                    	scanf ("%d", &temp.mat);
                    	printf ("Digite o saldo:\n");
                    	scanf ("%f", &temp.saldo);
                        enfileirarFim(&d, temp);
                        system("pause>>null");
                    	break;
                    case 5:
						temp=desenfileirarFim(&d);
                        printf("Nome removido: %s \n",temp.nome);
                        system("pause>>null");
                    	break;
                    case 6:
                        imprimirInicio(&d);
                    	system("pause>>null");
                    	break;
                    case 7:
                    	imprimirFim(&d);
                    	system("pause>>null");
                    	break;
                    case 8:
                    	imprimirdoInicio(&d);
                    	system("pause>>null");
                    	break;
                    case 9:
                    	imprimirdoFim(&d);
                    	system("pause>>null");
                    	break;
                    case 10:
                    	printf ("TAMANHO: %d\n", d.cont);
                    	system("pause>>null");
                    	break;
                }

        }
    }while(menu != -1);
}

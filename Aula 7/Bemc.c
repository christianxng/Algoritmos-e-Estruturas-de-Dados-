

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
	struct sCell *next;
}CELULA;

typedef struct fila{
	CELULA *inicio;
	CELULA *fim;
}FILA;

void inicializar (FILA *fila){
	fila->fim=NULL;
	fila->inicio=NULL;
}

int filaVazia (FILA *fila){
	if(fila->inicio==NULL){
		return 1;
	}
	return 0;
}

CELULA *criarCelula(){
	CELULA *nova=(CELULA*) malloc (sizeof(CELULA));
	return nova;
}

int enfileirar (FILA *fila, ALUNO elemento){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memória Cheia!\n");
		return 0;
	}
	nova->info=elemento;
	nova->next=NULL;
	if(filaVazia(fila)){
	    fila->inicio=nova;
	    fila->fim=nova;
	    return 1;
	}
	fila->fim->next=nova;
	fila->fim=nova;
	return 1;
}

ALUNO desenfileirar (FILA *fila){
	ALUNO removido;
	CELULA *aux;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return removido;
	}
	fila->inicio->info.saldo=fila->inicio->info.saldo-2;
	aux=fila->inicio;
	removido = aux->info;
	fila->inicio=fila->inicio->next;
	if(fila->inicio==NULL){
		fila->fim=NULL;
	}
	free(aux);
	return removido;
}

void imprimirInicio (FILA *fila){
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
	return;
	}
	printf ("NOME: %s\n", fila->inicio->info.nome);
	printf ("MATRICULA\n: %d", fila->inicio->info.mat);
	printf ("SALDO: %.2f\n", fila->inicio->info.saldo);
}

void imprimirDesenfileirar (FILA *fila){
	while(!filaVazia(fila)){ //enquanto a fila não for vazia
		imprimirInicio(fila);
		desenfileirar(fila);
	}
}

ALUNO desenfileirar2 (FILA *fila){
	ALUNO removido;
	CELULA *aux;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return removido;
	}
	aux=fila->inicio;
	removido=aux->info;
	fila->inicio=fila->inicio->next;
	free(aux);
	return removido;
}

void imprimirAuxiliar (FILA *fila, FILA *fila2){
	ALUNO aux;
	inicializar(fila2);
	while(!filaVazia(fila)){ //enquanto a fila não for vazia
		imprimirInicio(fila);
		aux=desenfileirar2(fila);
		enfileirar(fila2, aux);
	}
	while(!filaVazia(fila2)){ //enquanto a fila não for vazia
		aux=desenfileirar2(fila2);
		enfileirar(fila, aux);
	}
}

int tamanho (FILA *fila, FILA *fila2){
	int cont;
	cont=0;
	ALUNO aux;
	inicializar(fila2);
	while (!filaVazia(fila)){
		aux=desenfileirar2(fila);
		enfileirar(fila2, aux);
		cont++;	
	}
	while(!filaVazia(fila2)){ //enquanto a fila não for vazia
		aux=desenfileirar2(fila2);
		enfileirar(fila, aux);
	}
	return cont;
}

int main (){
	FILA f1, f2;
	ALUNO temp;
	int menu, n;
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar Fila");
        printf("\n2-Enfileirar");
        printf("\n3-Desenfileirar");
        printf("\n4-Imprimir inicio da fila");
        printf("\n5-Imprimir desenfileirando");
        printf("\n6-Imprimir com auxiliar");
        printf("\n7-Tamanho da Fila");
        printf("\n(-1 para fechar o programa)\n");
        scanf("%d", &menu);
        if(menu != -1){
                switch(menu){
                    case 1:
                        inicializar(&f1);
                        printf("\nFila Inicializada!\n");
                        system("pause>>null");
                   		break;
                    case 2:
                    	printf ("Digite o nome:\n");
                    	scanf ("%s", temp.nome);
                    	printf ("Digite a matricula:\n");
                    	scanf ("%d", &temp.mat);
                    	printf ("Digite o saldo:\n");
                    	scanf ("%f", &temp.saldo);
                        enfileirar(&f1, temp);
                        system("pause>>null");
                   		break;
                    case 3:
                        temp=desenfileirar(&f1);
                        printf("Nome removido: %s \n",temp.nome);
					    system("pause>>null");
                    	break;
                    case 4:
                        imprimirInicio(&f1);
                        system("pause>>null");
                    	break;
                    case 5:
						imprimirDesenfileirar(&f1);
                        system("pause>>null");
                    	break;
                    case 6:
                    	imprimirAuxiliar(&f1, &f2);
                    	system("pause>>null");
                    	break;
                    case 7:
                    	n=tamanho(&f1, &f2);
                    	printf ("Tamanho: %d\n", n);
                    	system("pause>>null");
                    	break;
                }

        }
    }while(menu != -1);
}

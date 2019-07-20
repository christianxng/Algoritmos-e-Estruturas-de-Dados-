#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
	char nome[20];
	int mat;
	float saldo;
}ALUNO;

typedef struct sDeque{
	ALUNO info[20];
	int cabecalho;
	int ultimo;
	int cont;
}DEQUE;

void inicializar (DEQUE *deque){
	deque->cabecalho=0;
	deque->ultimo=0;
	deque->cont=0;
}

int dequeVazia (DEQUE *deque){
	if(deque->ultimo==deque->cabecalho){
		return 1;
	}
	return 0;
}

int dequeCheia (DEQUE *deque){
	int prox;
	prox=(deque->ultimo+1)%20;
	if(prox==deque->cabecalho){
		return 1;
	}
	return 0;
}

int enfileirarFim (DEQUE *deque, ALUNO elemento){
	int prox;
	if(dequeCheia(deque)){
		printf ("Deque Cheia\n");
		return 0;
	}
	prox=(deque->ultimo+1)%20;
	deque->info[prox]=elemento;
	deque->ultimo=prox;
	deque->cont++;
	return 0;
}

ALUNO desenfileirarInicio (DEQUE *deque){
	ALUNO removido;
	int prox;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return removido;
	}
	prox=(deque->cabecalho+1)%20;
	deque->info[prox].saldo=deque->info[prox].saldo-2;
	deque->cabecalho=prox;
	removido=deque->info[prox];
	deque->cont--;
	return removido;
}

int enfileirarInicio (DEQUE *deque, ALUNO elemento){
	int ant;
	if(dequeCheia(deque)){
		printf ("Deque Cheia\n");
		return 0;
	}
	ant=(20+deque->cabecalho-1)%20;
	deque->info[deque->cabecalho]=elemento;
	deque->cabecalho=ant;
	deque->cont++;
	return 0;
}

ALUNO desenfileirarFim (DEQUE *deque){
	ALUNO removido;
	int ant;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return removido;
	}
	ant=(20+deque->ultimo-1)%20;
	deque->info[ant].saldo=deque->info[ant].saldo-2;
	removido=deque->info[deque->ultimo];
	deque->ultimo=ant;
	deque->cont--;
	return removido;
}

void imprimirInicio (DEQUE *deque){
	int prox;
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return;
	}
	prox=(deque->cabecalho+1)%20;
	printf ("NOME: %s\n", deque->info[prox].nome);
	printf ("MATRICULA\n: %d", deque->info[prox].mat);
	printf ("SALDO: %.2f\n", deque->info[prox].saldo);
}

void imprimirFim (DEQUE *deque){
	if(dequeVazia(deque)){
		printf("Deque Vazia\n");
		return;
	}
	printf ("NOME: %s\n", deque->info[deque->ultimo].nome);
	printf ("MATRICULA\n: %d", deque->info[deque->ultimo].mat);
	printf ("SALDO: %.2f\n", deque->info[deque->ultimo].saldo);
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

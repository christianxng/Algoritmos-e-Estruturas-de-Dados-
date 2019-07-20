//SIN 211 � Algoritmos e Estruturas de dados
//Professor: Gilberto Oliveira
//Projeto � Fila est�tica

// Integrantes: 
// Christian Rodrigues - 3629
// Matheus de Deus - 3918

// Quest�o 2: 

// Fila Cheia: 
// Verifica se est� cheia. 
// O resto da divis�o  de (fila->ultimo+1) pelo tamanho total do vetor(MAX_TAM), sempre dar� o resultado de 0 a MAX_TAM-1, 
// que s�o exatamente os �ndices v�lidos no vetor. Ent�o se (fila->ultimo+1)%MAX_TAM == fila->cabe�alho a fila estar� cheia. 

// Fila vazia: 
// Verifica se est� vazia. 
// Como o vetor funciona de forma circular, se fila->ultimo == fila->cabe�alho, ent�o temos uma fila vazia.

// Quest�o 3: 

// Em nosso c�digo a implementa��o foi feita de forma sequencial.
// Essa adapta��o na fun��o de desienfileirar causa a mudan�a que quando um item for removido, a fila inteira seja deslocada
// no sentido do in�cio do vetor (evitando que perca posi��es do vetor) assim podendo posteriormente aproveitar esse espa�o com a fun��o enfileirar.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TAM 20

typedef struct Aluno{
	char nome[20];
	int mat;
	float saldo;
}ALUNO;

typedef struct fila{
	ALUNO info[MAX_TAM];
	int cabecalho;
	int ultimo;
}FILA;

void inicializar (FILA *fila){
	fila->cabecalho=0;
	fila->ultimo=0;
}

int filaVazia (FILA *fila){
	if(fila->ultimo==fila->cabecalho){
		return 1;
	}
	return 0;
}

int filaCheia (FILA *fila){
	int prox;
	prox=(fila->ultimo+1)%MAX_TAM;
	if(prox==fila->cabecalho){
		return 1;
	}
	return 0;
}

int enfileirar (FILA *fila, ALUNO elemento){
	int prox;
	if(filaCheia(fila)){
		printf ("Fila Cheia\n");
		return 0;
	}
	prox=(fila->ultimo+1)%20;
	fila->info[prox]=elemento;
	fila->ultimo=prox;
	return 0;
}

ALUNO desenfileirar (FILA *fila){
	ALUNO removido;
	int prox;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return removido;
	}
	prox=(fila->cabecalho+1)%MAX_TAM;
	fila->info[prox].saldo=fila->info[prox].saldo-2;
	fila->cabecalho=prox;
	removido=fila->info[prox];
	return removido;
}

ALUNO desenfileirar2 (FILA *fila){
	ALUNO removido;
	int prox;
	strcpy(removido.nome, "Invalido");
	removido.mat=0;
	removido.saldo=-1;
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return removido;
	}
	prox=(fila->cabecalho+1)%MAX_TAM;
	fila->cabecalho=prox;
	removido=fila->info[prox];
	return removido;
}

void imprimirInicio (FILA *fila){
	int prox;
	if(filaVazia(fila)){
		printf("Fila Vazia\n");
		return;
	}
	prox=(fila->cabecalho+1)%MAX_TAM;
	printf ("NOME: %s\n", fila->info[prox].nome);
	printf ("MATRICULA\n: %d", fila->info[prox].mat);
	printf ("SALDO: %.2f\n", fila->info[prox].saldo);
}

void imprimirDesenfileirar (FILA *fila){ // Imprimir e desenfileirar. 
	while(!filaVazia(fila)){ //enquanto a fila n�o for vazia
		imprimirInicio(fila);
		desenfileirar(fila);
	}
}

void esvaziarFila (FILA *fila){ 
	while(!filaVazia(fila)){ //enquanto a fila n�o for vazia
		desenfileirar(fila);
	}
	printf("Fila limpa");
}

void imprimirAuxiliar (FILA *fila, FILA *fila2){ // Imprimir e manter fila original
	ALUNO aux;
	inicializar(fila2);
	while(!filaVazia(fila)){ //enquanto a fila n�o for vazia
		imprimirInicio(fila);
		aux=desenfileirar2(fila);
		enfileirar(fila2, aux);
	}
	while(!filaVazia(fila2)){ //enquanto a fila n�o for vazia
		aux=desenfileirar2(fila2);
		enfileirar(fila, aux);
	}
}



int main (){
	FILA f1, f2;
	ALUNO temp;
	int menu, n, i;
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar Fila");
        printf("\n2-Verificar Vazia");
        printf("\n3-Verificar Cheia");
        printf("\n4-Enfileirar");
        printf("\n5-Desenfileirar");
        printf("\n6-Limpar Fila");
        printf("\n7-Imprimir e esvaziar a fila");
        printf("\n8-Imprimir e manter a fila original");
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
                    	i = filaVazia(&f1);
                    	if(i == 1)
                    	{
                    		printf("A fila esta totalmente vazia. ");
						}
						else
						{
							printf("A fila nao esta vazia. ");
						}
						system("pause>>null");
                   		break;
                    	
                    case 3:
                    	
                    	i = filaCheia(&f1);
                    	if(i == 1)
                    	{
                    		printf("A fila esta totalmente cheia. ");
						}
						else
						{
							printf("A fila nao esta cheia. ");
						}
						system("pause>>null");
                   		break;
                       
                    case 4:
                       	printf ("Digite o nome:\n");
                    	scanf ("%s", temp.nome);
                    	printf ("Digite a matricula:\n");
                    	scanf ("%d", &temp.mat);
                    	printf ("Digite o saldo:\n");
                    	scanf ("%f", &temp.saldo);
                        enfileirar(&f1, temp);
                        system("pause>>null");
                   		break;
                    case 5:
                    	temp=desenfileirar(&f1);
                        printf("Nome removido: %s \n",temp.nome);
					    system("pause>>null");
                    	break;    	
                
                    case 6:
                    	esvaziarFila(&f1);
                    	system("pause>>null");
                    	break;
                    case 7:
                    	imprimirDesenfileirar(&f1);
                        system("pause>>null");
                    	break;
                    case 8: 
                    	imprimirAuxiliar (&f1, &f2);
                    	system("pause>>null");
                    	break;
                    
                }

        }
    }while(menu != -1);
    
    return 0;
}

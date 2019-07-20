

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 15
#include "aula.h"

typedef struct lista{
	ITEM item[tam];
	int ultimo;
};

void inicializar (Lista *lista){
	lista->ultimo=-1;
} //Incializa a lista com ultimo valendo -1
//fun��es para conferir se a lista est� cheia ou vazia
int vazia (Lista *lista){
	if (lista->ultimo==-1){
		return 1;
	}
	return 0;
}// a fun��o retorna um se for verdadeiro (vazia) e zero se for falso
int cheia (Lista *lista){
	if(lista->ultimo==tam-1){ //se a lista estiver cheia ela tem o tamanho=ultimo-1(come�a no zero)
		return 1;
	}
	return 0;
}

int inserir (Lista *lista, ITEM item){ //vai receber o elemento na lista mas � do tipo item com nome e pre�o
    //verificar se n�o est� cheia
	if (cheia(lista)){
		printf ("Lista Cheia!\n");
		return 0;
	}
	//se a lista n�o estiver cheia voce insere no final
	lista->item[lista->ultimo+1]=item; //lista->item na posi��o ultimo+1 recebe um elemento do tipo item
	lista->ultimo++; //aumentou uma posi��o 
	return 1;	
}

int inserirNaPosicao (Lista *lista, ITEM item, int k){
	//conferir se a posi��o existe
	if(k<0 || k>lista->ultimo){ //se o k for menor que zero ou maior que ultimo
		printf ("Posi��o n�o existe\n");
		return 0;
	}
	int i;
	for (i=k; i<=lista->ultimo; i++){ //tem que ser menor ou igual ao ultimo
		lista->item[i+1]=lista->item[i]; //item[5]=item[4]
	}
	lista->item[k]=item; //item[5]
	lista->ultimo++;
	return 1;
}

int removerNaPosicao (Lista *lista, int k){
	//verficiar se a lista n�o est� vazia e se posi��o existe
	if (vazia(lista) || k<0 || k>lista->ultimo){
		printf ("Inv�lido!\n");
		return 0;
	}
	int i;
	for(i=k; i<=lista->ultimo; i++){
		lista->item[i]=lista->item[i-1]; //item[6]=item[5]
	}
	lista->ultimo--;
	return 1;	
}

int tamanho (Lista *lista){
	return lista->ultimo+1; // se o ultimo vale -1 o tamanho da lista=0
}

ITEM maiorPreco (Lista *lista){
	int i;
	float maior=0;
	for(i=0; i<lista->ultimo; i++){
		if (lista->item[i].preco>maior){ //se o item verificado for maior que maior
			maior=lista->item[i].preco; //maior recebe item
		}
	}
	//a fun��o se cima s� serve para saber qual � o item
	//fazemos outro for para retornar o maior item
	for(i=0; i<lista->ultimo; i++){
		if(lista->item[i].preco==maior){ //se o pre�o do item na posi��o i for igual ao maior verificado no for anterior
			return lista->item[i]; //retorna o item nessa posicao
		}
	}
}

void imprimir (Lista *lista){
	int i;
	for(i=0; i<lista->ultimo+1; i++){
		printf ("Nome: %s\n", lista->item[i].nome);
		printf ("Pre�o: %.2f\n", lista->item[i].preco);
	}
}

ITEM cadastrarItem (){ //retorna um tipo item
	ITEM item;
	printf ("Digite o nome do item\t");
	scanf ("%s", item.nome);
	printf ("Digite o pre�o\t");
	scanf ("%f", &item.preco); 
	return item;
}


int main (){
	ITEM novo;
	//alocar a memoria dinamicamente
	Lista *lista;
	lista=(Lista*)malloc(sizeof(Lista));
	if(lista==NULL){
		printf ("N�o foi poss�vel alocar a mem�ria");
		exit (1);
	}
	int n, k;
	do{
		
		printf("1- Inicilizar\n");
		printf("2- Inserir item no final\n");
		printf("3- Inserir na posi��o k\n");
		printf("4- Remover item da posi��o k\n");
		printf("5- Verificar tamanho\n");
		printf("6- Retornar item com maior pre�o\n");
		printf("7- Imprimir\n");
		printf("8- Sair do programa\n");
		scanf ("%d", &n);
		switch (n){
			case 1:
				inicializar(lista);
				printf ("Lista Incializada!\n");
				break;
			case 2:
				novo=cadastrarItem();
				inserir(lista, novo);
				printf ("Elemento inserido!\n");
				break;
			case 3:
				novo=cadastrarItem();
				printf ("Digite a posi��o\n");
				scanf ("%d", &k);
				inserirNaPosicao(lista, novo, k);
				printf ("Elemento inserido!\n");
				break;
			case 4:
				printf ("Digite a posi��o\n");
				scanf ("%d", &k);	
				removerNaPosicao(lista, k);
				printf ("Item Removido\n");
				break;
			case 5:
			    printf ("%d", tamanho(lista));
				break;
			case 6:
			    novo=maiorPreco(lista);
				printf ("%s\n%.2f", novo.nome, novo.preco);
				break;
			case 7:
			    imprimir(lista);
				break;
			case 8:
			    exit (1);		
		}
	}while (n!=8);
	free(lista);
	system ("pause>>null");
	return 0;
}


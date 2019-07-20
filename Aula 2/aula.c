

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
//funções para conferir se a lista está cheia ou vazia
int vazia (Lista *lista){
	if (lista->ultimo==-1){
		return 1;
	}
	return 0;
}// a função retorna um se for verdadeiro (vazia) e zero se for falso
int cheia (Lista *lista){
	if(lista->ultimo==tam-1){ //se a lista estiver cheia ela tem o tamanho=ultimo-1(começa no zero)
		return 1;
	}
	return 0;
}

int inserir (Lista *lista, ITEM item){ //vai receber o elemento na lista mas é do tipo item com nome e preço
    //verificar se não está cheia
	if (cheia(lista)){
		printf ("Lista Cheia!\n");
		return 0;
	}
	//se a lista não estiver cheia voce insere no final
	lista->item[lista->ultimo+1]=item; //lista->item na posição ultimo+1 recebe um elemento do tipo item
	lista->ultimo++; //aumentou uma posição 
	return 1;	
}

int inserirNaPosicao (Lista *lista, ITEM item, int k){
	//conferir se a posição existe
	if(k<0 || k>lista->ultimo){ //se o k for menor que zero ou maior que ultimo
		printf ("Posição não existe\n");
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
	//verficiar se a lista não está vazia e se posição existe
	if (vazia(lista) || k<0 || k>lista->ultimo){
		printf ("Inválido!\n");
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
	//a função se cima só serve para saber qual é o item
	//fazemos outro for para retornar o maior item
	for(i=0; i<lista->ultimo; i++){
		if(lista->item[i].preco==maior){ //se o preço do item na posição i for igual ao maior verificado no for anterior
			return lista->item[i]; //retorna o item nessa posicao
		}
	}
}

void imprimir (Lista *lista){
	int i;
	for(i=0; i<lista->ultimo+1; i++){
		printf ("Nome: %s\n", lista->item[i].nome);
		printf ("Preço: %.2f\n", lista->item[i].preco);
	}
}

ITEM cadastrarItem (){ //retorna um tipo item
	ITEM item;
	printf ("Digite o nome do item\t");
	scanf ("%s", item.nome);
	printf ("Digite o preço\t");
	scanf ("%f", &item.preco); 
	return item;
}


int main (){
	ITEM novo;
	//alocar a memoria dinamicamente
	Lista *lista;
	lista=(Lista*)malloc(sizeof(Lista));
	if(lista==NULL){
		printf ("Não foi possível alocar a memória");
		exit (1);
	}
	int n, k;
	do{
		
		printf("1- Inicilizar\n");
		printf("2- Inserir item no final\n");
		printf("3- Inserir na posição k\n");
		printf("4- Remover item da posição k\n");
		printf("5- Verificar tamanho\n");
		printf("6- Retornar item com maior preço\n");
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
				printf ("Digite a posição\n");
				scanf ("%d", &k);
				inserirNaPosicao(lista, novo, k);
				printf ("Elemento inserido!\n");
				break;
			case 4:
				printf ("Digite a posição\n");
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




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sItem{
	char nome[20];
	float preco;
}ITEM;

typedef struct lista Lista;

void inicializar (Lista *lista);
int vazia (Lista *lista);
int cheia (Lista *lista);
int inserir (Lista *lista, ITEM item);
int inserirNaPosicao (Lista *lista, ITEM item, int k);
int removerNaPosicao (Lista *lista, int k);
int tamanho (Lista *lista);
ITEM maiorPreco (Lista *lista);
void imprimir (Lista *lista);
ITEM cadastrarItem ();

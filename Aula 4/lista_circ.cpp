#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
	char nome[30];
	float saldo;
}CLIENTE;

typedef struct sCell{
	struct sCell *prev;
	CLIENTE info;
	struct sCell *next;
}CELULA;

void inicializa (CELULA **lista){
	(*lista)=NULL;
}

int listaVazia (CELULA **lista){
	if((*lista)==NULL){
		return 1;
	}
	return 0;
}

CELULA* criarCelula(){
	CELULA *nova;
	nova=(CELULA*)malloc(sizeof(CELULA));
	return nova;
}

CLIENTE preenche (){
	CLIENTE info;
	printf ("Digite o nome\n");
	scanf ("%s", info.nome);
	printf ("Digite o saldo devedor\n");
	scanf ("%f", &info.saldo);
	return info;
}

int inserirFim (CELULA **lista){
	CELULA *nova;
	CELULA *aux;
	nova=criarCelula();
	if (criarCelula==NULL){
		printf ("Memória cheia!\n");
		return 0;
	}
	nova->info=preenche();
	nova->next=NULL;
	nova->prev=NULL;
	if (listaVazia(lista)){
		(*lista)=nova;
		return 1;
	}
	aux=(*lista);
	while(aux->next!=NULL){
		aux=aux->next;
	}
	nova->prev=aux;
	aux->next=nova;
	return 1;
}

int inserirInicio (CELULA **lista){
	CELULA *nova;
	nova=criarCelula();
	if (criarCelula==NULL){
		printf ("Memória cheia!\n");
		return 0;
	}
	if (listaVazia(lista)){
		return inserirFim(lista);
	}
	nova->prev=NULL;
	nova->info=preenche();
	nova->next=(*lista);
	(*lista)->prev=nova;
	(*lista)=nova;
	return 1;
}

void imprimirElemento(CLIENTE cliente){
	printf("NOME:\n%s", cliente.nome);
	printf ("SALDO DEVEDOR:%.2f\n", cliente.saldo);
}

void imprimirInicio (CELULA **lista){
	CELULA *aux=(*lista);
	if(listaVazia(lista)){
		printf ("Lista vazia!\n");
	}else{
		aux=(*lista);
		do{
			imprimirElemento(aux->info);
			aux=aux->next;
		}while(aux != NULL);
		printf ("\n");
	}
}


void imprimirFim (CELULA **lista){
	CELULA *aux=(*lista);
	if(listaVazia(lista)){
		printf ("Lista vazia!\n");
	}else{
		aux=(*lista);
		while(aux->next != NULL){
			aux=aux->next;
		}
		while(aux!=NULL){
			imprimirElemento(aux->info);
			aux=aux->prev;
		}		
	}
}

CELULA* buscar (CELULA **lista){
	CELULA *aux;
	CLIENTE elemento;
	printf ("Digite o nume do cliente\n");
    scanf ("%s", elemento.nome);
    aux=(*lista);
	while(aux!=NULL){
		if(strcmp(elemento.nome, aux->info.nome)==0){
			return aux;
		}
		aux=aux->next;
	}
	return NULL;
}

CLIENTE removerInicio (CELULA **lista){
	CELULA *removida;
	CLIENTE removido;
	strcpy(removido.nome, " ");
	removido.saldo=-1;
	if (listaVazia(lista)){
		printf ("Lista Vazia/n");
		return removido;
	}
	removida=(*lista);
	removido=removida->info;
	(*lista)=(*lista)->next;
	if((*lista)!=NULL){
		(*lista)->prev=NULL;
	}
	free(removida);
	return removido;
}

CLIENTE removerFinal (CELULA **lista){
	CELULA *removida;
	CELULA *anterior;
	CLIENTE removido;
	strcpy(removido.nome, " ");
	removido.saldo=-1;
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


int liberarLista (CELULA **lista){ 
	do{
		removerFinal(lista);
	}while (listaVazia(lista) != 1);
}

int main(){
	CELULA *ptrlista;
	CELULA *nova;
	char nome[20];
	int menu;
	CLIENTE elemento;
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar Lista");
        printf("\n2-Inserir item no inicio");
        printf("\n3-Inserir item no fim");
        printf("\n4-Imprimir lista pelo inicio");
        printf("\n5-Imprimir lista pelo final");
        printf("\n6-Buscar um elemento");
        printf("\n7-Remover do Inicio");
        printf("\n8-Remover do final");
        printf("\n9-Liberar lista");
        printf("\n10- para fechar o programa\n");
        scanf("%d", &menu);
        
                switch(menu){
                    case 1:
                        inicializa(&ptrlista);
                        printf("\nLista Inicializada!");
                        system("pause");
                        break;
                    case 2:
                    	inserirInicio(&ptrlista);
                        printf("\nItem inserido com sucesso\n");
                        system("pause");
                        break;
                    case 3:
                    	inserirFim(&ptrlista);
                        printf("\nItem inserido com sucesso\n");
                        system("pause");             	
                        break;
                    case 4:
                        imprimirInicio(&ptrlista);
                        system("pause");
                        break;
                    
                    case 5:
                    	imprimirFim(&ptrlista);
                    	system("pause");   
                        break;
                    
                    case 6:
                    	nova=buscar(&ptrlista);
                        if(nova!=NULL){
                        	printf ("saldo devedor do cliente: %.2f\n", nova->info.saldo);
						}else{
							printf("Cliente não encontrado\n");
						}
                        system("pause");
                         break; 
					case 7:
						removerInicio(&ptrlista);
						printf("elemento removido!\n");
						system("pause");           
				     	break;
				    case 8:
				    	removerFinal(&ptrlista);
						printf("elemento removido!\n");
						system("pause");
				    	break;
				    case 9:
				    	liberarLista(&ptrlista);
						printf("lista liberada!\n");
						system("pause");
				    	break;
                }

    }while(menu != 10);
	system("pause>>null");
	return 0;
}









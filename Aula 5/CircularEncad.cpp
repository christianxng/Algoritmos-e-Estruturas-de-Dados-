
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCell{
	char info[20];
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
	CELULA *nova=(CELULA*)malloc(sizeof(CELULA));
	return nova;
}

int inserirFim (CELULA **lista, char elemento[20]){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memoria cheia!\n");
		return 0;
	}
	strcpy(nova->info, elemento);
	if(listaVazia(lista)){
		nova->next=nova;
		(*lista)=nova;
		return 1;
	}
	nova->next=(*lista)->next;
	(*lista)->next=nova;
	(*lista)=nova;
	return 1;
}

int inserirInicio (CELULA **lista, char elemento[20]){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memoria cheia!\n");
		return 0;
	}
	if(listaVazia(lista)){
		return inserirFim(lista, elemento);
	}
	strcpy(nova->info, elemento);
	nova->next=(*lista)->next;
	(*lista)->next=nova;
	return 1;
}

char removerFim (CELULA **lista){
	CELULA *removida;
	CELULA *aux;
	char x[20];
	strcpy(x, "invalido");
	if(listaVazia(lista)){
		return x[20];
	}else{
	removida=(*lista);
	aux=(*lista)->next;
	strcpy(removida->info, x);
	if((*lista)->next==(*lista)){
		inicializa(lista);
	}else{
		while(aux->next != (*lista)){
			aux=aux->next;
		}
		aux->next=(*lista)->next;
		(*lista)=aux;
	}
	free(removida);
	return x[20];
    }
}

char removerInicio (CELULA **lista){
	CELULA *removida;
	char x[20];
	strcpy(x, "  ");
	if(listaVazia(lista)){
		return x[20];
	}
	removida=(*lista)->next;
	strcpy(removida->info, x);
	if((*lista)->next==(*lista)){
		inicializa(lista);
	}else{
		(*lista)->next=removida->next;
	}
	free(removida);
	return x[20];
}

void imprimirElemento(char elemento[20]){
	printf("%s", elemento);
}

void imprimirLista (CELULA **lista){
	CELULA *aux=(*lista);
	if(listaVazia(lista)){
		printf ("Lista vazia!\n");
	}else{
		aux=(*lista)->next;
		do{
			imprimirElemento(aux->info);
			aux=aux->next;
		}while(aux != (*lista)->next);
		printf ("\n");
	}
}

int liberarLista (CELULA **lista){ 
	do{
		removerFim(lista);
	}while (listaVazia(lista) != 1);
}

int main(){
	CELULA *ptrlista;
	int menu;
	char elemento[20];
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar Lista");
        printf("\n2-Inserir item no inicio");
        printf("\n3-Inserir item no final");
        printf("\n4-Remover item do inicio");
        printf("\n5-Remover item do final");
        printf("\n6-Imprimir lista");
        printf("\n7-Liberar lista");
        printf("\n8- para fechar o programa\n");
        scanf("%d", &menu);
        
                switch(menu){
                    case 1:
                        inicializa(&ptrlista);
                        printf("\nLista Inicializada!");
                        system("pause");
                        break;
                    case 2:
                    	printf("\nDigite o nome do produto");
                    	scanf("%s", elemento);
                        inserirInicio(&ptrlista, elemento);
                        printf("\nItem inserido com sucesso");
                        system("pause");
                        break;
                    case 3:
                    	printf("\nDigite o nome do produto");
                    	scanf("%s", elemento);
						inserirFim(&ptrlista, elemento);
                        printf("\nItem inserido com sucesso");
                        system("pause");
                                     	
                        break;
                    
                    case 4:
                        removerInicio(&ptrlista);
                        system("pause");
                        break;
                    
                    case 5:
                    	removerFim(&ptrlista);
                    	system("pause");   
                        break;
                    
                    case 6:
                        imprimirLista(&ptrlista);
                        system("pause");
                         break; 
					
					case 7:
						liberarLista(&ptrlista);
						system("pause");           
				     	break;
                }

    }while(menu != 8);
	system("pause>>null");
	return 0;
}

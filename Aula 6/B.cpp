

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct revista{
	char nome[30];
	int pag;
	char categoria[30];
}REVISTA;

typedef struct sCell{
	REVISTA info;
	struct sCell *next;
}CELULA;

void inicializar (CELULA **pilha){
	(*pilha)=NULL;
}

int vazia (CELULA **pilha){
	if((*pilha)==NULL){
		return 1;
	}
	return 0;
}

CELULA *criarCelula(){
	CELULA *nova=(CELULA*) malloc (sizeof(CELULA));
	return nova;
}

//empilhar
int push (CELULA **pilha, REVISTA elemento){
	CELULA *nova;
	nova=criarCelula();
	if(nova==NULL){
		printf("Memória Cheia!\n");
		return 0;
	}
	if(vazia(pilha)){
	    nova->info=elemento;
		nova->next=NULL;
		(*pilha)=nova;
	    return 1;
		}
	nova->info=elemento;
	nova->next=(*pilha);
	(*pilha)=nova;	
	return 1;
}

//desempilhar
REVISTA pop (CELULA **pilha){
	CELULA *removida;
	REVISTA removido;
	strcpy(removido.nome, "Inválido");
	removido.pag=-1;
	strcpy(removido.categoria, "Inválido");
	if(vazia(pilha)){
		printf("Pilha Vazia!\n");
		return removido;
	}
	removida=(*pilha);
	removido=removida->info;
	(*pilha)=(*pilha)->next;
	free(removida);
	return removido;
}

REVISTA topo (CELULA **pilha){
	CELULA *aux;
	REVISTA topo;
	strcpy(topo.nome, "Inválido");
	topo.pag=-1;
	strcpy(topo.categoria, "Inválido");
	if(vazia(pilha)){
		printf("Lista Vazia!\n");
		return topo;
	}
	aux=(*pilha);
	topo=aux->info;
	return topo;
}

void imprimirtopo (CELULA **pilha){
	   	if(vazia(pilha)){
	    	printf ("Pilha vazia\n");
	    	return;
		}
		printf ("Nome: %s\n", (*pilha)->info.nome);
		printf ("Páginas: %d\n", (*pilha)->info.pag);
		printf ("Categoria: %s\n\n\n", (*pilha)->info.categoria);
}

void imprimir (CELULA **pilha){
	   if(vazia(pilha)){
	    	printf ("Pilha vazia\n");
	    	return;
	}
	while ((*pilha) != NULL){
		imprimirtopo(pilha);
		pop(pilha);
	}
}

void imprimir2 (CELULA **pilha, CELULA **pilha2){
	inicializar(pilha2);
	REVISTA aux;
	if(vazia(pilha)){
	    	printf ("Pilha vazia\n");
	    	return;
	}
	while (!vazia(pilha)){
		aux=pop(pilha);
		printf ("Nome: %s\n", aux.nome);
		printf ("Páginas: %d\n", aux.pag);
		printf ("Categoria: %s\n\n", aux.categoria);
		push(pilha2, aux);
	}
	while(!vazia(pilha2)){
		aux=pop(pilha2);
		push(pilha, aux);
	}
}

int main(){
	REVISTA temp;
	CELULA *P1, *P2;
	int menu;
	 do{
        system("cls");
        printf("\nDigite o numero para realizar uma operacao");
        printf("\n1-Inicializar pilha");
        printf("\n2-Empilhar na pilha");
        printf("\n3-Desempilhar da pilha");
        printf("\n4-Imprimir pilha desempilhando");
        printf("\n5-Imprimir pilha");
        printf("\n6-Imprimir topo");
        printf("\n(-1 para fechar o programa)\n");
        scanf("%d", &menu);
        if(menu != -1){
                switch(menu){
                    case 1:
                        inicializar(&P1);
                        printf("\nLista Inicializada!\n");
                        system("pause>>null");
                   		break;
                    case 2:
                    	printf ("Digite o nome\n");
                    	scanf("%s", temp.nome);
                    	printf ("Digite o numero de paginas\n");
                    	scanf("%d", &temp.pag);
                     	printf ("Digite a categoria\n");
                     	scanf("%s", temp.categoria);
                        push(&P1, temp);
                        system("pause>>null");
                   		break;
                    case 3:
                        temp=pop(&P1);
                        printf("Nome removido: %s \nCategoria: %s\n",temp.nome,temp.categoria);
					    system("pause>>null");
                    	break;
                    case 4:
                        imprimir(&P1);
                        system("pause>>null");
                    	break;
                    case 5:
						imprimir2(&P1, &P2);
                        system("pause>>null");
                    	break;
                    case 6:
                    	imprimirtopo(&P1);
                    	system("pause>>null");
                    	break;
                }

        }
    }while(menu != -1);

}

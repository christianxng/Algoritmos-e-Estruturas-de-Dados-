
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct revista{
	char nome[30];
	int pag;
	char categoria[30];
}REVISTA;

typedef struct pilha{
	REVISTA info[10];
	int topo;
}PILHA;

void inicializar (PILHA *pilha){
	pilha->topo=-1;
}

int vazia (PILHA *pilha){
	if(pilha->topo==-1){
		return 1;
	}
	return 0;
}

int cheia (PILHA *pilha){
	if(pilha->topo==9){
		return 1;
	}
	return 0;
}


int push (PILHA *pilha, REVISTA elemento){
	if(cheia(pilha)){
		printf("Pilha Cheia!\n");
		return 0;
	}
	pilha->info[pilha->topo+1]=elemento;
	pilha->topo++;
	return 1;
}


REVISTA pop (PILHA *pilha){
	REVISTA removido;
	strcpy(removido.nome, "Inválido");
	removido.pag=-1;
	strcpy(removido.categoria, "Inválido");
	if(vazia(pilha)){
		printf("Pilha Vazia!\n");
		return removido;
	}
	removido=pilha->info[pilha->topo];
	pilha->topo--;
	return removido;
}

REVISTA topo (PILHA *pilha){
	REVISTA topo;
	strcpy(topo.nome, "Inválido");
	topo.pag=-1;
	strcpy(topo.categoria, "Inválido");
	if(vazia(pilha)){
		printf("Lista Vazia!\n");
		return topo;
	}
	topo=pilha->info[pilha->topo];
	return topo;
}

void imprimir (PILHA *pilha){
	while (pilha->topo != -1){
		printf ("Nome: %s\n", pilha->info[pilha->topo].nome);
		printf ("Páginas: %d\n", pilha->info[pilha->topo].pag);
		printf ("Categoria: %s\n\n\n", pilha->info[pilha->topo].categoria);
		pop(pilha);
	}
}

void imprimirtopo (PILHA *pilha){
	    if(vazia(pilha)){
	    	printf ("Pilha vazia\n");
	    	return;
		}
		printf ("Nome: %s\n", pilha->info[pilha->topo].nome);
		printf ("Páginas: %d\n", pilha->info[pilha->topo].pag);
		printf ("Categoria: %s\n", pilha->info[pilha->topo].categoria);
}

void encher (PILHA *pilha, PILHA *pilha2){
	pilha2->info[pilha2->topo+1]=pilha->info[pilha->topo];
	pilha2->topo++;
}

void imprimir2 (PILHA *pilha, PILHA *pilha2){
	REVISTA aux;
	inicializar(pilha2);
	while (pilha->topo != -1){
		aux=pop(pilha);
		printf ("Nome: %s\n", aux.nome);
		printf ("Páginas: %d\n", aux.pag);
		printf ("Categoria: %s\n\n", aux.categoria);
		push(pilha2, aux);
	}
	while(pilha2->topo != -1){
		aux=pop(pilha2);
		push(pilha, aux);
	}
}


int main(){
	REVISTA temp;
	PILHA P1, P2;
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

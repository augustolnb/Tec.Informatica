#include<stdio.h>
#include<stdlib.h>

typedef struct t{	//Declara uma struct do tipo Item, o comando typedef permite criar um novo tipo de dado, nesse caso o tipo é Item
	int valor;
	struct t *prox;
}Item;

typedef struct{		//Declara a struct da lista, onde serão inseridos os Itens 
	Item *inicio;
	int quant;
}Lista;

void inicializa(Lista *lista){	//Inicializa a lista, ou seja, zera seus valores p/ poder iniciar a inserção
	lista->inicio = NULL; 		//Aponta o inicio para NULL
	lista->quant = 0;			//Zera a quantidade de itens na lista
}

int insereInicio(Lista *lista, int valor){ 		//Função que insere um item no inicio da lista
	Item *novo, *aux;							//Cria um ponteiro para o novo item e um ponteiro auxiliar
	
	novo = (Item*)malloc(sizeof(Item));			//Aloca o espaço na memoria para o novo item. Sintaxe: novo_item = (nome_do_tipo*)malloc(sizeof(nome_do_tipo));
	novo->valor = valor;						//Pega o valor que foi digitado e copia para o campo valor do item novo
	
	if(lista->inicio == NULL){					//Caso a lista esteja vazio o inicio da lista sera NULL
		lista->inicio = novo;					//Poe o item novo como inicio da lista
		novo->prox = NULL;						//Seta o proximo do novo item como NULL
		return lista->quant++;					//Retorna para o bloco main a quantidade de itens na lista
	}
	//Caso a lista não esteja vazia o inicio sera diferente de NULL e não entrará no if acima
   aux = lista->inicio;							//Seta o ponteiro aux para guardar a primeira posição da lista, ou seja, o inicio da lista
   lista->inicio = novo;						//O inicio da lista recebe o novo item
   novo->prox = aux;							//Seta o proximo do novo item(inicio da lista) como o antigo inicio(guardado em aux)
   return lista->quant++;   					//Retorna para o bloco main a quantidade de itens na lista
}

void imprime(Lista lista){
	Item *ptr;									//Cria um ponteiro para percorrer a lista
	int i=1;
	
	ptr = lista.inicio;							//Aponta esse ponteiro para o inicio da lista
	while(ptr != NULL){							//Enquanto o ponteiro for diferente de NULL ele imprime e passa para o proximo item
		printf("Posicao: %i\tValor: %i", i, ptr->valor);	//Imprime
		i++;
		ptr = ptr->prox;						//Passa para o proximo item
		printf("\n");
	}
}

int main(void){
	Lista lista;
	int i, valor;
	
	inicializa(&lista);
	
	printf("Complete a lista: "); 
	for(i=0;i<5;i++){
		scanf("%i", &valor);
		insereInicio(&lista, valor);
	}
	imprime(lista);
	
}
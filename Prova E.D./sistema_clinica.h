// estrutura com dados do paciente
typedef struct pac{
	char nome[30];
	int idade;
	char sintomas[30];
	struct pac *prox;
}paciente;

//estrutura da lista
typedef struct{
	paciente *inicio;
	int quant;
}Lista;

//função que inicializa a lista
void inicializa(Lista *lista){
	lista->inicio = NULL;
	lista->quant = 0;
}

int veri_menu(char *ch){
	int i; //i = unidade, d = dezena

	if(ch[0] == '\n' || ch[0] == '\0')
		return -1;

	if(ch[0] >= 48 && ch[0] <= 52){

		if(ch[0] != '\n' || ch[0] != '\0'){
			if(ch[0] == '0')
				i=0;
			if(ch[0] == '1')
				i=1;
			if(ch[0] == '2')
				i=2;
			if(ch[0] == '3')
				i=3;
			if(ch[0] == '4')
				i=4;
			return i;
		}
	}
	else
		return -1;
}


//função que gera o menu e retorna a opção escolhida
int menu(){
	int i=NULL;
	char ch;

	__fpurge(stdin);
	fflush(stdin);
	system("clear");
	printf("1->Registrar chegada\n2->Chamar paciente\n3->Consultas\n4->Encerrar atendimento\n0->Ver Listas\n-> ");
    ch = getchar();
    i = veri_menu(&ch);
    system("clear");

    while(i == -1){
    	printf("\tOpcao invalida\n");
   		printf("1->Registrar chegada\n2->Chamar paciente\n3->Consultas\n4->Encerrar atendimento\n0->Ver Listas\n-> ");
    	ch = getchar();
    	i = veri_menu(&ch);
   	    system("clear");
    }

	printf("\n");


	__fpurge(stdin);
	fflush(stdin);
	return i;
}

//Insere o paciente no final da lista de espera
int inserir(Lista *lista, char *nome, int idade, char *sintomas){
	paciente *novo, *ptr;
	int n, s, i;

	novo = (paciente*)malloc(sizeof(paciente));
	novo->idade = idade;
	n = strlen(nome);
	s = strlen(sintomas);

	for(i=0;i<n;i++)
		novo->nome[i] = nome[i];
	
	for(i=0;i<s;i++)
		novo->sintomas[i] = sintomas[i];


	if(lista->inicio == NULL){
		lista->inicio = novo;
		novo->prox = NULL;
		lista->quant++;
		return lista->quant;
	}

	ptr = lista->inicio;

	while(ptr->prox != NULL)
		ptr = ptr->prox;

	ptr->prox = novo;
	novo->prox = NULL;

	lista->quant++;
	return lista->quant;
}

// Encaminha paciente para o 1° médico
int chamar_med1(Lista *lista, Lista *med1){
	paciente *ptr, *aux;

	if(lista->inicio == NULL)
		return -1;

	if(lista->inicio->prox == NULL){
		if(med1->inicio == NULL){
			med1->inicio = lista->inicio;
			lista->inicio = NULL;
			lista->quant--;
			med1->quant++;
			return med1->quant;
		}
		aux = med1->inicio;

		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = lista->inicio;
		lista->inicio = NULL;
		lista->quant--;
		med1->quant++;
		return med1->quant;
	}

	if(med1->inicio == NULL){
		med1->inicio = lista->inicio;
		lista->inicio = lista->inicio->prox;
		med1->inicio->prox = NULL;
		lista->quant--;
		med1->quant++;
		return med1->quant;
	}

	aux = med1->inicio;
	while(aux->prox != NULL)
		aux = aux->prox;

	aux->prox = lista->inicio;
	lista->inicio = lista->inicio->prox;
	aux = aux->prox;
	aux->prox = NULL;
	lista->quant--;
	med1->quant++;
	return med1->quant;
}

// Encaminha paciente para o 2° médico
int chamar_med2(Lista *lista, Lista *med2){
	paciente *ptr, *aux;

	if(lista->inicio == NULL)
		return -1;

	if(lista->inicio->prox == NULL){
		if(med2->inicio == NULL){
			med2->inicio = lista->inicio;
			lista->inicio = NULL;
			lista->quant--;
			med2->quant++;
			return med2->quant;
		}
		aux = med2->inicio;

		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = lista->inicio;
		lista->inicio = NULL;
		lista->quant--;
		med2->quant++;
		return med2->quant;
	}

	if(med2->inicio == NULL){
		med2->inicio = lista->inicio;
		lista->inicio = lista->inicio->prox;
		med2->inicio->prox = NULL;
		lista->quant--;
		med2->quant++;
		return med2->quant;
	}

	aux = med2->inicio;
	while(aux->prox != NULL)
		aux = aux->prox;

	aux->prox = lista->inicio;
	lista->inicio = lista->inicio->prox;
	aux = aux->prox;
	aux->prox = NULL;
	lista->quant--;
	med2->quant++;
	return med2->quant;
}

// Encaminha paciente para o 3° médico
int chamar_med3(Lista *lista, Lista *med3){
	paciente *ptr, *aux;

	if(lista->inicio == NULL)
		return -1;

	if(lista->inicio->prox == NULL){
		if(med3->inicio == NULL){
			med3->inicio = lista->inicio;
			lista->inicio = NULL;
			lista->quant--;
			med3->quant++;
			return med3->quant;
		}
		aux = med3->inicio;

		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = lista->inicio;
		lista->inicio = NULL;
		lista->quant--;
		med3->quant++;
		return med3->quant;
	}

	if(med3->inicio == NULL){
		med3->inicio = lista->inicio;
		lista->inicio = lista->inicio->prox;
		med3->inicio->prox = NULL;
		lista->quant--;
		med3->quant++;
		return med3->quant;
	}

	aux = med3->inicio;
	while(aux->prox != NULL)
		aux = aux->prox;

	aux->prox = lista->inicio;
	lista->inicio = lista->inicio->prox;
	aux = aux->prox;
	aux->prox = NULL;
	lista->quant--;
	med3->quant++;
	return med3->quant;
}

// imprime a lista de todos os medicos
void imprime_med(Lista med1, Lista med2, Lista med3){
	paciente *ptr;
	int i1=1, i2=1, i3=1;
	char c = '0';


	ptr = med1.inicio;
	printf("\n-->  LISTA DO MÉDICO 1  <--\n\n");
	while(ptr != NULL){
		printf("# Paciente %d\n", i1);
		printf("--> Nome: %s--> Idade: %d\n--> Sintomas: %s", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
		printf("\n");
		i1++;
	}
	printf("+---------------------------+\n\n");


	ptr = med2.inicio;
	printf("\n-->  LISTA DO MÉDICO 2  <--\n\n");
	while(ptr != NULL){
		printf("# Paciente %d\n", i2);
		printf("--> Nome: %s--> Idade: %d\n--> Sintomas: %s", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
		printf("\n");
		i2++;
	}
	printf("+---------------------------+\n\n");

	ptr = med3.inicio;
	printf("\n-->  LISTA DO MÉDICO 3  <--\n\n");
	while(ptr != NULL){
		printf("# Paciente %d\n", i3);
		printf("--> Nome: %s--> Idade: %d\n--> Sintomas: %s", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
		printf("\n");
		i3++;
	}
	printf("+---------------------------+\n\n");
	while(c == '0'){
		printf("Pressione alguma tecla ");
		c = getchar();
	}
}

// Imprime a lista de espera
void imprime(Lista lista){
	paciente *ptr;
	int i=1;
	ptr = lista.inicio;
	char c = '0';

	printf("\n-->  LISTA DE ESPERA  <--\n\n");
	while(ptr != NULL){
		printf("# Paciente %d\n", i);
		printf("--> Nome: %s--> Idade: %d\n--> Sintomas: %s", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
		printf("\n");
		i++;
	}
	while(c == '0'){
		printf("Pressione alguma tecla ");
		c = getchar();
	}
}

// Imprime o menu de consultas
int consultas(){
	int i=NULL;

	__fpurge(stdin);
	fflush(stdin);
	system("clear");
	printf("1-> Quantidade de pacientes na lista de espera\n2-> Quantidade de pacientes em espera\n3-> Pesquisar paciente\n-> ");

	scanf("%d", &i);
	printf("\n");
	__fpurge(stdin);
	fflush(stdin);
	return i;
}

// Faz a contagem de quantas pessoas ainda estão na lista de espera
int cont_espera(Lista *lista){
	paciente *ptr;
	int cont=0;

	ptr = lista->inicio;

	while(ptr != NULL){
		cont++;
		ptr = ptr->prox;
	}
	return cont;
}

// Faz a contagem de quantas pessoas ja foram atendidas
int cont_atendidos(Lista *med1, Lista *med2, Lista *med3){
	paciente *ptr;
	int cont=0;

	ptr = med1->inicio;
	while(ptr != NULL){
		cont++;
		ptr = ptr->prox;
	}

	ptr = med2->inicio;
	while(ptr != NULL){
		cont++;
		ptr = ptr->prox;
	}

	ptr = med3->inicio;
	while(ptr != NULL){
		cont++;
		ptr = ptr->prox;
	}
	return cont;
}

// Pesquisa um paciente pelo nome e retorna o seu estado(atendido, em espera ou inexistente)
int pesq_paciente(Lista *lista, Lista *med1, Lista *med2, Lista *med3, char *nome){
	paciente *ptr;
	int controle=0;

	while(controle == 0){
		ptr = lista->inicio;
		while(ptr != NULL){
			if(strcmp(ptr->nome, nome) == 0)
				return 1;
			ptr = ptr->prox;
		}

		ptr = med1->inicio;
		while(ptr != NULL){
			if(strcmp(ptr->nome, nome) == 0)
				return 2;
			ptr = ptr->prox;
		}

		ptr = med2->inicio;
		while(ptr != NULL){
			if(strcmp(ptr->nome, nome) == 0)
				return 2;
			ptr = ptr->prox;
		}

		ptr = med3->inicio;
		while(ptr != NULL){
			if(strcmp(ptr->nome, nome) == 0)
				return 2;
			ptr = ptr->prox;
		}
		controle = 1;
	}
	return 0;
}

// Salva as listas dos médicos em um arquivo
void salvar(Lista *med1, Lista *med2, Lista *med3){
	FILE *arq;
	paciente *ptr;

	arq = fopen("arquivo.txt", "w");

	if(arq == NULL)
		printf("\n\t\tERRO!\n\n");

	fprintf(arq, "+---Médico 1---+\n");
	ptr = med1->inicio;
	while(ptr != NULL){
		fprintf(arq, "Nome: %sIdade: %d\nSintomas: %s\n", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
	}
	fprintf(arq, "+--------------+\n\n\n");


	fprintf(arq, "+---Médico 2---+\n");
	ptr = med2->inicio;
	while(ptr != NULL){
		fprintf(arq, "Nome: %sIdade: %d\nSintomas: %s\n", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
	}
	fprintf(arq, "+--------------+\n\n\n");


	fprintf(arq, "+---Médico 3---+\n");
	ptr = med3->inicio;
	while(ptr != NULL){
		fprintf(arq, "Nome: %sIdade: %d\nSintomas: %s\n", ptr->nome, ptr->idade, ptr->sintomas);
		ptr = ptr->prox;
	}
	fprintf(arq, "+--------------+\n\n\n");

	fclose(arq);
}

// Converte números em formato string para números em formato int
int converte(char *num){
	int i, d; //i = unidade, d = dezena

	if(num[0] == '\n' || num[0] == '-')
		return -1;

	if(num[0] >= 48 && num[0] <= 57 || num[1] >= 48 && num[1] <= 57){

		if(num[1] == '\n'){
			if(num[0] == '0')
				i=0;
			if(num[0] == '1')
				i=1;
			if(num[0] == '2')
				i=2;
			if(num[0] == '3')
				i=3;
			if(num[0] == '4')
				i=4;
			if(num[0] == '5')
				i=5;
			if(num[0] == '6')
				i=6;
			if(num[0] == '7')
				i=7;
			if(num[0] == '8')
				i=8;
			if(num[0] == '9')
				i=9;
			return i;
		}

		if(num[2] == '\0'){
			if(num[1] == '0')
				i=0;
			else if(num[1] == '1')
				i=1;
			else if(num[1] == '2')
				i=2;
			else if(num[1] == '3')
				i=3;
			else if(num[1] == '4')
				i=4;
			else if(num[1] == '5')
				i=5;
			else if(num[1] == '6')
				i=6;
			else if(num[1] == '7')
				i=7;
			else if(num[1] == '8')
				i=8;
			else if(num[1] == '9')
				i=9;
			//
			if(num[0] == '1'){
				d = 1 * 10;
				d = d + i;
			}
			else if(num[0] == '2'){
				d = 2 * 10;
				d = d + i;
			}
			else if(num[0] == '3'){
				d = 3 * 10;
				d = d + i;
			}
			else if(num[0] == '4'){
				d = 4 * 10;
				d = d + i;
			}
			else if(num[0] == '5'){
				d = 5 * 10;
				d = d + i;
			}
			else if(num[0] == '6'){
				d = 6 * 10;
				d = d + i;
			}
			else if(num[0] == '7'){
				d = 7 * 10;
				d = d + i;
			}
			else if(num[0] == '8'){
				d = 8 * 10;
				d = d + i;
			}
			else if(num[0] == '9'){
				d = 9 * 10;
				d = d + i;
			}
			else if(num[0] == '0'){
				d = 0 * 10;
				d = d + i;
			}
			return d;
		}
	}

	else
		return -1;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	int jog1[10][10], jog2[10][10], i, j, x, y, k, c1=0, c2=0, r=0, opcao, t, u, *p, v;

	printf("\n\n\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\t\t\t||||||                            Batalha Naval                             ||||||\n");
	printf("\t\t\t||||||                          By : Lucas Augusto                          ||||||\n");
	printf("\t\t\t||||||                                                                      ||||||\n");
	printf("\t\t\t||||||          1:Destroyer  2:Porta-Avioes  3:Submarino  4:Cruzador        ||||||\n");
	printf("\t\t\t||||||                       9:Agua   0:Navio Atigido                       ||||||\n");
	printf("\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");

	while(c1!=4 && c2!=4){

	srand(time(NULL)); // funcao para numeros aleatorios

	printf("Deseja usar o campo padrão (10x10) ? 0 p/ nao\t"); // Deixa a criterio do usuario usar a matriz 10x10 ou usar outra
	scanf("%d", &opcao);

if(opcao == 0){
	printf("\nInforme o novo tamanho do campo (x,y):  "); scanf("%d", &t); // Faz a alocacao dinamica da nova matriz
	printf("\t\t\t\t\t"); scanf("%d", &u);
	p=(int *)malloc(sizeof(t));
	p=(int *)malloc(sizeof(u));

	for(i=0;i<t;i++) // Inicializa as duas matrizes
	{
		for(j=0;j<u;j++)		{
			jog1[i][j] = 9;
			jog2[i][j] = 9;
		}
	}

v=1;
	for(k=1;k<5;k++) // Distribue os navios em posicoes aleatorias
	{
	x = rand() % t;
	y = rand() % u;
	jog1[x][y] = v;
	v++;
	}

v=1;
	for(k=1;k<5;k++) // Distribui os navios em posicoes aleatorias
        {
        x = rand() % t;
        y = rand() % u;
        jog2[x][y] = v;
	v++;
        }
	printf("\n\n");

	for(i=0;i<t;i++) // Printa a 1° matriz
        {
                for(j=0;j<u;j++)
                {
		printf("| %d |", jog1[i][j]);
                }
                printf("\n");
        }

	for(i=0;i<t;i++) // Printa a 2° matriz
        {
	printf("\t\t\t\t\t\t\t\t\t\t");
                for(j=0;j<u;j++)
                {
                printf("| %d |", jog2[i][j]);
                }
                printf("\n");
        }
	printf("\n\n\n");

	while(c1!=4 && c2!=4)	{
		printf("\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n");
		x = rand() % t;
		y = rand() % u;
		printf("Jogador 1 atirou na posicao: %d, %d", x, y);
		printf("\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n");
		if(jog2[x][y] == 1 || jog2[x][y] == 2 || jog2[x][y] == 3  || jog2[x][y] == 4)
		{
			jog2[x][y] = 0;
			c2++;
			printf("Jogador 1 acertou!\t\t\t\t\t\t\t||\n");
		}
		printf("\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t\t||\n");
		x = rand() % t;
		y = rand() % u;
		printf("\t\t\t\t\t\t\t\t\t||\t\tJogador 2 atirou na posicao: %d, %d", x, y);
		if(jog1[x][y] == 1 || jog1[x][y] == 2 || jog1[x][y] == 3  || jog1[x][y] == 4)
		{
		jog1[x][y] = 0;
			c1++;
		printf("\n\t\t\t\t\t\t\t\t\t||\t\tJogador 2 acertou!");
		}
	sleep(1); // Aguarda 1 segundo para reexecutar o laco
	r++; // Incrementa o contador das rodadas
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

	for(i=0;i<t;i++){
                for(j=0;j<u;j++){
                printf("| %d |", jog1[i][j]);
                }
                printf("\n");
        }
        printf("\n\n");

        for(i=0;i<t;i++){
                for(j=0;j<u;j++){
                printf("| %d |", jog2[i][j]);
                }
                printf("\n");
        }
        printf("\n\n\n");

	if(c2 == 4)
        printf("\n\t\t\t\t\t\t\t\tJogador 1 ganhou!!\n");

        if(c1 == 4)
        printf("\n\t\t\t\t\t\t\t\tJogador 2 ganhou!!\n");

        printf("\t\t\t\t\t\t\t\t%d jogadas\n\n", r);
        return(0);
}
else{

	// Tratamento da matriz do 1 jogador
	for(i=0;i<10;i++) // laco que inicializa a matriz, todas as posicoes tem valor 0
	{
		for(j=0;j<10;j++)
		{
			jog1[i][j] = 9;
			jog2[i][j] = 9;
		}
	}

	for(k=1;k<5;k++) // Distribue os "navios" em posicoes aleatorias da matriz
	{
		x = rand() % 10; // gera numero aleatorio entre 0 e 10 para a linha
		y = rand() % 10; // gera numero aleatorio entre 0 e 10 para a coluna

		jog1[x][y] = k;
	}
	// Tratamento da matriz do 2 jogador
	for(k=1;k<5;k++)
	{
		x = rand() % 10; // Gera numero aleatorio entre 0 e 10 para a linha
		y = rand() % 10; // Gera numero aleatorio entre 0 e 10 para a coluna

		jog2[x][y] = k;		// A posicao aleatoria recebe o o valor de k
	}
	printf("\n\n");

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("|  %d  |", jog1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	for(i=0;i<10;i++)	{
		for(j=0;j<10;j++)
		{
			printf("|  %d  |", jog2[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	while(c1!=4 && c2!=4)
        {
                printf("\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n");
                x = rand() % 10;
                y = rand() % 10;
                printf("Jogador 1 atirou na posicao: %d, %d", x, y);
                printf("\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n");
                if(jog2[x][y] == 1 || jog2[x][y] == 2 || jog2[x][y] == 3  || jog2[x][y] == 4)
                {
                        jog2[x][y] = 0;
                        c2++;
                        printf("Jogador 1 acertou!\t\t\t\t\t\t||\n");
                }
                printf("\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n\t\t\t\t\t\t\t\t||\n");
                x = rand() % 10;
                y = rand() % 10;
                printf("\t\t\t\t\t\t\t\t||\t\tJogador 2 atirou na posicao: %d, %d", x, y);
                if(jog1[x][y] == 1 || jog1[x][y] == 2 || jog1[x][y] == 3  || jog1[x][y] == 4)
                {
                jog1[x][y] = 0;
                        c1++;
                printf("\n\t\t\t\t\t\t\t\t||\t\tJogador 2 acertou!");
                }
        sleep(1); // Aguarda 1 segundo para reexecutar o laco
        r++; // Incrementa o contador das rodadas
        printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------\n-");
        }

	if(c2 == 4)
	printf("\n\t\t\tJogador 1 ganhou!!");

	if(c1 == 4)
	printf("\n\t\t\tJogador 2 ganhou!!\n");

	printf("\t\t\t%d jogadas\n\n", r);
	return(0);
	}
}
}

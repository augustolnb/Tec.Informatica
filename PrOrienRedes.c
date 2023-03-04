#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ler(char *cmd){
	char ch;
	int i=0;

	ch = getchar();
	while(ch != '\n'){
		cmd[i] = ch;
		ch = getchar();
		i++;
	}
	cmd[i] = '\0';
}

int main(int argc, char *argv[])
{
	int quant, i;
	char vt[20], cmd[30], back[120];
	FILE *arq;

	quant = atoi(argv[1]);
	strcpy(vt, argv[2]);

	arq = fopen(vt, "r");

	if(arq == NULL && quant <= 9){
		for(i=0;i<quant;i++){
			ler(cmd);
			strcpy(back, "echo ");
			strcat(back, cmd);
			if(i == 0)
				strcat(back, " > ");
			else if(i > 0 )
				strcat(back, " >> ");
			strcat(back, vt); strcat(back, "; echo ----------------------------"); strcat(back, " >> ");
			strcat(back, vt); strcat(back, " ; "); strcat(back, cmd); strcat(back, " >> ");
			strcat(back, vt); strcat(back, " ; "); strcat(back, "echo  "); strcat(back, " >> ");
			strcat(back, vt); strcat(back, " ; "); strcat(back, "echo  "); strcat(back, " >> ");
			strcat(back, vt);

			system(back);
		}
	}
	else
		printf("\n\nParâmetros incorretos.\n\n");
}

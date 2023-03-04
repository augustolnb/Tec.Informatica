# Prova de estrutura de dados
# Discente: Lucas Augusto
# Curso EMI 4º ano - 2016
# Simulação do sistema de atendimento de uma clinica implementando ordem de prioridade ao adicionar paciente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "/home/lucas/Documentos/Estrutura/Trabalho/sistema_clinica.h" //Obs: mude o caminho do arquivo .h 
#include <time.h>

int main(void)
{
	Lista lista; // lista é a lista de pacientes na fila de espera
	Lista med1, med2, med3;
	int operacao, idade, i=1, x, consulta, espera, atendidos, pesq, ch, veri;
	char nome[30], sintomas[30], num[3];
	memset(nome, '\0', 30);

	inicializa(&lista);
	inicializa(&med1);
	inicializa(&med2);
	inicializa(&med3);

	do {
		__fpurge(stdin);
		fflush(stdin);
		operacao = menu();

		switch (operacao){
			case 0:
				imprime(lista);
				printf("\n\n");
				imprime_med(med1, med2, med3);
			break;
			case 1:				
				__fpurge(stdin); 
				fflush(stdin);
				printf("Nome do paciente: "); fgets(nome, 30, stdin);
				__fpurge(stdin);
				fflush(stdin);
				printf("Idade do paciente: "); fgets(num, 3, stdin);
				idade = converte(num);
				while(idade == -1){ //// idade negativa
					printf("\tValor inválido\n");
					__fpurge(stdin);
					fflush(stdin);
					printf("Idade do paciente: "); fgets(num, 3, stdin);
					idade = converte(num);
				}
				__fpurge(stdin);
				fflush(stdin);
				printf("Sintomas: "); fgets(sintomas, 30, stdin);
				__fpurge(stdin);
				fflush(stdin);
				inserir(&lista, nome, idade, sintomas);
				imprime(lista);
				break;

			case 2:
				//ch = chamar_paciente(&lista, &med1, &med2, &med3, i);
				veri = cont_espera(&lista);

				if(veri == 0)
					break;
				else if(veri != 0){
					if(i % 3 == 1)				
						chamar_med1(&lista, &med1);
					else if(i % 3  == 2)
						chamar_med2(&lista, &med2);
					else if(i % 3 == 0)
						chamar_med3(&lista, &med3);
					i++;
				}

			break;

			case 3:
				consulta = consultas();

				if(consulta == 1){
					espera = cont_espera(&lista);
					printf("\nHá %d pessoa(s) na lista de espera\n\n", espera);
					sleep(3);
				}

				else if(consulta == 2){
					atendidos = cont_atendidos(&med1, &med2, &med3);
					if(atendidos == 1){
						printf("\n%d pessoa ja foi atendida\n\n", atendidos);
						sleep(3);
					}
					else{
						printf("\n%d pessoas ja foram atendidas\n\n", atendidos);
						sleep(3);
					}
				}

				else if(consulta == 3){
					printf("\nPesquisar paciente\n");
					printf("Entre com o nome do paciente: "); 
					__fpurge(stdin);
					fflush(stdin);
					fgets(nome, 30, stdin);
					pesq = pesq_paciente(&lista, &med1, &med2, &med3, nome);
					if(pesq == 1){
						printf("\nPaciente na lista de espera\n");
						sleep(3);
					}
					else if(pesq == 2){
						printf("\nPaciente atendido\n");
						sleep(3);
					}
					else if(pesq == 0){
						printf("\nPaciente não encontrado\n");
						sleep(3);
					}
				}

				break;

			default:
			break;
		}

	}while(operacao != 4);

	salvar(&med1, &med2, &med3);
	printf("\n\t***Conteudo salvo em 'arquivo.txt'***\n\n");
}

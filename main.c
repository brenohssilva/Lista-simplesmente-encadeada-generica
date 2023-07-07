/*
Implementar em C um TAD de lista encadeada genérica com informações do tipo Aluno. A Lista deverá
ser implementada como um TAD - tipo abstrato de dados - codificado usando arquivo fonte de header (.h)
e arquivo fonte com a implementação das funções definidas no arquivo header (.c). 

Deve possuir as seguintes funções:
1. Cria Lista;
2. Insere na lista (no início);
3. Percorre a lista (considerando as situações de busca, impressão e retirada de elementos);
4. Verifica se a lista está vazia;
5. Libera a lista (memória alocada);

Segue a estrutura do tipo de informação Aluno da lista:

struct aluno{
 int matrícula;
 char nome[50];
}
O programa DEVE possuir um Menu com as seguintes opções:
1. Inserir aluno;
2. Buscar aluno (por matrícula);
3. Imprimir alunos;
4. Retirar aluno (por matrícula);
5. Verifica se lista está vazia;
6. Sair; 

Sobre o formato da entrega:
Os trabalhos podem ser desenvolvidos individualmente ou em duplas e os arquivos .c e .h devem ser
enviados via Moodle, na Tarefa criada "Atividade 1 - Lista simplesmente encadeada genérica”. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

typedef struct aluno Aluno;
struct aluno{
	
	int matricula;
	char nome[50];
};

ListaGen* lst_cria(void){
	
	ListaGen* l = (ListaGen*) malloc(sizeof(ListaGen));
	l->prim = NULL;
	return l;
}

static void insere_aluno(ListaGen* l, int m, char nome[]){
	
	Aluno* p = (Aluno*) malloc(sizeof(Aluno));
	p->matricula = m;
	strcpy(p->nome, nome);
	lgen_insere(l, p);
}

static void imprime(void* info){
	
	Aluno* p = (Aluno*)info;
	printf("matricula: %.5d \tnome: %s\n", p->matricula, p->nome);
}

static void busca(void* info, int m){
	
	Aluno* p = (Aluno*) info;
	if(p->matricula == m)
		printf("\tbusca: %6s\n", p->nome);
}

static int remover(void* info, int m){
	
	Aluno* p = (Aluno*) info;
	if(p->matricula == m)
		return m;
	return 0;
}

int main(){
	
	ListaGen* l = lst_cria();
	
	int s, m, n = 0;
	char nome[50];
	
	while(1){
		
		system("cls");
		
		printf("Digite:");
		printf("\t1-Inserir Aluno\n");
		printf("\t2-Buscar Aluno\n");
		printf("\t3-Imprimir Alunos\n");
		printf("\t4-Retirar Aluno\n");
		printf("\t5-Verificar\n");
		printf("\t6-sair\n");
		scanf("%d", &s);
		
		switch(s){
			
			case 1:
				printf("Digite o nome: ");
				fflush(stdin);
				scanf("%[^\n]", nome);
				n++;
				insere_aluno(l, n, nome);
				break;
			case 2:
				printf("Digite a matricula: ");
				scanf("%d", &m);
				lgen_percorre2(l, busca, m);
				system("pause");
				break;
			case 3:
				lgen_percorre(l, imprime);
				system("pause");
				break;
			case 4:
				if(lgen_vazia(l) == 1){
					printf("\nA lista esta vazia\n");
					system("pause");
					continue;
				}
				
				printf("Digite a matricula: ");
				scanf("%d", &m);
				lgen_remove(l, remover, m);
				break;
			case 5:
				printf("A lista esta vazia: %s\n", lgen_vazia(l) == 0 ? "nao" : "sim");
				system("pause");
				break;
			default:
				lgen_libera(l);
				return 0;
		}
	}
}
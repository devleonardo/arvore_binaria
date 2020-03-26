#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define TAM 50
#define RU 10

struct Alunos {
	int ru;
	char nome[TAM];
	struct Alunos* direita, * esquerda;
};
struct Alunos all[RU] = {
	{1,"Leonardo"},
	{2,"Layla"},
	{3,"Edson"}
};

int menu();
void Inserir(Alunos** ElementoVarredura, int rus, char nomes[TAM]);
Alunos* Buscar(Alunos** ElementoVarredura, int rus, char nomes[TAM]);

int main() {
	int op, c;
	int rus;
	char nomes[TAM];

	Alunos* root;
	root = (Alunos*)malloc(sizeof(Alunos));
	root = NULL;

	Alunos* ElementoBusca;
	ElementoBusca = (Alunos*)malloc(sizeof(Alunos));

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite o RU do aluno: ");
			scanf_s("%d", &rus);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome do aluno: ");
			fgets(nomes, 50, stdin);
			Inserir(&root, rus, nomes);
			break;
		case 2:
			printf("Digite o RU a ser buscado: ");
			scanf_s("%d", &rus);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			ElementoBusca = Buscar(&root, rus, nomes);
			if (ElementoBusca != 0) {
				printf("\nRegistro encontrado!\n");
				printf("  \nRU: %d\n", rus);
				printf("Nome: %s\n", nomes);
			}
			else
				printf("Registro nao encontrado!\n");
			system("pause");
			break;
		case 3:
			return 0;
		default:
			printf("Opcao invalida\n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("Cls");

	printf("1. Cadastrar novo aluno\n");
	printf("2. Buscar aluno\n");
	printf("3.Sair\n\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

void Inserir(Alunos** ElementoVarredura, int rus, char nomes[TAM]) {

	if (*ElementoVarredura == NULL)
	{ //SE ESTÁ VAZIO, COLOCA NA ÁRVORE
		Alunos* NovoElemento = NULL;
		NovoElemento = (Alunos*)malloc(sizeof(Alunos));
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->ru = rus;
		NovoElemento->nome[TAM] = nomes[TAM];
		*ElementoVarredura = NovoElemento;

		return;
	}

	if (rus < (*ElementoVarredura)->ru)
	{
		Inserir(&(*ElementoVarredura)->esquerda, rus, nomes);
	}
	else
	{
		if (rus > (*ElementoVarredura)->ru)
		{
			Inserir(&(*ElementoVarredura)->direita, rus, nomes);
		}
	}
}

Alunos* Buscar(Alunos** ElementoVarredura, int rus, char nomes[TAM])
{
	if (*ElementoVarredura == NULL)
		return NULL;

	if (rus < (*ElementoVarredura)->ru)
	{
		Buscar(&((*ElementoVarredura)->esquerda), rus, nomes);
	}
	else
	{
		if (rus > (*ElementoVarredura)->ru)
		{
			Buscar(&((*ElementoVarredura)->direita), rus, nomes);
		}
		else
		{
			if (rus == (*ElementoVarredura)->ru)
				return *ElementoVarredura;
		}
	}
}
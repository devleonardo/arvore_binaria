#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Alunos {
	int ru;
	char nome[50];
	struct Alunos* direita, * esquerda;
};

int menu();
void Inserir(Alunos** ElementoVarredura, int num, char nomes[50]);
Alunos* Buscar(Alunos** ElementoVarredura, int num, char nomes[50]);

int main() {
	int op, c, num;
	char nomes[50];

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
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome do aluno: ");
			fgets(nomes, 50, stdin);
			Inserir(&root, num, nomes);
			break;
		case 2:
			printf("Digite o RU a ser buscado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			ElementoBusca = Buscar(&root, num, nomes);
			if (ElementoBusca != 0) {
				printf("%d\n", num);
				printf("%s\n", nomes);
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

void Inserir(Alunos** ElementoVarredura, int num, char nomes[50]) {

	if (*ElementoVarredura == NULL)
	{ //SE ESTÁ VAZIO, COLOCA NA ÁRVORE
		Alunos* NovoElemento = NULL;
		NovoElemento = (Alunos*)malloc(sizeof(Alunos));
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->ru = num;
		NovoElemento->nome[50] = nomes[50];
		*ElementoVarredura = NovoElemento;

		return;
	}

	if (num < (*ElementoVarredura)->ru)
	{
		Inserir(&(*ElementoVarredura)->esquerda, num, nomes);
	}
	else
	{
		if (num > (*ElementoVarredura)->ru)
		{
			Inserir(&(*ElementoVarredura)->direita, num, nomes);
		}
	}
}

Alunos* Buscar(Alunos** ElementoVarredura, int num, char nomes[50])
{
	if (*ElementoVarredura == NULL)
		return NULL;

	if (num < (*ElementoVarredura)->ru)
	{
		Buscar(&((*ElementoVarredura)->esquerda), num, nomes);
	}
	else
	{
		if (num > (*ElementoVarredura)->ru)
		{
			Buscar(&((*ElementoVarredura)->direita), num, nomes);
		}
		else
		{
			if (num == (*ElementoVarredura)->ru)
				return *ElementoVarredura;
		}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int RU;
	char nome[50], email[50];
}Aluno;

/*Aluno allu[10] = {
	{2771700, "Leonardo", "leonardo@gmail.com"},
	{2771701, "Layla", "layla@gmail.com"},
	{2771702, "Edson", "edson@gmail.com"}
};*/

typedef struct Arvore{
	Aluno alu;
	struct Arvore* esq, * dir;
} Arv;

int menu();
void Incluir(Arv** folha, Aluno alu);
void Buscar(Arv* folha, int p);
void Exibir(Arv* folha);

int main() {

	Arv* folha = NULL;
	Aluno alu;
	int opc, retorno = 0, c;
	int p;

	while (1) {
		opc = menu();
		switch (opc) {
		case 1:
			printf("\n\n");
			printf("=========================================\n");
			printf("|           Cadastro de Aluno           |\n");
			printf("=========================================\n");

			printf("|  Informe o RU: ");
			scanf_s("%d", &alu.RU);
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("|  Informe o Nome: ");
			fgets(alu.nome, 50, stdin);

			printf("|  Informe o Email: ");
			fgets(alu.email, 50, stdin);

			Incluir(&folha, alu);
			break;
		case 2:
			printf("\n\n");
			printf("=========================================\n");
			printf("|           Listagem de Aluno           |\n");
			printf("=========================================\n");
			Exibir(folha);
			system("pause");
			break;
		case 3:
			printf("\n\n");
			printf("==========================================\n");
			printf("|            Conulta de Aluno            |\n");
			printf("==========================================\n");

			printf("|  Informe o RU: ");
			scanf_s("%d", &alu.RU);
			while ((c = getchar()) != '\n' && c != EOF) {}

			p = alu.RU;

			Buscar(folha, p);
			system("pause");
			break;
		case 4:
			return 0;
		default:
			printf("Opcao invalida\n");
		}
	}
	return 0;
}

int menu() {
	int opc, c;
	system("Cls");
	printf("\n\n");
	printf("========================================\n");
	printf("|                 MENU                 |\n");
	printf("|======================================|\n");
	printf("|     1 - Cadastrar novo aluno         |\n");
	printf("|     2 - Listar todos os alunos       |\n");
	printf("|     3 - Buscar aluno              |\n");
	printf("|                                      |\n");
	printf("|     4 - Sair                         |\n");
	printf("========================================\n\n");

	printf("|     Digite sua escolha: ");
	scanf_s("%d", &opc);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return opc;
}

void Incluir(Arv** folha, Aluno alu) {
	if (*folha == NULL) {
		*folha = (Arv*)malloc(sizeof(Arv));
		(*folha)->dir = NULL;
		(*folha)->esq = NULL;
		(*folha)->alu = alu;
	}
	else {
		if (((*folha)->alu.RU) < alu.RU)
			Incluir(&(*folha)->esq, alu);
		else if (((*folha)->alu.RU) > alu.RU)
			Incluir(&(*folha)->dir, alu);
		else if (((*folha)->alu.RU) == alu.RU) {
			printf("\nAluno ja cadastrado.\n\n");
			system("pause");
		}
	}
}

void Buscar(Arv* folha, int p) {
	if (folha == NULL) {
		printf("\n");
		printf("|  Aluno nao cadastrado!\n\n");		
		return;		
	}
	if ((folha->alu.RU, p) == folha->alu.RU) {
		printf("==========================================\n");
		printf("|  RU: %d\n", folha->alu.RU);
		printf("|  Nome: %s", folha->alu.nome);
		printf("|  Email: %s", folha->alu.email);
		printf("==========================================\n");
		return;
	}
	Buscar(folha->esq, p);
	Buscar(folha->dir, p);
}

void Exibir(Arv* folha) {
	if (folha == NULL)
		return;
	else {
		printf("=========================================\n");
		printf("|  RU: %d\n", folha->alu.RU);
		printf("|  Nome: %s", folha->alu.nome);
		printf("|  Email: %s", folha->alu.email);
		printf("=========================================\n");
		Exibir(folha->esq);
		Exibir(folha->dir);
	}
	printf("\n");
}
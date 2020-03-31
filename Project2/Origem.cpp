/* �VORE BIN�RIA - BST */

/* Sua escolha � devido a sua facilidade na busca de dados, uma vez
que ela se compara com a busca binaria. A diferen�a de desempenho
esta na inser��o dos dados. Ambos aprensentam  para o BigO a complexidade
O(logn), por�m, a busca binaria em uma lista encadeada exige que
o conjunto de dados ja esteja ordenado, caso contrario, devera fazer
a ordena��o primeiro. A �VORE BIN�RIA tem a sua inser��o de dados
de forma organizada.
Dados de valores menores a esquerda de um n� pai e maiores a direita. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro
#define TAM 50

// Estrutura heterogenea de dados
typedef struct {
	int RU;
	char nome[TAM];
	char email[TAM];
}Aluno;

// Arvore
typedef struct Arvore{
	Aluno alu;
	struct Arvore* esq, * dir;
} Arv;

// Prototipos
void menu();
void Incluir(Arv** folha, Aluno alu);
void Buscar(Arv* folha, int ru);
void Exibir(Arv* folha);

// Inicio da execu��o da aplica��o
int main() {
	// Atribui a ARVORE a um ponteiro e inicializa NULL
	Arv* folha = NULL;
	Aluno alu;
	int opc, retorno = 0, c;

	while (1) {
		// Chama a fun��o menu e recebe a op��o do usuario
		menu();
		printf("|     Digite sua escolha: ");
		scanf_s("%d", &opc);
		// sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {} 
		system("Cls");
		// Executa a fun��o escolhida
		switch (opc) {
		case 1:
			// Inser��o dos dados do aluno
			printf("\n\n");
			printf("=========================================\n");
			printf("|           Cadastro de Aluno           |\n");
			printf("=========================================\n");

			printf("|  Informe o RU: ");
			scanf_s("%d", &alu.RU);
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("|  Informe o Nome: ");
			fgets(alu.nome, TAM, stdin);

			printf("|  Informe o Email: ");
			fgets(alu.email, TAM, stdin);

			Incluir(&folha, alu);
			break;
		case 2:
			// Lista todos os alunos cadastrados
			printf("\n\n");
			printf("=========================================\n");
			printf("|           Listagem de Aluno           |\n");
			printf("=========================================\n");
			Exibir(folha);
			system("pause");
			break;
		case 3:
			/* Busca um aluno na �rvore. Caso o encontre,
			imprime seus dados. N�o encontrando, imprime uma
			mensagem de erro. */
			printf("\n\n");
			printf("==========================================\n");
			printf("|            Conulta de Aluno            |\n");
			printf("==========================================\n");

			printf("|  Informe o RU: ");
			scanf_s("%d", &alu.RU);
			while ((c = getchar()) != '\n' && c != EOF) {}
			// Realiza a busca atraves da fun��o
			Buscar(folha, alu.RU);
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

// Fun��o que imprime o menu
void menu() {
	system("Cls");
	printf("\n\n");
	printf("========================================\n");
	printf("|                 MENU                 |\n");
	printf("|======================================|\n");
	printf("|     1 - Cadastrar novo aluno         |\n");
	printf("|     2 - Listar todos os alunos       |\n");
	printf("|     3 - Buscar aluno                 |\n");
	printf("|                                      |\n");
	printf("|     4 - Sair                         |\n");
	printf("========================================\n\n");
}

// Fun��o que cadastra o aluno na �rvore
void Incluir(Arv** folha, Aluno alu) {
	// Aloca a ARVORE na memoria e cria NO
	if (*folha == NULL) {
		*folha = (Arv*)malloc(sizeof(Arv));
		(*folha)->dir = NULL;
		(*folha)->esq = NULL;
		(*folha)->alu = alu;
	}

	/* Cadastra de acordo com o valor da RAIZ.
	Se o RU a ser cadastrado for menor que a RAIZ,
	inserir a esquerda. Se o RU a ser cadastrado
	for maior que a RAIZ, inserir a direta. */
	else {
		if (((*folha)->alu.RU) < alu.RU)
			Incluir(&(*folha)->esq, alu);
		else if (((*folha)->alu.RU) > alu.RU)
			Incluir(&(*folha)->dir, alu);
		else if (((*folha)->alu.RU) == alu.RU) {
			// Retorna uma mensagem caso o aluno ja esteja cadastrado
			printf("\nAluno ja cadastrado.\n\n");
			system("pause");
		}
	}
}

// Fun��o que reaiza a busca do aluno na ARVORE
void Buscar(Arv* folha, int ru) {
	/* Se o NO folha pesquisado for NULL
	retorna uma mensagem de erro informando
	que o aluno n�o foi encontrado. */
	if (folha == NULL) {
		printf("\n");
		printf("|  Aluno nao cadastrado!\n\n");		
		return;		
	}
	/* Caso contrario, as informa��es completas
	do aluno pesquisado ser�o exibidas */
	if ((folha->alu.RU, ru) == folha->alu.RU) {
		printf("==========================================\n");
		printf("|  RU: %d\n", folha->alu.RU);
		printf("|  Nome: %s", folha->alu.nome);
		printf("|  Email: %s", folha->alu.email);
		printf("==========================================\n");
		return;
	}
	/* Busca esquerda ou direita, comparando o
	numero buscado com a RAIZ */
	if ((folha->alu.RU) > ru)
		Buscar(folha->dir, ru);
	else
		Buscar(folha->esq, ru);
}

/* Exibe a lista completa dos alunos
cadastrados em ordem crescente de cima para baixo. */
void Exibir(Arv* folha) {
	// Caso a ARVORE esteja vazia, retorna ao MENU
	if (folha == NULL)
		return;
	// Sen�o, exibe a lista completa.
	else {
		Exibir(folha->dir);
		printf("=========================================\n");
		printf("|  RU: %d\n", folha->alu.RU);
		printf("|  Nome: %s", folha->alu.nome);
		printf("|  Email: %s", folha->alu.email);
		printf("=========================================\n");
		Exibir(folha->esq);
	}
	printf("\n");
}
/* ÁVORE BINÁRIA - BST */

/* Sua escolha é devido a sua facilidade na busca de dados, uma vez
que ela se compara com a busca binaria. A diferença de desempenho
esta na inserção dos dados. Ambos aprensentam  para o BigO a complexidade
O(logn), porém, a busca binaria em uma lista encadeada exige que
o conjunto de dados ja esteja ordenado, caso contrario, devera fazer
a ordenação primeiro. A ÁVORE BINÁRIA tem a sua inserção de dados
de forma organizada.
Dados de valores menores a esquerda de um nó pai e maiores a direita. */

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

// Inicio da execução da aplicação
int main() {
	// Atribui a ARVORE a um ponteiro e inicializa NULL
	Arv* folha = NULL;
	Aluno alu;
	int opc, retorno = 0, c;

	while (1) {
		// Chama a função menu e recebe a opção do usuario
		menu();
		printf("|     Digite sua escolha: ");
		scanf_s("%d", &opc);
		// sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {} 
		system("Cls");
		// Executa a função escolhida
		switch (opc) {
		case 1:
			// Inserção dos dados do aluno
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
			/* Busca um aluno na árvore. Caso o encontre,
			imprime seus dados. Não encontrando, imprime uma
			mensagem de erro. */
			printf("\n\n");
			printf("==========================================\n");
			printf("|            Conulta de Aluno            |\n");
			printf("==========================================\n");

			printf("|  Informe o RU: ");
			scanf_s("%d", &alu.RU);
			while ((c = getchar()) != '\n' && c != EOF) {}
			// Realiza a busca atraves da função
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

// Função que imprime o menu
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

// Função que cadastra o aluno na árvore
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

// Função que reaiza a busca do aluno na ARVORE
void Buscar(Arv* folha, int ru) {
	/* Se o NO folha pesquisado for NULL
	retorna uma mensagem de erro informando
	que o aluno não foi encontrado. */
	if (folha == NULL) {
		printf("\n");
		printf("|  Aluno nao cadastrado!\n\n");		
		return;		
	}
	/* Caso contrario, as informações completas
	do aluno pesquisado serão exibidas */
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
	// Senão, exibe a lista completa.
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
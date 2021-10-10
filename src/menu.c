#include <corecrt_wstdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <menu.h>

static inline void print_menu()
{
	printf("1 - Exibir estatísticas\n");
	printf("2 - Efetuar busca por matrícula\n");
	printf("3 - Excluir por matrícula\n");
	printf("4 - Incluir aluno\n");
	printf("0 - Sair\n");
	printf("Opção: ");
}

int menu(HashFechada *h1, HashFechada *h2)
{
	int quit = 0;
	int op;
	while(!quit) {
		print_menu();
		fflush(stdout);
		scanf("%d", &op);
		printf("\n");
		switch(op)
		{
			case 1:
				//Exibir estatisticas
				break;
			case 2:
				//Busca por matricula
				break;
			case 3:
				//Excluir por matricula
				break;
			case 4:
				char nome[50];
				int matricula, nota;

				printf("Matrícula: ");
				fflush(stdout);
				scanf("%d", &matricula);
				getc(stdin); // Remover '\n' do stdout

				printf("\nNome: ");
				fflush(stdout);
				fgets(nome, sizeof(nome), stdin);
				nome[strcspn(nome, "\n")] = 0; //Remover '\n' da string

				printf("\nNota: ");
				fflush(stdout);
				scanf("%d", &nota);
				getc(stdin); // Remover '\n' do stdout
				printf("\n");

				// Inserir
				Aluno *a = new_aluno(matricula, nome, nota);
				insert_hashFechada(h1, a);
				insert_hashFechada(h2, a);
				break;
			case 0:
				printf("Salvando arquivos...\n");
				FILE *fp = fopen("hash_fechada1000.txt", "w");
				write_file(fp, h1);
				fclose(fp);
				fp = fopen("hash_fechada997.txt", "w");
				write_file(fp, h2);
				fclose(fp);
				printf("Arquivos salvos.");
				quit = 1;
				break;
			default:
				printf("Opção inválida\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}
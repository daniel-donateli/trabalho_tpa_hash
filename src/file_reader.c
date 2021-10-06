#include <file_reader.h>

void read_file(FILE *fp, HashFechada *h)
{
	if(fp == NULL) return;
	int i;
	char *token;
	char linha[256];
	int qtd = atoi(fgets(linha, 256, fp));
	char nome[50];
	int matricula;
	int nota;
	for(i=0; i<qtd; i++) {
		fgets(linha, 256, fp);
		token = strtok(linha, ";");
		matricula = atoi(token);
		token = strtok(NULL, ";");
		strcpy(nome, token);
		token = strtok(NULL, ";");
		nota = atoi(token);
		Aluno *a = new_aluno(matricula, nome, nota);
		insert_hashFechada(h, a);
	}
	fclose(fp);
}

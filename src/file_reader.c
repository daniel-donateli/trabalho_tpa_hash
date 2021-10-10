#include <stdio.h>
#include <stdlib.h>

#include <lista.h>
#include <file_reader.h>

void read_file(FILE *fp, HashFechada *h1, HashFechada *h2)
{
	if(fp == NULL) perror("Não foi possível abrir o arquivo.");
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
		insert_hashFechada(h1, a);
		insert_hashFechada(h2, a);
	}
	fclose(fp);
}

void write_file(FILE *fp, HashFechada *h)
{
	int i;
	Elemento *aux = NULL;
	for(i=0; i<h->tamanho; i++) {
		if(h->dados[i]->prim == NULL) continue;
		aux = h->dados[i]->prim;
		while(aux != NULL) {
			fprintf(fp, "%d;%d;%s;%d\n", i, aux->valor->matricula, aux->valor->nome, aux->valor->nota);
			aux = aux->prox;
		}
	}
}
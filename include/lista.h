#pragma once

#include <stdlib.h>

#include <aluno.h>

typedef struct elemento {
	Aluno *valor;
	struct elemento *prox;
} Elemento;

typedef struct lista {
	Elemento *prim;
	Elemento *ult;
	int quantidade;
} Lista;

Lista *new_lista();

void insert_lista(Lista *l, Aluno *a);

Aluno *remove_lista(Lista *l, Aluno *a);

Aluno *search_lista_nome(Lista *l, char nome[50]);

Aluno *search_lista_matricula(Lista *l, int matricula);

void print_lista(Lista *l);

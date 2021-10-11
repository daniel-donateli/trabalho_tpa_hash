#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lista.h>
#include <aluno.h>

Lista *new_lista()
{
	Lista *l = (Lista *) malloc(sizeof(Lista));
	l->prim = NULL;
	l->ult = NULL;
	l->quantidade = 0;
	return l;
}

void insert_lista(Lista *l, Aluno *a)
{
	Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
	novo->valor = a;
	novo->prox = NULL;
	if(l->prim == NULL) {
		l->prim = l->ult = novo;
	} else {
		l->ult->prox = novo;
		l->ult = novo;
	}
	l->quantidade++;
}

Aluno *remove_lista(Lista *l, Aluno *a)
{
	Elemento *aux = l->prim;
	Elemento *ant = NULL;
	//Aluno *ret;
	while(aux != NULL) {
		if(aux->valor == a) {
			if(aux == l->prim) l->prim = aux->prox;
			else if(aux == l->ult) {
				l->ult = ant;
				ant->prox = NULL;
			}
			else ant->prox = aux->prox;
			//ret = aux->valor;
			free(aux);
			l->quantidade--;
			return a;
		}
		ant = aux;
		aux = aux->prox;
	}
	return NULL;
}

Aluno *search_lista_nome(Lista *l, char *nome)
{
	Elemento *aux = l->prim;
	while(aux != NULL) {
		if(strcmp(aux->valor->nome, nome) == 0) {
			return aux->valor;
		}
		aux = aux->prox;
	}
	return NULL;
}

Aluno *search_lista_matricula(Lista *l, int matricula)
{
	Elemento *aux = l->prim;
	while(aux != NULL) {
		if(aux->valor->matricula == matricula) {
			return aux->valor;
		}
		aux = aux->prox;
	}
	return NULL;
}

void print_lista(Lista *l)
{
	Elemento *aux = l->prim;
	//printf("\nLISTA:\n[\n");
	while (aux != NULL) {
		PRINT_ALUNO(aux->valor);
		aux = aux->prox;
	}
	//printf("]\n");
}

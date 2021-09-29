#pragma once

#include <lista.h>

typedef struct hash_fechada {
	int tamanho, quantidade;
	Lista **dados;
} HashFechada;

HashFechada *new_hashFechada(int tamanho);

void insert_hashFechada(HashFechada *h, Aluno *a);

int remove_hashFechada(HashFechada *h, int matricula);

Aluno *search_hashFechada_matricula(HashFechada *h, Aluno *a);

void print_hashFechada(HashFechada *h);

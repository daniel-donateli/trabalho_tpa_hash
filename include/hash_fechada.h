#pragma once

#include <lista.h>

typedef struct hash_fechada {
	int tamanho, quantidade;
	Lista **dados;
} HashFechada;

HashFechada *new_hashFechada(int tamanho);

void insert_hashFechada(HashFechada *h, Aluno *a);

Aluno *remove_hashFechada(HashFechada *h, int matricula);

Aluno *search_hashFechada_matricula(HashFechada *h, int matricula);

void print_hashFechada(HashFechada *h);

void print_stats(HashFechada *h);

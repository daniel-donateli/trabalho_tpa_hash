#include <stdlib.h>

#include <hash_fechada.h>

static inline int hash(HashFechada *h, int matricula)
{
	return matricula % h->tamanho;
}

HashFechada *new_hashFechada(int tamanho)
{
	HashFechada *h = (HashFechada *) malloc(sizeof(HashFechada));
	h->quantidade = 0;
	h->tamanho = tamanho;
	h->dados = (Lista **) malloc(sizeof(Lista *) * tamanho);
	int i;
	for(i=0; i<tamanho; i++) {
		h->dados[i] = new_lista();
	}
	return h;
}

void insert_hashFechada(HashFechada *h, Aluno *a)
{
	insert_lista(h->dados[hash(h, a->matricula)], a);
	h->quantidade++;
}

int remove_hashFechada(HashFechada *h, int matricula)
{
	Aluno *a = search_lista_matricula(h->dados[hash(h, matricula)], matricula);
	if(a == NULL) return 0;
	h->quantidade--;
	return remove_lista(h->dados[hash(h, matricula)], a);
}

void print_hashFechada(HashFechada *h)
{
	int i;
	printf("HASH FECHADA:\n");
	for(i=0; i<h->tamanho; i++) {
		printf("LISTA %d:\n", i);
		print_lista(h->dados[i]);
	}
}

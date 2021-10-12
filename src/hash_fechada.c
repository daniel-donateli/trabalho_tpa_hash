#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

Aluno *remove_hashFechada(HashFechada *h, int matricula)
{
	Aluno *a = search_lista_matricula(h->dados[hash(h, matricula)], matricula);
	if(a == NULL) return NULL;
	h->quantidade--;
	return remove_lista(h->dados[hash(h, matricula)], a);
}

Aluno *search_hashFechada_matricula(HashFechada *h, int matricula)
{
	return search_lista_matricula(h->dados[hash(h, matricula)], matricula);
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

void print_stats(HashFechada *h)
{
	int maior;
	int menor;
	int qtd_intervalo = 0; // quantidade de índices dentro do intervalo de média + ou - desvio padrão
	maior = menor = 0;
	int i;
	double media = (double) h->quantidade / (double) h->tamanho;
	double somatoria = 0; // Para calcular desvio padrão

	for(i=0; i<h->tamanho; i++) {
		if(h->dados[i]->quantidade > h->dados[maior]->quantidade) maior = i;
		if(h->dados[i]->quantidade < h->dados[menor]->quantidade) menor = i;
		somatoria += pow(((double) h->dados[i]->quantidade - media), 2);
	}

	double desvio_padrao = sqrt(somatoria / (double) h->tamanho);

	for(i=0; i<h->tamanho; i++) {
		if((double) h->dados[i]->quantidade < (media + desvio_padrao)
		&& (double) h->dados[i]->quantidade > (media - desvio_padrao)) {
			qtd_intervalo++;
		}
	}

	printf("Quantidade total de elementos: %d\n", h->quantidade);
	printf("Média de elementos por índice: %.2lf\n", media);
	printf("Índice com a maior quantidade de elementos: %d; Quantidade de elementos: %d\n", maior, h->dados[maior]->quantidade);
	printf("Índice com a menor quantidade de elementos: %d; Quantidade de elementos: %d\n", menor, h->dados[menor]->quantidade);
	printf("Desvio Padrão: %.2lf\n", desvio_padrao);
	printf("Número de índices que tem quantidade dentro do intervalo da média + ou - devio padrão: %d\n", qtd_intervalo);
}

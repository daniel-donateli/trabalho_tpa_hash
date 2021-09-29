#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include <hash_fechada.h>

int main(int argv, char *args[]) 
{
	setlocale(LC_ALL, "Portuguese");
	/*
	Lista *l = new_lista();
	insert_lista(l, new_aluno(1, "Teste"));
	insert_lista(l, new_aluno(2, "asdgfg"));
	insert_lista(l, new_aluno(3, "fdfhgohywfhog"));
	print_lista(l);
	Aluno *a = search_lista_matricula(l, 2);
	
	if(a != NULL) PRINT_ALUNO(a);
	a = search_lista_nome(l, "Teste");
	if(a != NULL) PRINT_ALUNO(a);
	
	if(remove_lista(l, a)) print_lista(l);
	*/
	HashFechada *h = new_hashFechada(10);
	insert_hashFechada(h, new_aluno(1, "Teste"));
	insert_hashFechada(h, new_aluno(2, "asdgfg"));
	insert_hashFechada(h, new_aluno(6, "fdfhgohywfhog"));
	//PRINT_ALUNO(search_lista_matricula(h->dados[1], 1));
	remove_hashFechada(h, 1);
	print_hashFechada(h);
	return 0;
}

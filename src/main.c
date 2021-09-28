#include <stdlib.h>
#include <string.h>

#include <aluno.h>
#include <lista.h>

int main(int argv, char *args[]) 
{
	Lista *l = new_lista();
	insert_lista(l, new_aluno(1, "Teste"));
	insert_lista(l, new_aluno(2, "asdgfg"));
	insert_lista(l, new_aluno(3, "fdfhgohywfhog"));
	print_lista(l);
	Aluno *a = search_lista_matricula(l, 2);
	/*
	if(a != NULL) PRINT_ALUNO(a);
	a = search_lista_nome(l, "Teste");
	if(a != NULL) PRINT_ALUNO(a);
	*/
	if(remove_lista(l, a)) print_lista(l);
	return 0;
}
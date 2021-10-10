#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <file_reader.h>

int main(int argv, char *args[]) 
{
	setlocale(LC_ALL, "Portuguese");
	HashFechada *h1 = new_hashFechada(10);
	HashFechada *h2 = new_hashFechada(7);
	FILE *fp = fopen("dados.txt", "r");
	read_file(fp, h1, h2);
	fclose(fp);
	return menu(h1, h2);
}

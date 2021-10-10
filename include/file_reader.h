#pragma once

#include <stdio.h>

#include <hash_fechada.h>

void read_file(FILE *fp, HashFechada *h1, HashFechada *h2);

void write_file(FILE *fp, HashFechada *h);

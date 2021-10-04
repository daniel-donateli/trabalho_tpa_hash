#pragma once

#include <stdio.h>

#include <hash_fechada.h>

void read_file(FILE *fp, HashFechada *h);

void write_file(FILE *fp, HashFechada *h);

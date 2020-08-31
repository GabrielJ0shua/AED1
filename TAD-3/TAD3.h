#include<stdio.h>
#include<stdlib.h>
#include "fun3.c"

void menu(void);

typedef struct TAD tad;

int Atribuicao(int i);

void libera(tad *p);

void area(tad *p,tad *p1);

float raio(tad *p,tad *p1);

void volume(tad *p,tad *p1);
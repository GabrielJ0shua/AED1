#include<stdio.h>
#include<stdlib.h>
#include "complexo.c"

typedef struct TAD tad;

tad * generate();
tad * sum(tad *, tad *);

float cria_nro(tad *, float, float);
float get_value(tad *, float *, float *);
void delete(tad **p);
 
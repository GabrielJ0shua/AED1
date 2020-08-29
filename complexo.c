#include<stdio.h>
#include<stdlib.h>
#include<funcao.h>


struct TAD{
float real, imaginario;
};

typedef struct TAD tad;

tad * generate(){ // cria um numero complexo
    tad * p;
    p=(tad *) malloc(sizeof(tad));
    return p;
}

tad * sum(tad *n1, tad *n2){ // soma 2 numeros complexos e retorna o resultado
    tad *n3;
    n3 = generate(); // cria um numero complexo e atribui o end para a variavel aux
    if(n3 != NULL){
        n3->real = (n1->real*n2->imaginario) + (n2->real*n1->imaginario);
        n3->imaginario = (n1->imaginario * n2->imaginario);
    }
    return n3;
}

float cria_nro(tad *p, int r, int i){
    if(p == NULL || i == 0)
        return 0;

    p->real = r;
    p->imaginario = i;

    return 1;
}

float get_value(tad *p, float *r, float *i){ // atribuição aos valores
  
    if(p==NULL)

        return 0;

    *r = p->real;
    *i = p->imaginario;

    return 1;
}

void delete(tad **p){
    free(*p);
    *p = NULL;
}


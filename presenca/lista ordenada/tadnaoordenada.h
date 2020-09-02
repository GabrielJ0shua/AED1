#include<stdio.h>
#include<stdlib.h>
#define MAX 20
 
struct lista{
    float vet[MAX];
    int FIM;
};

typedef struct lista Lista;

Lista* cria(void){
    Lista *a;
    a=(Lista*) malloc(sizeof(Lista));
    if(a!=NULL) a->FIM = 0;

    return a;
}

int vazia(Lista *p){
    if (p->FIM == 0) return 1;
    else return 0;
}

int lista_cheia(Lista *p){
    if (p->FIM == MAX) return 1;
    else return 0;
}

int insere(Lista *p) {
    float x;
    printf("\nQual elemento? ");
    scanf("%f",&x);

    if (p == NULL || lista_cheia(p) == 1) return 0;

    if (vazia(p) == 1 || x >= p->vet[p->FIM-1]) p->vet[p->FIM] = x;
    
    else {
        int i, aux = 0;
        while (x >= p->vet[aux])
        aux++;
        for (i = p->FIM; i > aux; i--)
        p->vet[i] = p->vet[i-1];
        p->vet[aux] = x;
    }
    p->FIM++;
    return 1;
}

int apaga(Lista *p){
    float x;
    printf("\nQual elemento? ");
    scanf("%f",&x);

    if (p == NULL || vazia(p) == 1 || x < p->vet[0] || x > p->vet[p->FIM-1]) return 0;
    
    int i, Aux = 0;

    while (Aux < p->FIM && p->vet[Aux] < x)Aux++;

    if (Aux == p->FIM || p->vet[Aux] > x) return 0;

    for (i = Aux+1; i < p->FIM; i++)p->vet[i-1] = p->vet[i];

    p->FIM--;
    return 1;
}

void imprime(Lista *p){
    int i=0;
    for(i=0;i<p->FIM;i++){
        printf("| %f ",p->vet[i]);
        if(i<p->FIM-1)printf(" ");
    }

    printf("\b");
}
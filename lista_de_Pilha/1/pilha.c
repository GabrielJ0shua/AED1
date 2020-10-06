#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

struct pilha
{
    int qnt;
    struct numero num[MAX]; 
};

void clear(void)
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

Pilha *cria_pilha(void){
    Pilha*pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL) pi->qnt = 0;
    return pi;
}

void libera_pilha(Pilha*pi){
    free(pi);
}

int tamanho_pilha(Pilha*pi){
    if(pi == NULL) return -1;
    else return pi->qnt;
}

int pilha_cheia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->qnt == MAX);
}

int pilha_vazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->qnt == 0);
}

int push(Pilha *pi, int x){
    if (pi == NULL || pilha_cheia(pi)) return 0;
    pi->num[pi->qnt].x = x;
    pi->qnt++;
    return 1;
}

int pop(Pilha *pi){
    if (pi == NULL || pi->qnt == 0) return 0;
    pi->qnt--;
    return 1;
}

int consulta_pilha(Pilha *pi, int x){
    if (pi == NULL || pi->qnt == 0) return 0;
    x = pi->num[pi->qnt-1].x;
    return 1;
}

void imprime(Pilha *pi){
    Pilha *aux = pi;
    if (pi == NULL || pi->qnt == 0) printf("\nNão a nada a ser impresso...");
    for (int i = 0; i < aux->qnt; i++) printf("\n| %d |\n", aux->num[i].x);
}
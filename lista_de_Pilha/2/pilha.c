#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

struct elemento
{
    struct pilha *prox;
    struct numero num; 
};
typedef struct elemento elem;
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
    Pilha*pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL) *pi = NULL;
    return pi;
}

void libera_pilha(Pilha*pi){
    if(pi != NULL){
        elem* no;
        while ((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);        
    }
}

int tamanho_pilha(Pilha*pi){
    if(pi == NULL) return 0;
    int cont = 0;
    elem* no = *pi;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    
}

int pilha_cheia(Pilha *pi){
    return 0;
}

int pilha_vazia(Pilha *pi){
    if(pi == NULL || pi == NULL) return 1;
    return 0;
}

int push(Pilha *pi, int x){
    if (pi == NULL) return 0;
    elem* no = (elem*) malloc(sizeof(elem));
    if(no == NULL) return 0;
    no->num.x = x;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int pop(Pilha *pi){
    if (pi == NULL || (*pi) == NULL) return 0;
    elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int consulta_pilha(Pilha *pi, int x){
    if (pi == NULL || (*pi) == NULL) return 0;
    x = (*pi)->num.x;
    return 1;
}
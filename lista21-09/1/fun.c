#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
  
lista *cria(void)
{
    lista* li = (lista*) malloc(sizeof(lista));
    if (li != NULL) *li = NULL;
    return li;
}
void libera (lista *li)
{
    if (li != NULL)
    {
        elem* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li= (*li)->prox;
            free(no);
        }
        free(li);
    }
    
}
int ord(lista *li,int b)
{
    if(li == NULL) return 0;
    elem* no = (elem*) malloc(sizeof(elem));
    if(no == NULL) return 0;
    no->num = b;
    if(vazia(li)) {
        no->prox = NULL;
        no->ini = NULL;
        *li = no;
        return 1;
    }
    else{
        elem *ante, * atual = *li;
        while (atual != NULL && atual->num < b)
        {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li){
            no->ini = NULL;
            (*li)->ini = no;
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ante->prox;
            no->ini = ante;
            ante->prox = no;
            if(atual != NULL) atual->ini = no;
        }
        return 1;
    }
}
int rem(lista *li,int b){
    if(li == NULL) return 0;
    elem* ant, *no = *li;
    while (no != NULL && no->num != b){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *li) *li = no->prox;
    else ant->prox = no->prox;
    free(no);
    return 1;
}
int pos(lista *li,int b)
{
    if(li == NULL) return 0;
    elem *no = *li;
    int qnt = 0;
    while (no != NULL && no->num != b)
    {
        no = no->prox;
        qnt++;
    }
    if(no == NULL) return 0;
    else{
        printf("\n| %d |",qnt);
        return 1;
    }
}
int imprime(lista *li)
{
    if(li == NULL) return 0;
    elem *no = *li;
    while (no != NULL)
    {
        printf("| %d |",no->num);
        no = no->prox;
    }
    printf("\n");
    if(no == NULL) return 1;
}
int tamanho(lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    elem* no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}
int vazia(lista* li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}
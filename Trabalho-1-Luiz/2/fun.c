#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista *cria(){
    lista *li;
    li = (lista*) malloc(sizeof(lista));
    if(li != NULL) li->qnt = 0;
    return li;
}

void libera(lista *li){
    free(li);
}

int tamanho(lista *li){
    if(li == NULL) return 0;
    else return li->qnt;
}

int vazia(lista *li){
    if(li == NULL) return 0;
    return (li->qnt == 0);
}

int insercao_ord(lista *li, int numero){
    if (li == NULL) return 0;
    int k,i = 0;
    while (i<li->qnt && li->num[i] < numero) i++;
    for (k = li->qnt-1; k >= i; k--) li->num[k+1] = li->num[k];
    li->num[i] = numero;
    li->qnt++;
    return 1;
}

int remove_qualquer(lista *li, int numero){
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0;
    while (i<li->qnt && li->num[i] != numero) i++;
    if (i == li->qnt) return 0;
    for (k = i; k < li->qnt-1; k++) li->num[k] = li->num[k+1];
    li->qnt--;
    return 1;
}

int consulta_par(lista *li)
{
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0;
    while (i<li->qnt){
        if ((li->num[i])%2 != 0)
        {
            i++;
        }
    if (i == 0) return 1;
    else return 0;
    }
}

int remove_par(lista *li){
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0;
    for (int j = 0; j != 1; j)
    {
        while (i<li->qnt && (li->num[i])%2 != 0) i++;
        if (i == li->qnt) return 1;
        for (k = i; k < li->qnt-1; k++) li->num[k] = li->num[k+1];
        li->qnt--;
        j = consulta_par(li);
    }
    return 1;
}

int consulta_qualquer (lista *li, int numero){
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0;
    while (i<li->qnt && li->num[i] != numero) i++;
    if (i == li->qnt) return 0;
    else return i;
}

int consulta_maior (lista *li){
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    int k,i = 0,aux = li->num[0];
    while (i < li->qnt)
    {
        if (aux < li->num[i]) aux = li->num[i];
        i++;
    }
    if (i == li->qnt) return aux;
    else return 0;
}

int intercalar(lista *aux,lista *li, lista *li2){
    if (li == NULL || li2 == NULL) return 0;
    if(li->qnt == 0 || li2->qnt == 0) return 0;
    int i,j,k;
    for (i = 0; i < (li->qnt); i++) insercao_ord(aux, li->num[i]);
    for (i = 0; i < (li2->qnt); i++) insercao_ord(aux, li2->num[i]);
    return 1;
}

int esvaziar_lista(lista *li){
    if (li == NULL) return 0;
    if(li->qnt == 0) return 0;
    li->qnt = 0;
    return 1;
}

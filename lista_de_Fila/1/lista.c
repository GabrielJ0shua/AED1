#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
 
#define MAX 20

struct nomes
{
    char n[10];
};

struct fila{
    int ini,qnt, fim;
    struct nomes nome[MAX];
};

lista * cria_fila(void){
    lista *fi;
    fi = (lista*) malloc(sizeof(struct fila));
    if (fi != NULL)
    {
        fi->ini = 0;
        fi->qnt = 0;
        fi->fim = 0;
    }
    return fi;
}

void libera_fila(lista *fi){
    free(fi);
}

int tamanho_fila(lista *fi){
    if (fi == NULL) return -1;
    return fi->qnt;
}

int fila_cheia(lista *fi){
    if (fi == NULL) return -1;
    if (fi->qnt == MAX) return 1;
    else return 0;       
}

int fila_vazia(lista *fi){
    if (fi == NULL) return -1;
    else return 0; 
}

int insere_fila(lista *fi,char dados[]){
    if (fi == NULL) return 0;
    if (fila_cheia(fi)) return 0;
    strcpy(fi->nome[fi->fim].n,dados);
    fi->fim = (fi->fim+1)%MAX;
    fi->qnt++;
    return 1;
}

int remove_fila(lista *fi){
    if (fi == NULL || fila_vazia(fi)) return 0;
    fi->ini = (fi->ini+1)%MAX;
    fi->qnt--;
    return 1;
}

int consulta_fila(lista *fi, char *dados[]){
    if (fi == NULL || fila_vazia(fi)) return 0;
    *dados = fi->nome[fi->ini].n;
    return 1;
}

void clear(void)
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void imprime(lista *fi){
    if (fi == NULL || fila_vazia(fi)) printf("\nNão a nada a ser impresso...");
    int i = 0;
    while (i < fi->qnt)
    {
        printf("\n| %s |",fi->nome[i].n);
        i++;
    }
}
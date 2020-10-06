#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

#define MAX 20

struct fila{
    int ini,qnt, fim;
    struct aluno alunos[MAX];
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
    if (fi->qnt == MAX) return 1;
    else return 0; 
}

int insere_fila(lista *fi,struct aluno *a){
    if (fi == NULL) return 0;
    if (fila_cheia(fi)) return 0;
    fi->alunos[fi->fim] = *a;
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

int consulta_fila(lista *fi,struct aluno *a){
    if (fi == NULL || fila_vazia(fi)) return 0;
    *a = fi->alunos[fi->ini];
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
    for (int i = 0; i < fi->qnt; i++)
    {
        printf("\n| %i || %s || %f || %i |",fi->alunos[i].matricula,fi->alunos[i].nome,fi->alunos[i].media,fi->alunos[i].faltas);
    }
}
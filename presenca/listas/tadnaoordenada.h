#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct lista{
    float vet[MAX];
    int FIM;
};

typedef struct lista Lista;

Lista* cria(void){
    Lista *a = (Lista*) malloc(sizeof(Lista));

    if(a!=NULL) a->FIM = 0;

    return a;
}

int lista_vazia(Lista *lst) {

    if (lst == NULL) return 1;

    else return 0;
}

int insere_ord (Lista *lst) {
    float x;

    printf("\nQual elemento? ");
    scanf("%f",&x);

    Lista *N = (Lista*) malloc(sizeof(Lista));

    if (N == NULL) return 0;

    N->vet = x;

    if (lista_vazia(lst)  x <= (*lst)->vet){
        N->prox = *lst;
        *lst = N;
        return 1;
    }

    Lista aux = lst->vet;

    while (aux->prox != NULL && aux->prox->info < x)
    {
        aux = aux->prox;
        N->prox = aux->prox;
        aux->prox = N;
    }

    return 1;
}

void imprime_lista(Lista *lst){

    if(lst==NULL) printf("lista vazia");

    while(lst!=NULL){
        printf("| %c ", lst->info);
        lst=lst->prox;
    }
}
 
int remove_ord (Lista *lst, char elem) 
{
    if (lista_vazia(lst) == 1  elem < (*lst)->info)return 0; // Falha

    Lista aux = lst; // Ponteiro auxiliar para o 1onó

    if (elem == (lst)->info) 
    { // Remove elemento 1onó da lista
        *lst = aux->prox; // Lista aponta para o 2onó
        free(aux); // Libera memória alocada
        return 1;
    }

    while (aux->prox != NULL && aux->prox->info < elem)
    aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elem) return 0; // Falha

    // Remove elemento (após o 1onó da lista)
    Lista aux2 = aux->prox; // Aponta nó a ser removido
    aux->prox = aux2->prox; // Retira nó da lista

    free(aux2); // Libera memória alocada
    return 1;
}

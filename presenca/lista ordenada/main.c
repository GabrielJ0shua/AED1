#include<stdio.h>
#include<stdlib.h>
#include "tadnaoordenada.h"

int main(){
    int i;
    struct lista *l;
do
{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a lista\n[5]Liberar lista\n[6]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            l = cria();
        break;

        case (2):
            insere(l);
        break;

        case (3):
            apaga(l);
        break;

        case (4):
            imprime(l);
        break;

        case (5):
            free(l);
            l = cria();
        break;

        case (6):
            free(l);
            return 0;
        break;
    }
} while (i>0 && i<7);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void)
{
    int x,i;
    Pilha* pi;
    do
    {
    printf("\n[1]Criar Pilha\n[2]Inserir elementos\n[3]Remover primeiro elemento\n[4]Imprimir a Fila\n[5]Liberar fila\n[6]Sair\n");
    scanf("%d",&i);
    clear();
    switch (i)
    {
        case (1):
            pi  = cria_pilha();
            printf("\npronto\n");
        break;

        case (2):
            clear();
            printf("\nQual o número que deseja inserir? ");
            setbuf(stdin,NULL);
            scanf("%d",&x);
            push(pi,x);
            clear();
        break;

        case (3):
            pop(pi);
            clear();
        break;

        case (4):
            imprime(pi);
        break;

        case (5):
            libera_pilha(pi);
            pi = cria_pilha();
            clear();
        break;

        case (6):
            libera_pilha(pi);
            clear();
            return 0;
        break;
    }
} while (i>0 && i<7);
return 1;
}
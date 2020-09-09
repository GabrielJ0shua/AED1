#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad1.h"

int main(void){
    int i,j;
    lista *l;
do
{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a posição do número\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            l = cria();
            printf("\npronto");
        break;

        case (2):
            printf("\nQual o número que deseja inserir? ");
            scanf("%d",&j);
            insere(l,j);
        break;

        case (3):
            printf("\nQual o número que deseja apagar? ");
            scanf("%d",&j);
            rem(l,j);
        break;

        case (4):
            printf("\nQual o número que deseja consultar? ");
            scanf("%d",&j);
            pos(l,j);
        break;

        case (5):
            imprime(l);
        break;

        case (6):
            libera(l);
            l = cria();
        break;

        case (7):
            libera(l);
            return 0;
        break;
    }
} while (i>0 && i<8);
return 1;
} 
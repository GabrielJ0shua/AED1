#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad1.h"
 
int main(void){
    int i;
    lista *l;
    char n[10];
do
{
    printf("\n[1]Criar lista\n[2]Inserir elemento\n[3]Remover elemento\n[4]Imprimir a posição do nome\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            l = cria();
            printf("\npronto");
        break;

        case (2):
            printf("\nQual o nome que deseja inserir? ");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            insere(l,n);
        break;

        case (3):
            printf("\nQual o nome que deseja apagar? ");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            rem(l,n);
        break;

        case (4):
            printf("\nQual o nome que deseja consultar? ");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            pos(l,n);
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

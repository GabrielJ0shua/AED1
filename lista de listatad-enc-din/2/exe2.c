#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad2.h"
 
int main(void){
    int i,v;
    float p;
    lista *l;
    char n[100];
do
{
    printf("\n[1]Criar lista\n[2]Inserir elementos\n[3]Remover elementos\n[4]Imprimir as informações do nome\n[5]Imprimir a lista\n[6]Liberar lista\n[7]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            l = cria();
            printf("\npronto");
        break;

        case (2):
            printf("\nQual o nome da bebida: ");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            printf("\nQual o volume: ");
            scanf("%i",&v);
            printf("\nQual é o preço: ");
            scanf("%f",&p);
            insere(l,n,v,p);
        break;

        case (3):
            printf("\nQual o nome que deseja apagar? ");
            setbuf(stdin,NULL);
            gets(n);
            setbuf(stdin,NULL);
            rem(l,n);
        break;

        case (4):
            printf("\nMe fala o nome da bebida: ");
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

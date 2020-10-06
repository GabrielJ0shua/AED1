#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int main(void)
{
    struct bebida a;
    lista *fi;
    int x,i;
    do
{
    printf("\n[1]Criar Fila\n[2]Inserir elementos\n[3]Remover primeiro elemento\n[4]Imprimir a Fila\n[5]Liberar fila\n[6]Sair\n");
    scanf("%d",&i);
    clear();
    switch (i)
    {
        case (1):
            fi  = cria_fila();
            printf("\npronto\n");
        break;

        case (2):
            printf("\nNome da bebida: ");
            setbuf(stdin,NULL);
            gets(a.nome);
            printf("\nVolume: ");
            scanf("%d",&a.volume);
            printf("\nPreço: ");
            scanf("%f",&a.preco);
            insere_fila(fi,a);
            clear();
        break;

        case (3):
            remove_fila(fi);
        break;

        case (4):
            imprime(fi);
        break;

        case (5):
            libera_fila(fi);
            fi = cria_fila();
            clear();
        break;

        case (6):
            clear();
            libera_fila(fi);
            return 0;
        break;
    }
} while (i>0 && i<7);
return 1;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int main(void)
{
    struct aluno a;
    lista *fi;
    int x,i;
    do
{
    //clear;
    printf("\n[1]Criar Fila\n[2]Inserir elemento\n[3]Remover primeiro elemento\n[4]Imprimir a Fila\n[5]Liberar fila\n[6]Sair\n");
    scanf("%d",&i);
    switch (i)
    {
        case (1):
            fi  = cria_fila();
            printf("\npronto\n");
        break;

        case (2):
            printf("\nQual a matricula do aluno? ");
            scanf("%d",&a.matricula);
            printf("\nQual o nome do aluno? ");
            setbuf(stdin,NULL);
            gets(a.nome);
            printf("\nQual a média do aluno? ");
            scanf("%f",&a.media);
            printf("\nQuantidade de faltas do aluno? ");
            scanf("%d",&a.faltas);
            insere_fila(fi,&a);
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
        break;

        case (6):
            libera_fila(fi);
            return 0;
        break;
    }
} while (i>0 && i<7);
return 1;
}
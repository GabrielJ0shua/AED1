#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad2.h"

int main(void){
    int i;
    lista *l;
    struct pass
    {
        unsigned int mat;
        char nome[20];
        float me;
        int fal;
    };
    struct pass p;
    
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
            gets(p.nome);
            setbuf(stdin,NULL);
            printf("\nQual a matrícula: ");
            scanf("%u",&p.mat);
            printf("\nQuanto de média: ");
            scanf("%f",&p.me);
            printf("\nQuantas faltas: ");
            scanf("%d",&p.fal);
            insere(l,p.nome,p.mat,p.me,p.fal);
        break;

        case (3):
            printf("\nQual a matricula que deseja apagar? ");
            scanf("%u",p.mat);
            rem(l,p.mat);
        break;

        case (4):
            printf("\nQual a matricula que deseja consultar? ");
            scanf("%u",&p.mat);
            printf("| %d |",pos(l,p.mat));
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

#include<stdio.h>
#include<stdlib.h>
#include "TAD3.h"

typedef struct TAD tad;

int main(){

    int i;

    do
    {
        menu();
        scanf ("%d",&i);
        switch(i){
            case(1):
                printf("\nCrie a origem e um ponto 1°");
                tad *O = Atribuicao(1);
                tad *p1 = Atribuicao(2);
            break;

            case(2):
                printf("Liberando os pontos");
                libera(O);
                libera(p1);
            break;
                
            case(3):
                raio(O,p1);
            break;

            case(4):
                area(O,p1);
            break;


            case(5):
                volume(O,p1);
            break;
        }
    } while (i < 0 || i > 5);

    return 0;
}

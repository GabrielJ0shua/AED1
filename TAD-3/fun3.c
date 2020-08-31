#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14 

void menu(void){
     printf("\n1 - Cria_esfera");
     printf("\n2 - Libera_esfera");
     printf("\n3 - Raio");
     printf("\n4 - Área");
     printf("\n5 - Volume");
}

struct TAD
{
    float x,y,z;
};

typedef struct TAD tad;

int Atribuicao(int i)
{
    tad *ponto = (tad *) malloc(i * sizeof(tad));

    if(ponto == NULL)
    { 
        printf("\nNão inseriu memoria...");
        return 0;
    }

    printf("\nInsira o ponto x: ");
    scanf("%f",&ponto->x);

    printf("\nInsira o ponto y: ");
    scanf("%f",&ponto->y);

    printf("\nInsira o ponto z: ");
    scanf("%f",&ponto->z);

    return ponto;
}
/*
float volume(tad *p)
{
    float V
}
*/
void libera(tad *p){
    free(p);
}


float raio(tad *p,tad *p1){
    float distancia = 0, x1,x2,y1,y2,z1,z2;
    x1 = p->x;
    x2 = p1->x;
    y1 = p->y;
    y2 = p1->y;
    z1 = p->z;
    z2 = p1->z;
    distancia = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)+ pow(z2-z1, 2));
    return distancia;
}

void area(tad *p,tad *p1){
    float A = 4 * (PI) * pow(raio(p,p1),2);
    printf ("\nA área é %2.f",A);
}

void volume(tad *p,tad *p1){
    float V = (4 * (PI) * pow(raio(p,p1),3))/3;
    printf ("\nO volume é %2.f",V);
}
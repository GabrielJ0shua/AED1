#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void){
    int i,numero,aux,verificacao,qnt=0;
    lista *li[6];
    do
    {
        printf("\n===================\n[1]Criar Lista\n[2]Inserir elemento\n[3]Remover ímpares\n[4]Remover elemento\n[5]Imprimir a posição do número\n[6]Mostrar o menor elemento\n[7]Tamanho da lista\n[8]Imprimir a lista\n[9]Inverter lista\n[10]Concatenar listas\n[11]Sair\n");
        scanf("%d",&i);        
        switch (i)
        {
            case (1):
                li[qnt] = cria();
                qnt++;
            break;

            case (2):
                if(qnt == 0){
                    printf("\nNão tem lista criada...");
                    break;
                    }
                else
                {
                    printf("\nVocê quer inserir em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                    scanf("%d",&aux);
                    if(aux > qnt)
                    {
                        printf("Essa lista não existe.");
                        break;
                    }
                    printf("Qual número você deseja inserir?");
                    scanf("%d",&numero);
                    verificacao = insercao(li[aux], numero);
                    if (verificacao == 1) printf("\nInserido.");
                    else printf("\nNão inserido.");    
                }
            break;

            case (3):
                printf("\nVocê quer remover em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao = remove_impar(li[aux]);
                if (verificacao == 1) printf("\nRemovido.");
                else printf("\nNão removido.");
            break;

            case (4):
                printf("\nVocê quer remover em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                printf("\nE qual elemento você quer remover? ");
                scanf("%d",&numero);
                verificacao = remove_qualquer(li[aux],numero);
                if (verificacao == 1) printf("\nRemovido.");
                else printf("\nNão removido.");
            break;

            case (5):
                printf("\nVocê quer consultar em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                printf("\nE qual elemento você quer consultar? ");
                scanf("%d",&numero);
                verificacao = consulta_qualquer (li[aux], numero);
                if (verificacao == 0) printf("\nElemento Inexistente.");
                else printf("\n| %d |",verificacao);
            break;

            case (6):
                printf("\nVocê quer consultar em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao =  consulta_menor(li[aux]);
                if (verificacao == 0) printf("\nElemento Inexistente.");
                else printf("\n| %d |",verificacao);
            break;

            case (7):
                printf("\nVocê quer olhar o tamanho de qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao = tamanho(li[aux]);
                if (verificacao == 0)
                {
                    printf("\n Lista Vazia.");
                    break;
                }
                else printf("\b| %d |", verificacao);
            break;
            
            case (8):
                printf("\nVocê quer olhar o tamanho de qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao = imprimir_lista(li[aux]);
                if(verificacao == 1) printf("\n Pronto.");
                else printf("\n Algo deu errado...");
            break;

            case (9):
                printf("\nVocê quer inverter qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                li[qnt] = cria();
                verificacao = inverter_lista(li[aux], li[qnt]);
                if (verificacao == 1)
                {
                    printf("\nInserido.");
                    qnt++;
                }
                else
                {
                    printf("\nNão inserido.");
                    qnt--;
                }
            break;

            case (10):
                printf("\nVocê quer concatenar quais listas?\b Lembrando que tem %d listas\nDigite os números em estilo Array: ",qnt);
                scanf("%d %d",&aux,&verificacao);
                if(aux > qnt || verificacao > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                li[qnt] = cria();
                verificacao = concatenar(li[aux], li[verificacao], li[qnt]);
                if(verificacao == 1){
                    printf("\n Pronto.");
                    qnt++;}
                else{
                    printf("\n Algo deu errado...");
                    qnt--;}
            break;

            case (11):
                while(aux != qnt)
                {
                libera(li[aux]);
                aux++;
                }
                return 0;
            break;
        }
    } while (i>0 && i<12);
    return 1;
}

int imprimir_lista(lista *li){
    if (li == NULL) return 0;
    for (int i = 0; i < li->qnt; i++)
    {
        printf("| %d |",li->num[i]);
    }
    return 1;    
}
#include "tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int i,numero,aux,verificacao,qnt=0;
    lista *li[6];
    do
    {
        printf("\n===================\n[1]Criar Lista\n[2]Inserir elemento\n[3]Remover pares\n[4]Remover elemento qualquer\n[5]Remover elementos\n[6]Imprimir a posição do número\n[7]Mostrar o maior elemento\n[8]Tamanho da lista\n[9]Imprimir a lista\n[10]Intercalar listas\n[11]Sair\n");
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
                    printf("\nVocê quer inserir em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                    scanf("%d",&aux);
                    if(aux > qnt)
                    {
                        printf("Essa lista não existe.");
                        break;
                    }
                printf("Qual número você deseja inserir?");
                scanf("%d",&numero);
                verificacao = insercao_ord(li[aux], numero);
                if (verificacao == 1) printf("\nInserido.");
                else printf("\nNão inserido.");    
            break;

            case (3):
                printf("\nVocê quer remover em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao = remove_par(li[aux]);
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
                verificacao = remove_qualquer(li[aux], numero);
                if (verificacao == 1) printf("\nRemovido.");
                else printf("\nNão removido.");
            break;

            case (5):
                printf("\nVocê quer esvaziar elementos de qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                esvaziar_lista(li[aux]);
            break;

            case (6):
                printf("\nVocê quer consultar em qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("\nEssa lista não existe.");
                    break;
                }
                printf("\nQual número deseja saber a posição: ");
                scanf("%d",&numero);
                verificacao = consulta_qualquer (li[aux],numero);
                if(verificacao == 0) printf("\n Não encontrado.");
                else printf("\n| %d |\n",verificacao);
            break;

            case (7):
                printf("\nVocê quer saber o maior número de qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
                scanf("%d",&aux);
                if(aux > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                verificacao = consulta_maior(li[aux]);
                if(verificacao == 0) printf("\n Algo deu errado...");
                else printf("\n| %d |\n",verificacao);
            break;

            case (8):
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

            case (9):
                printf("\nVocê quer olhar o imprimir qual lista?\b Lembrando que tem %d listas\nDigite o número em estilo Array: ",qnt);
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

            case (10):
                printf("\nVocê quer intercalar quais listas?\b Lembrando que tem %d listas\nDigite os números em estilo Array: ",qnt);
                scanf("%d%d",&aux,&verificacao);
                if(aux > qnt || verificacao > qnt)
                {
                    printf("Essa lista não existe.");
                    break;
                }
                li[qnt] = cria();
                verificacao = intercalar(li[qnt],li[aux], li[verificacao]);
                if(verificacao == 1){
                    printf("\n Pronto.");
                    qnt++;}
                else{
                    printf("\n Algo deu errado...");
                    qnt--;}
            break;

            case (11):
                for(aux = 0; aux != qnt; aux++)
                {
                libera(li[aux]);
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
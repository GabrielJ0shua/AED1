struct numero
{
    int qnt;
    int num[];
};
typedef struct numero lista;
lista *cria();
void libera(lista *li);
int tamanho(lista *li);
int vazia(lista *li);
int insercao_ord(lista *li, int numero);
int remove_qualquer(lista *li, int numero);
int imprimir_lista(lista *li);
int consulta_impar(lista *li);
int remove_par(lista *li);
int consulta_qualquer (lista *li, int numero);
int consulta_maior (lista *li);
int tamanho(lista *li);
int intercalar(lista *aux,lista *li, lista *li2);
int esvaziar_lista(lista *li);
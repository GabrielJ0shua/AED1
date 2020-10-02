struct cabecalho
{
    struct cabecalho *ini;
    struct cabecalho *prox;
    int num;
};
typedef struct cabecalho elem;
typedef struct cabecalho* lista;
lista *cria(void);
void libera (lista *li);
int insere(lista *li,int b);
int ord(lista *li,int b);
int rem(lista *li,int b);
int pos(lista *li,int b);
int imprime(lista *li);
int vazia(lista* li);

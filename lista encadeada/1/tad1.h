struct numero
{
    int nu;
};
struct caixa
{
    int *no;
    struct numero num;
};
typedef struct caixa cad;
typedef struct caixa* lista;
lista *cria(void);
void libera (lista *li);
int insere(lista *li,int l);
int rem(lista *li,int b);
int pos(lista *li,int l);
int imprime(lista *li);  
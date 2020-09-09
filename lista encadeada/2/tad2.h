struct pass
    {
        unsigned int mat;
        char nome[20];
        float me;
        int fal;
    };
struct caixa
{
    struct caixa *no;
    struct pass p;
};
typedef struct caixa cad;
typedef struct caixa* lista;lista *cria(void);
lista *cria(void);
void libera (lista *li);
int insere(lista *li,unsigned int mat,char nome[],float me, int fal);
int rem(lista *li,unsigned int b);
int pos(lista *li,unsigned int b);
int imprime(lista *li);
  
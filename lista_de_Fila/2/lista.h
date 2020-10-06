struct aluno
{
    int matricula, faltas;
    char nome[50];
    float media;
};
typedef struct fila lista;
lista * cria_fila(void);
int tamanho_fila(lista *fi);
int fila_cheia(lista *fi);
int fila_vazia(lista *fi);
int insere_fila(lista *fi,struct aluno *a);
int remove_fila(lista *fi);
int consulta_fila(lista *fi,struct aluno *a);
void clear(void);
void libera_fila(lista *fi);
void imprime(lista *fi);
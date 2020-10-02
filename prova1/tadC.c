#include "tadH.h"

struct lista {
    char info[20];
    struct lista * prox_no;
};

int remove_elemento_inicio(Lista *li)
{
    Lista aux;
    if((*li) == NULL) return 0;
    aux = (*li)->prox_no;
    if(aux->prox_no == aux)
    {
        *li = NULL;
        free(aux);
        return 1;
    }
    (*li)->prox_no = aux->prox_no;
    free(aux);
    return 1;
}
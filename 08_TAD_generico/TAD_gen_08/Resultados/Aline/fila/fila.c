#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    DataType *fila;
    int tamanho;
};

Fila *FilaConstruct()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fila = NULL;
    f->tamanho=0;
    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType))
{
    int i;
    tMovel *m = NULL;
    for(i=0 ; i<FilaSize(f) ; i++)
    {
        destroy(f->fila[i]);
    }
    if(f->fila!=NULL)
    {
        free(f->fila);
    }
    if(f!=NULL)
    {
        free(f);
    }
}

int FilaSize(Fila *f)
{
    return f->tamanho;
}

DataType FilaPop(Fila *f)
{
    int i;
    DataType d = f->fila[0];
    for(i=0 ; i<FilaSize(f)-1 ; i++)
    {
        f->fila[i] = f->fila[i+1];
    }
    f->tamanho--;
    return d;
}

void FilaPush(Fila *f, DataType val)
{
    f->tamanho++;
    f->fila = realloc(f->fila, FilaSize(f)*sizeof(DataType));
    f->fila[FilaSize(f)-1] = val;
}

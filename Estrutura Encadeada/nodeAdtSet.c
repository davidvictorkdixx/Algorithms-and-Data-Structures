#include <stdio.h>
#include <stdlib.h>


#include "nodeAdtSet.h"


void adt_initSet(set_t *C)
{
    C->lider = (position_t) malloc(sizeof(noh));
    C->lider->prox = NULL;
    C->last = C->lider;
}

position_t adt_first(set_t C)
{
    return C.lider;
}

position_t adt_after(position_t p)
{
    return p->prox;
}

position_t adt_last(set_t C)
{
    position_t p = C.lider;
    while(p->prox != NULL && p->prox != C.last)
    {
        p = p->prox;
    }
    return p;
}

int adt_element(set_t C, position_t p)
{
    position_t q = C.lider;
    while(q != p->prox)
    {
        q = q->prox;
    }
    return q->element;
}

position_t adt_position(set_t C, int X)
{
    position_t q = C.lider;
    while(q->prox != NULL && q->prox->element != X)
    {
        q = q->prox;
    }
    if(q == C.last)
    {
        return NULL;
    }
    return q;
}

void adt_insertLast(set_t *C, int X)
{
    position_t p = C->last;
    p->prox = (position_t) malloc(sizeof(noh));
    p->prox->element = X;
    p->prox->prox = NULL;
    C->last = p->prox;
}

void adt_copySet(set_t *U, set_t C1)
{
    position_t p = C1.lider;
    while(p->prox != NULL)
    {
        adt_insertLast(U, p->prox->element);
        p = p->prox;
    }
}





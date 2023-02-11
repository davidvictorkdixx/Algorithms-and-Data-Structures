#include <stdio.h>
#include <stdlib.h>


#include "nodeAdt.h"


void adt_initList(list_t *C)
{
    C->lider = (position_t) malloc(sizeof(node_st));
    C->lider->next = NULL;
    C->last = C->lider;
}

position_t adt_first(list_t C)
{
    return C.lider;
}

position_t adt_after(position_t p)
{
    return p->next;
}

position_t adt_prev(list_t C, position_t p)
{
    position_t q = C.lider;
    if(p == C.lider)
    {
        return NULL;
    }
    while(q->next != p)
    {
        q = q->next;
    }
    return q;
}

position_t adt_last(list_t C)
{
    position_t p = C.lider;
    while(p->next != NULL && p->next != C.last)
    {
        p = p->next;
    }
    return p;
}

atom_st adt_element(list_t C, position_t p)
{
    position_t q = C.lider;
    while(q != p->next)
    {
        q = q->next;
    }
    return q->element;
}

position_t adt_position(list_t C, atom_st X)
{
    position_t q = C.lider;
    while(q->next != NULL && &(q->next->element) != &X)
    {
        q = q->next;
    }
    if(q == C.last)
    {
        return NULL;
    }
    return q;
}

void adt_insertLast(list_t *C, atom_st X)
{
    position_t p = C->last;
    p->next = (position_t) malloc(sizeof(node_st));
    p->next->element = X;
    p->next->next = NULL;
    C->last = p->next;
}

void adt_copyList(list_t *U, list_t C1)
{
    position_t p = C1.lider;
    while(p->next != NULL)
    {
        adt_insertLast(U, p->next->element);
        p = p->next;
    }
}

void adt_emptyList(list_t* listArg)
{
    position_t p = listArg->last, aux;

    while(p != listArg->lider)
    {
        aux = p;
        p = adt_prev(*listArg, p);
        p->next = NULL;
        free(aux);
    }
    listArg->last = p;
}




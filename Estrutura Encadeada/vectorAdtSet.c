#include <stdio.h>
#include <stdlib.h>


#include "vectorAdtSet.h"


void adt_initSet(set_t *C)
{
    C->elements[0] = 0;
    C->lider = C->elements[0];
    C->last = C->lider + 1;
}

position_t adt_first(set_t C)
{
    return C.lider + 1;
}

position_t adt_after(position_t p)
{
    return p + 1;
}

position_t adt_last(set_t C)
{
    return C.last - 1;
}

int adt_element(set_t C, position_t p)
{
    if(p == C.lider || p == C.last)
    {
        return 0;
    }
    return C.elements[p];
}

position_t adt_position(set_t C, int X)
{
    position_t q = C.lider + 1;
    while(q < C.last && C.elements[q] != X)
    {
        q++;
    }
    if(q == C.last)
    {
        return 0;
    }
    return q;
}

void adt_insertLast(set_t *C, int X)
{
    position_t p = C->last;
    C->elements[p] = X;
    C->last = p + 1;
    C->elements[C->last] = 0;
}

void adt_copySet(set_t *U, set_t C1)
{
    position_t p = C1.lider + 1;
    while(p != C1.last)
    {
        adt_insertLast(U, C1.elements[p]);
        p++;
    }
}


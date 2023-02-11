#ifndef _STACKADT_H
#define _STACKADT_H

#include <stdbool.h>

#include "atomAdt.h"
#include "nodeAdt.h"

typedef node_st* position_t;
typedef node_st* stack_t;

void adt_initStack(stack_t *);
void adt_pushStack(stack_t *, atom_st);
void adt_popStack(stack_t *);
atom_st adt_topStack(stack_t);
bool adt_isEmptyStack(stack_t);
void adt_emptyStack(stack_t *);

#endif

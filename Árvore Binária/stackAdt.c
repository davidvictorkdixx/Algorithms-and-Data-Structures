#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stackAdt.h"


void adt_initStack(stack_t* stackArg)
{
    *stackArg = NULL;
}

void adt_pushStack(stack_t* stackArg, atom_st elementArg)
{
    position_t temp = *stackArg;
    *stackArg = (position_t) malloc(sizeof(node_st));
    (*stackArg)->element = elementArg;
    (*stackArg)->next = temp;
}

void adt_popStack(stack_t* stackArg)
{
    position_t temp;
    if(*stackArg != NULL)
    {
        temp = *stackArg;
        *stackArg = (*stackArg)->next;
        free(temp);
    }else
    {
        printf("Empty stack\n");
    }
}

atom_st adt_topStack(stack_t stackArg)
{
    if(stackArg == NULL)
    {
        printf("Empty stack\n");
    }
    return stackArg->element;
}

bool adt_isEmptyStack(stack_t stackArg)
{
    if(stackArg == NULL)
    {
        return true;
    }
    return false;
}

void adt_emptyStack(stack_t* stackArg)
{
    position_t temp = *stackArg;
    while(temp != NULL)
    {
        *stackArg = (*stackArg)->next;
        free(temp);
        temp = *stackArg;
    }
}

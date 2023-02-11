#include <stdio.h>
#include <stdlib.h>


#include "atomAdt.h"
#include "nodeAdt.h"
#include "stackAdt.h"
#include "auxiliary.h"
#include "treeAdt.h"


list_t getPolishList(parenthetical_t parenthetical, int natoms)
{
    list_t polish;
    stack_t auxiliar;

    adt_initList(&polish);
    adt_initStack(&auxiliar);

    for(int j = 0; j < natoms; j++)
    {
        if(parenthetical[j].type == NUMBER)
        {
            adt_insertLast(&polish, parenthetical[j]);
        }
        if(parenthetical[j].type == OP)
        {
            adt_pushStack(&auxiliar, parenthetical[j]);
        }
        if(parenthetical[j].type == CPAR)
        {
            atom_st temp = adt_topStack(auxiliar);
            adt_popStack(&auxiliar);
            adt_insertLast(&polish, temp);
        }
    }
    adt_emptyStack(&auxiliar);
    return polish;
}



bintree_node buildCell(bintree_node nodeArg, atom_st* atomArg)
{
    bintree_node cursor = nodeArg;
    if(cursor->elem->type == NUMBER)
    {
        cursor = cursor->parent;
    }
    while(cursor->lchild != NULL && cursor->rchild != NULL)
    {
        cursor = cursor->parent;
    }

    if(cursor->rchild == NULL)
    {
        cursor->rchild = (bintree_node) malloc(sizeof(cell_st));
        (cursor->rchild)->elem = atomArg;
        (cursor->rchild)->parent = cursor;
        (cursor->rchild)->rchild = NULL;
        (cursor->rchild)->lchild = NULL;
        cursor = cursor->rchild;
    }else
    {
        cursor->lchild = (bintree_node) malloc(sizeof(cell_st));
        (cursor->lchild)->elem = atomArg;
        (cursor->lchild)->parent = cursor;
        (cursor->lchild)->rchild = NULL;
        (cursor->lchild)->lchild = NULL;
        cursor = cursor->lchild;
    }
    return cursor;
}



void buildTree(list_t* listArg, bintree_t* treeArg)
{
    bintree_node cursor;
    position_t q = adt_last(*listArg);
    atom_st *temp = &(listArg->last->element);
    (*treeArg)->elem = temp;
    cursor = *treeArg;

    while(q != adt_first(*listArg))
    {
        temp = &(q->element);
        cursor = buildCell(cursor, temp);
        q = adt_prev(*listArg, q);
    }
}

void printList(list_t listArg)
{
    position_t p = adt_first(listArg);

    if(adt_after(p) == NULL)
    {
        printf("\nEmpty list!\n");
        return;
    }

    printf("\nPolish: ");
    while(p != adt_after(adt_last(listArg)))
    {
        if(adt_element(listArg, p).type == NUMBER)
        {
            printf(" %d ", adt_element(listArg, p).attribute.value);
        }
        if(adt_element(listArg, p).type == OP)
        {
            printf(" %c ", adt_element(listArg, p).attribute.op);
        }
        p = adt_after(p);
    }
    printf("\n");
}


void printTree(bintree_t treeArg)
{
    if(treeArg == NULL)
    {
        return;
    }
    if(treeArg->elem->type == OP)
    {
        printf("(");
    }
    printTree(treeArg->lchild);
    if(treeArg->elem->type == NUMBER)
    {
        printf("%d", treeArg->elem->attribute.value);
    }
    if(treeArg->elem->type == OP)
    {
        printf(" %c ", treeArg->elem->attribute.op);
    }
    printTree(treeArg->rchild);
    if(treeArg->elem->type == OP)
    {
        printf(")");
    }
}

int eval_expression(bintree_t treeArg)
{
    if(treeArg->elem->type == OP)
    {
        if(treeArg->elem->attribute.op == '+')
        {
            return eval_expression(treeArg->lchild) + eval_expression(treeArg->rchild);
        }
        if(treeArg->elem->attribute.op == '*')
        {
            return eval_expression(treeArg->lchild) * eval_expression(treeArg->rchild);
        }
    }
    return treeArg->elem->attribute.value;
}













#ifndef _AUXILIARY_H
#define _AUXILIARY_H

#include "atomAdt.h"
#include "nodeAdt.h"
#include "stackAdt.h"
#include "treeAdt.h"


list_t getPolishList(parenthetical_t, int);
bintree_node buildCell(bintree_node, atom_st *);
void buildTree(list_t *, bintree_t *);
void printList(list_t);
void printTree(bintree_t);
int eval_expression(bintree_t);

#endif


#ifndef _TREEADT_H
#define _TREEADT_H

#include "atomAdt.h"
#include "nodeAdt.h"
#include "stackAdt.h"

typedef struct cell cell_st;
typedef cell_st* bintree_node;
typedef cell_st* bintree_t;

struct cell{
    atom_st* elem;
    bintree_node parent, lchild, rchild;
};

void adt_initTree(bintree_t *);
bintree_node adt_leftChild(bintree_node);
bintree_node adt_rightChild(bintree_node);
bintree_node adt_parent(bintree_node);
atom_st* adt_elementTree(bintree_node);


#endif


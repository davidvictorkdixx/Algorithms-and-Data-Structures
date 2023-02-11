#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "atomAdt.h"
#include "nodeAdt.h"
#include "stackAdt.h"
#include "treeAdt.h"


void adt_initTree(bintree_t* treeArg)
{
    *treeArg = (bintree_node) malloc(sizeof(cell_st));
    (*treeArg)->elem = NULL;
    (*treeArg)->parent = NULL;
    (*treeArg)->lchild = NULL;
    (*treeArg)->rchild = NULL;
}

bintree_node adt_leftChild(bintree_node nodeArg)
{
    return nodeArg->lchild;
}

bintree_node adt_rightChild(bintree_node nodeArg)
{
    return nodeArg->rchild;
}

bintree_node adt_parent(bintree_node nodeArg)
{
    return nodeArg->parent;
}

atom_st* adt_elementTree(bintree_node nodeArg)
{
    return nodeArg->elem;
}


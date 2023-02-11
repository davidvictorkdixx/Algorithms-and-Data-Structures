#include <stdio.h>
#include <stdlib.h>

//#ifdef ATOMADT
#include "atomAdt.h"
//#endif

//#ifdef NODEADT
#include "nodeAdt.h"
//#endif

//#ifdef STACKADT
#include "stackAdt.h"
//#endif

//#ifdef TREEADT
#include "treeAdt.h"
//#endif

//#ifdef AUXILIARY
#include "auxiliary.h"
//#endif


int main(){

    parenthetical_t parenthetical;

    int natoms = make_atoms(&parenthetical);
    print_atoms(parenthetical, natoms);

    list_t PolishList = getPolishList(parenthetical, natoms);
    printList(PolishList);

    bintree_t PolishTree;
    adt_initTree(&PolishTree);
    buildTree(&PolishList, &PolishTree);

    printf("\nParenthetical: ");
    printTree(PolishTree);
    printf("\n\nResult = %d\n", eval_expression(PolishTree));

    adt_emptyList(&PolishList);
    system("pause");
    return 0;
}



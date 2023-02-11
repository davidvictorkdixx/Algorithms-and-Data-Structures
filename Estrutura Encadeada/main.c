#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//#ifdef NODEADTSET
#include "nodeAdtSet.h"
//#endif

//#ifdef VECTORADTSET
//#include "vectorAdtSet.h"
//#endif

//#ifdef AUXILIARY
#include "auxiliary.h"
//#endif



int main(){

    set_t U_s;
    adt_initSet(&U_s);
    U_s = getUniverseSet();
    printf("Universe: ");
    printSet(U_s);
    printf("\n");

    set_t C1;
    adt_initSet(&C1);
    C1 = getFilteredSet();
    printf("C1: ");
    printSet(C1);
    printf("Complement: ");
    printSet(compSet(C1, U_s));
    printf("\n");

    set_t C2 = getFilteredSet();
    printf("C2: ");
    printSet(C2);
    printf("Complement: ");
    printSet(compSet(C2, U_s));
    printf("\n\n");

    printf("Union{C1, C2}: ");
    printSet(unionSet(C1, C2));
    printf("\n");

    printf("Intersection{C1, C2}: ");
    printSet(interSet(C1, C2));
    printf("\n");

    printf("Difference{C1, C2}: ");
    printSet(diffSet(C1, C2));
    printf("\n");

    return 0;
}











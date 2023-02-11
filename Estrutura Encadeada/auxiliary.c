#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "auxiliary.h"
#include "nodeAdtSet.h"
//#include "vectorAdtSet.h"


set_t getUniverseSet(void)
{
    set_t U;
    FILE *fptr = NULL;
    char ERROR[12] = {"Empty set."};
    char ERROR1[21] = {"Cannot open the file."};

    fptr = fopen("universe.txt", "r");
    if(!fptr)
    {
       errorMessage(ERROR1);
       exit(1);
    }

    adt_initSet(&U);

    int number;
    while(fscanf(fptr, "%d ", &number) != EOF)
    {
        adt_insertLast(&U, number);
    }
    fclose(fptr);
    if(adt_after(adt_first(U)) == adt_after(adt_last(U)))
    {
        errorMessage(ERROR);
        exit(1);
    }
    return U;
}

set_t getFilteredSet(void)
{
    FILE *fptr = NULL;
    set_t C, U_s = getUniverseSet();
    char ERROR[12] = {"Empty set."};
    char ERROR1[21] = {"Cannot open the file."};
    char fname[31];

    printf("Enter the set file:\n");
    scanf("%30s", fname);
    fptr = fopen(fname, "r");
    if(!fptr)
    {
       errorMessage(ERROR1);
       exit(1);
    }

    adt_initSet(&C);
    int number;
    while(fscanf(fptr, " %d", &number) != EOF)
    {
        bool exist = false, duplicate = false;
        if(adt_position(U_s, number) != adt_position(U_s, -1))
        {
            exist = true;
        }
        if(adt_position(C, number) != adt_position(C, -1))
        {
            duplicate = true;
        }
        if(exist == true && duplicate == false)
        {
            adt_insertLast(&C, number);
        }
    }
    fclose(fptr);

    if(adt_after(adt_first(C)) == adt_after(adt_last(C)))
    {
        errorMessage(ERROR);
        exit(1);
    }
    return C;
}

void printSet(set_t C)
{
    position_t p = adt_first(C);
    while(p != adt_after(adt_last(C)))
    {
        printf("%d ", adt_element(C, p));
        p = adt_after(p);
    }
    printf("\n");
}

void errorMessage(char *ERROR)
{
    fprintf(stderr, "[ERROR]: %s\n", ERROR);
}

set_t unionSet(set_t C1, set_t C2)
{
    set_t U;
    adt_initSet(&U);
    adt_copySet(&U, C1);
    position_t p = adt_first(C2);
    while(adt_after(p) != adt_after(adt_after(adt_last(C1))))
    {
        int X = adt_element(C2, p);
        if(adt_position(C1, X) == adt_after(adt_after(adt_last(C1))))
        {
            adt_insertLast(&U, X);
        }
        p = adt_after(p);
    }
    return U;
}

set_t interSet(set_t C1, set_t C2)
{
    set_t I;
    adt_initSet(&I);
    position_t p = adt_first(C2);
    while(adt_after(p) != adt_after(adt_after(adt_last(C1))))
    {
        int X = adt_element(C2, p);
        if(adt_position(C1, X) != adt_after(adt_after(adt_last(C1))))
        {
            adt_insertLast(&I, X);
        }
        p = adt_after(p);
    }
    return I;
}

set_t diffSet(set_t C1, set_t C2)
{
    set_t D;
    adt_initSet(&D);
    position_t p = adt_first(C1);
    while(adt_after(p) != adt_after(adt_after(adt_last(C2))))
    {
        int X = adt_element(C1, p);
        if(adt_position(C2, X) == adt_position(C1, -1) && X != 0)
        {
            adt_insertLast(&D, X);
        }
        p = adt_after(p);
    }
    return D;
}

set_t compSet(set_t C, set_t U_s)
{
    set_t COMP;
    adt_initSet(&COMP);
    position_t p = adt_first(U_s);

    while(adt_after(p) != adt_after(adt_after(adt_last(U_s))))
    {
        int X = adt_element(U_s, p);
        if(adt_position(C, X) == adt_position(C, -1))
        {
            adt_insertLast(&COMP, X);
        }
        p = adt_after(p);
    }
    return COMP;
}






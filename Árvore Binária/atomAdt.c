#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "atomAdt.h"


char get_non_blank(expression_t exprArg, int i)
{
    while(isspace(exprArg[i]) || (iscntrl(exprArg[i]) && exprArg[i] != '\0'))
    {
        i++;
    }
    return exprArg[i];
}

char get_next(expression_t exprArg, int i)
{
    i++;
    return exprArg[i];
}

void init_expr(int i)
{
    if(i != 0)
    {
        i = 0;
    }
}


int make_atoms(parenthetical_t *parenthetical)
{
    FILE *fptr = NULL;
    char fname[31];

    printf("Expression file:\n");
    scanf("%30s", fname);

    fptr = fopen(fname, "r");
    if(!fptr)
    {
       fprintf(stderr, "Cannot open %s\n", fname);
       exit(1);
    }
    expression_t expr;
    fgets(expr, MAX_EXPR, fptr);
    printf("\nExpression: %s\n", expr);
    fclose(fptr);

    int natoms = 0, i = 0;
    init_expr(i);
    while(expr[i + 1] != '\0')
    {
        while(isspace(expr[i]) != 0 || iscntrl(expr[i]) != 0)
        {
            i++;
        }
        switch(expr[i])
        {
            case '+':
            case '*':
                (*parenthetical)[natoms].type = OP;
                (*parenthetical)[natoms].attribute.op = expr[i];
                break;
            case '(':
                (*parenthetical)[natoms].type = OPAR;
                break;
            case ')':
                (*parenthetical)[natoms].type = CPAR;
                break;
            default:
                (*parenthetical)[natoms].type = INVAL;
                (*parenthetical)[natoms].attribute.character = expr[i];
                break;
        }

        if(isdigit(expr[i]) != 0)
        {
            char aux[MAX_EXPR] = {0};
            int j = 0, num;
            while(isdigit(expr[i]) != 0)
            {
                aux[j] = expr[i];
                j++;
                i++;
            }
            i--;
            aux[j] = '\0';
            sscanf(aux, "%d", &num);
            (*parenthetical)[natoms].type = NUMBER;
            (*parenthetical)[natoms].attribute.value = num;
        }

        i++;
        natoms++;
    }
    return natoms;
}


void print_atoms(parenthetical_t parenthetical, int natoms)
{
    printf("type\t |  attribute\n");
    printf("-----------------------\n");
    for(int j = 0; j < natoms; j++)
    {
        if(parenthetical[j].type == NUMBER)
        {
            printf("NUMBER\t |  %d\n", parenthetical[j].attribute.value);
        }
        if(parenthetical[j].type == OP)
        {
            printf("OP\t |  %c\n", parenthetical[j].attribute.op);
        }
        if(parenthetical[j].type == OPAR)
        {
            printf("OPAR\t |  \n");
        }
        if(parenthetical[j].type == CPAR)
        {
            printf("CPAR\t |  \n");
        }
        if(parenthetical[j].type == INVAL)
        {
            printf("INVAL\t |  %c\n", parenthetical[j].attribute.character);
        }
    }
    printf("-----------------------\n");
}


#ifndef _ATOMADT_H
#define _ATOMADT_H

#define MAX_ATOMS 100
#define MAX_EXPR 1000


typedef enum{NUMBER, OP, OPAR, CPAR, INVAL} type_et;

typedef union{
    int value;
    char op;
    char character;
} attribute_ut;

typedef struct{
    type_et type;
    attribute_ut attribute;
} atom_st;

typedef char expression_t[MAX_EXPR];
typedef atom_st parenthetical_t[MAX_ATOMS];

int make_atoms(parenthetical_t *);
void print_atoms(parenthetical_t, int);
char get_non_blank(expression_t, int);
char get_next(expression_t, int);
void init_expr(int);


#endif

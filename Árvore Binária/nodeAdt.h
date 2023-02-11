#ifndef _NODEADT_H
#define _NODEADT_H


#include "atomAdt.h"

typedef struct node_st node_st;
typedef struct list_st list_t;
typedef node_st* position_t;

struct node_st{
    atom_st element;
    position_t next;
};

struct list_st{
    position_t lider, last;
};

void adt_initList(list_t *);
position_t adt_first(list_t);
position_t adt_after(position_t);
position_t adt_prev(list_t, position_t);
position_t adt_last(list_t);
atom_st adt_element(list_t, position_t);
position_t adt_position(list_t, atom_st);
void adt_insertLast(list_t *, atom_st);
void adt_copyList(list_t *, list_t);
void adt_emptyList(list_t *);


#endif

#ifndef _NODEADTSET_H
#define _NODEADTSET_H


typedef struct noh noh;
typedef struct set_t set_t;
typedef noh *position_t;

struct noh{
    int element;
    position_t prox;
};

struct set_t{
    position_t lider, last;
};

void adt_initSet(set_t *);
position_t adt_first(set_t);
position_t adt_after(position_t);
position_t adt_last(set_t);
int adt_element(set_t, position_t);
position_t adt_position(set_t, int);
void adt_insertLast(set_t *, int);
void adt_copySet(set_t *, set_t);


#endif


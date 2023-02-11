#ifndef _VECTORADTSET_H
#define _VECTORADTSET_H

//const int MAX = 20;
#define MAX 22

typedef struct set_t set_t;
typedef int position_t;
typedef int vector[MAX + 1];

struct set_t{
    vector elements;
    position_t last, lider;
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


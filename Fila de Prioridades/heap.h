/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#ifndef HEAP_H
#define HEAP_H


#include <stdbool.h>

typedef struct atom_st atom_st;

struct atom_st{
    int id;
    int p;
    int deadline;
};

void sift(atom_st *v, int n, int i);
void swap(atom_st *x, atom_st *y);
void build_heap(atom_st *v, int n);
bool min(atom_st *v, int size, int *r);
bool extract_min(atom_st *v, int *size, int *minv);
bool modify(atom_st *v, int size, int k, int x);
bool insert(atom_st *v, int *size, int x);
void heap_sort(atom_st *v, int n);

#endif


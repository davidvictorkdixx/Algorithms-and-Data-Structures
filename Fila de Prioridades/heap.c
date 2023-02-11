/*********************************************/
/* Aluno: David Victor 			     */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


void sift(atom_st *v, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if(left < n && v[left].p < v[smallest].p)
    {
         smallest = left;
    }
    if(right < n && v[right].p < v[smallest].p)
    {
        smallest = right;
    }
    if(smallest != i)
    {
        swap(&v[i], &v[smallest]);
        sift(v, n, smallest);
    }
}

void swap(atom_st *x, atom_st *y)
{
    int p_aux = x->p;
    int id_aux = x->id;
    int deadline_aux = x->deadline;

    x->p = y->p;
    x->id = y->id;
    x->deadline = y->deadline;

    y->p = p_aux;
    y->id = id_aux;
    y->deadline = deadline_aux;
}

void build_heap(atom_st *v, int n)
{
    for(int i = (n / 2) - 1; i >= 0; --i)
    {
        sift(v, n, i);
    }
}

bool min(atom_st *v, int size, int *r)
{
    if(size > 0)
    {
        *r = v[0].p;
        return true;
    }
    return false;
}

bool extract_min(atom_st *v, int *size, int *minv)
{
    if(*size < 1)
    {
        return false;
    }
    *minv = v[0].p;
    v[0] = v[*size - 1];
    (*size)--;
    sift(v, *size, 0);
    return true;
}


bool modify(atom_st *v, int size, int k, int x)
{
    if(k > size || k < 0 || size < 1)
    {
        return false;
    }
    v[k].p = x;
    while (k > 0 && v[(k - 1) / 2].p > v[k].p)
    {
        swap(&v[k], &v[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
    sift(v, size, k);
    return true;
}

bool insert(atom_st *v, int *size, int x)
{
    (*size)++;
    return modify(v, *size, *size - 1, x);
}

void heap_sort(atom_st *v, int n)
{
    build_heap(v, n);
    for(int i = 1; i < n; ++i)
    {
        swap(&v[i], &v[n - 1]);
        sift(v, i, 0);
    }
}

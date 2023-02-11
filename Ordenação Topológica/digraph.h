#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdbool.h>

#include "stack.h"

typedef struct digraph DIGRAPH;
typedef struct edge edge;

struct edge{
    int index;
    edge *next;
};

struct digraph{
  int order;
  edge **vertex;
};

DIGRAPH *digraph_read();
DIGRAPH *digraph_create(int order);
void digraph_destroy(DIGRAPH *digraph);
void digraph_add_edge(DIGRAPH *digraph, int u, int v);
bool digraph_has_edge(const DIGRAPH *digraph, int u, int v);


void topological_sort(const DIGRAPH *digraph);
bool DFS(const DIGRAPH *digraph, int v, STACK *S, int *expl, int *comp);


#endif // DIGRAPH_H


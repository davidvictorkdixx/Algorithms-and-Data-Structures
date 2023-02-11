#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graph GRAPH;
typedef struct edge edge;

struct edge{
    int index;
    edge *next;
};

struct graph{
  int order;
  edge **vertex;
};

GRAPH *graph_read();
GRAPH *graph_create(int order);
void graph_destroy(GRAPH *graph);
void graph_add_edge(GRAPH *graph, int u, int v);
bool graph_has_edge(const GRAPH *graph, int u, int v);

void graph_pivot_points(const GRAPH *graph);
void DFS(const GRAPH *graph, int v, int *expl, int *m, int *dad);

#endif

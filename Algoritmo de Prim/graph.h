#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graph GRAPH;
typedef struct edge edge;

struct edge{
    int index;
    int weight;
    edge *next;
};

struct graph{
  int order;
  edge **vertex;
};

GRAPH *graph_read();
GRAPH *graph_create(int order);
void graph_destroy(GRAPH *graph);
void graph_add_edge(GRAPH *graph, int u, int v, int w);
bool graph_has_edge(const GRAPH *graph, int u, int v);
int graph_edge_weight(const GRAPH *graph, int u, int v);

void graph_MST(const GRAPH *graph);

#endif


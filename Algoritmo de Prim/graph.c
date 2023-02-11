/*********************************************/
/* Aluno: David Victor	                     */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define infinite 1000000
#define undefined -1000000


GRAPH *graph_read()
{
    int order, u, v, weight;
    scanf("%d ", &order);
    GRAPH *g = graph_create(order);
    while(scanf("%d %d %d", &u, &v, &weight) == 3)
    {
        graph_add_edge(g, u, v, weight);
    }
    return g;
}

GRAPH *graph_create(int order)
{
    GRAPH *g = (GRAPH *) malloc(sizeof(GRAPH));
    g->order = order;
    g->vertex = (edge **) malloc(order * sizeof(edge*));

    for(int i = 0; i < order; i++)
    {
        g->vertex[i] = (edge *) malloc(sizeof(edge*));
        g->vertex[i]->next = NULL;
    }
    return g;
}

void graph_destroy(GRAPH *graph)
{
    if(graph)
    {
        if(graph->vertex)
        {
            for(int j = 0; j < graph->order; j++)
            {
                edge *first = graph->vertex[j]->next;
                while(first)
                {
                    edge *temp = first;
                    first = first->next;
                    free(temp);
                }
            }
            free(graph->vertex);
        }
        free(graph);
    }
}

void graph_add_edge(GRAPH *graph, int u, int v, int w)
{
    edge *new_edge1 = (edge *) malloc(sizeof(edge));
    new_edge1->index = v;
    new_edge1->weight = w;
    new_edge1->next = graph->vertex[u]->next;
    graph->vertex[u]->next = new_edge1;

    if(u != v)
    {
        edge *new_edge2 = (edge *) malloc(sizeof(edge));
        new_edge2->index = u;
        new_edge2->weight = w;
        new_edge2->next = graph->vertex[v]->next;
        graph->vertex[v]->next = new_edge2;
    }
}

bool graph_has_edge(const GRAPH *graph, int u, int v)
{
    if(graph == NULL)
    {
        return false;
    }

    edge *temp = graph->vertex[u]->next;
    while(temp)
    {
        if(temp->index == v)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int graph_edge_weight(const GRAPH *graph, int u, int v)
{
    edge *temp = graph->vertex[u]->next;
    while(temp->index != v)
    {
        temp = temp->next;
    }
    return temp->weight;
}


void graph_MST(const GRAPH *graph)
{
    int order = graph->order;
    int *key   = (int *) malloc(order * sizeof(int));
    int *p     = (int *) malloc(order * sizeof(int));
    bool *tree = (bool *) malloc(order * sizeof(bool));

    for(int i = 0; i < order; i++)
    {
        key[i]  = infinite;
        p[i]    = undefined;
        tree[i] = false;
    }
    key[0]  = 0;
    tree[0] = true;

    edge *x = graph->vertex[0]->next;
    while(x != NULL)
    {
        p[x->index] = 0;
        key[x->index] = x->weight;
        x = x->next;
    }

    while(true)
    {
        int min = infinite, v;
        for(int w = 0; w < order; w++)
        {
            if(tree[w] == false && key[w] < min)
            {
                min = key[w];
                v = w;
            }
        }

        if(min == infinite)
        {
            break;
        }
        tree[v] = true;
        printf("%d %d %d\n", v, p[v], graph_edge_weight(graph, p[v], v));

        edge *x = graph->vertex[v]->next;
        while(x != NULL)
        {
            if(tree[x->index] == false && x->weight < key[x->index])
            {
                key[x->index] = x->weight;
                p[x->index] = v;

            }
            x = x->next;
        }
    }
    free(key);
    free(p);
    free(tree);
}




/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "graph.h"

#define undefined -1000000

GRAPH *graph_read()
{
    int order, u, v;
    scanf("%d ", &order);

    GRAPH *g = graph_create(order);
    while(scanf("%d %d ", &u, &v) == 2)
    {
        graph_add_edge(g, u, v);
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

void graph_add_edge(GRAPH *graph, int u, int v)
{
    edge *new_edge1 = (edge *) malloc(sizeof(edge));
    new_edge1->index = v;
    new_edge1->next = graph->vertex[u]->next;
    graph->vertex[u]->next = new_edge1;

    if(u != v)
    {
        edge *new_edge2 = (edge *) malloc(sizeof(edge));
        new_edge2->index = u;
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


void graph_pivot_points(const GRAPH *graph)
{
    int *expl   = (int *) malloc((graph->order + 1) * sizeof(int));
    int *dad    = (int *) malloc((graph->order + 1) * sizeof(int));
    int *m      = (int *) malloc(graph->order * sizeof(int));
    bool *pivot = (bool *) malloc(graph->order * sizeof(bool));

    for(int i = 0; i < graph->order; i++)
    {
        expl[i]  = 0;
        m[i]     = 0;
        dad[i]   = undefined;
        pivot[i] = false;
    }
    expl[graph->order] = 0;
    dad[graph->order] = 0;
    DFS(graph, 0, expl, m, dad);

    int p = 0;
    for(int v = 1; v < graph->order; v++)
    {
        p = dad[v];
        if(pivot[p] == true || (m[v] >= expl[p]))
        {
            pivot[p] = true;
        }
    }

    if(dad[graph->order] >= 2)
    {
        printf("%d\n", 0);
    }

    for(int i = 1; i < graph->order; i++)
    {
        if(pivot[i] == true)
        {
            printf("%d\n", i);
        }
    }
    free(expl);
    free(dad);
    free(m);
    free(pivot);
}

void DFS(const GRAPH *graph, int v, int *expl, int *m, int *dad)
{
    expl[v] = ++expl[graph->order];
    m[v] = expl[v];

    edge *x = graph->vertex[v]->next;
    while(x != NULL)
    {
        if(expl[x->index] == 0)
        {
            dad[x->index] = v;
            if(v == 0)
            {
                dad[graph->order]++;
            }
            DFS(graph, x->index, expl, m, dad);
            if(m[x->index] < m[v])
            {
                m[v] = m[x->index];
            }
        }else if(x->index != dad[v])
        {
            if(expl[x->index] < m[v])
            {
                m[v] = expl[x->index];
            }
        }
        x = x->next;
    }
}



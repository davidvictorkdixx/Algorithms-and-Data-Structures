/*********************************************/
/* Aluno: David Victor         		     */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"

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

void graph_print(const GRAPH *graph)
{
    for(int u = 0; u < graph->order; ++u)
    {
        for(int v = 0; v < graph->order; ++v)
        {
            if(graph_has_edge(graph, u, v))
            {
                printf("w(%d -> %d) = %d \n", u, v, graph_edge_weight(graph, u, v));
            }
            /*else
            {
                printf("INF \n");
            }*/
        }
        printf("\n");
    }
}

void dijkstra(const GRAPH *graph, int u)
{
    int order = graph->order;
    int *path = (int *) malloc(order * sizeof(int));
    int *dist = (int *) malloc(order * sizeof(int));
    bool *U = (bool *) malloc(order * sizeof(bool));

    for(int i = 0; i < order; i++)
    {
        path[i] = undefined;
        dist[i] = infinite;
        U[i] = true;
    }
    dist[u] = 0;

    while(U_isEmpty(U, order) == false)
    {
        int v = get_argMin(U, dist, order, u);
        edge *x = graph->vertex[v]->next;

        while(x != NULL)
        {
            if((dist[v] + graph_edge_weight(graph, v, x->index)) < dist[x->index])
            {
                dist[x->index] = dist[v] + graph_edge_weight(graph, v, x->index);
                path[x->index] = v;
            }
            x = x->next;
        }
    }
    graph_paths(path, dist, order, u);
}

bool U_isEmpty(bool *U, int order)
{
    for(int i = 0; i < order; i++)
    {
        if(U[i] == true)
        {
            return false;
        }
    }
    return true;
}

int get_argMin(bool *U, int *dist, int order, int u)
{
    int v = 0;
    for(int i = 0; i < order; i++)
    {
        bool arg_min = true;
        if(U[i] == true)
        {
            for(int j = 0; j < order; j++)
            {
                if(U[j] == true)
                {
                    if(dist[i] > dist[j] && j != u)
                    {
                        arg_min = false;
                        break;
                    }
                }
            }
            if(arg_min == true)
            {
                U[i] = false;
                v = i;
                break;
            }
        }
    }
    return v;
}

void graph_paths(int *path, int *dist, int order, int u)
{
    for(int i = 0; i < order; i++)
    {
        STACK *S = stack_create();
        while(i == u || dist[i] == infinite)
        {
            i++;
        }
        if(i >= order)
        {
            break;
        }
        int v = i;
        stack_push(S, i);
        while(path[v] != undefined)
        {
            stack_push(S, path[v]);
            v = path[v];
        }

        while(stack_isEmpty(S) == false)
        {
            v = stack_top(S);
            stack_pop(S);
            printf("%d ", v);
        }
        printf(": %d\n", dist[i]);
        stack_destroy(S);
    }
}

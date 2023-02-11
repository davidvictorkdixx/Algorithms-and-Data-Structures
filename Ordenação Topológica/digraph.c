/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "digraph.h"
#include "stack.h"


DIGRAPH *digraph_read()
{
    int order, u, v;
    scanf("%d ", &order);

    DIGRAPH *g = digraph_create(order);
    while(scanf("%d %d ", &u, &v) == 2)
    {
        digraph_add_edge(g, u, v);
    }
    return g;
}

DIGRAPH *digraph_create(int order)
{
    DIGRAPH *g = (DIGRAPH *) malloc(sizeof(DIGRAPH));
    g->order = order;
    g->vertex = (edge**) malloc(order * sizeof(edge*));

    for(int i = 0; i < order; i++)
    {
        g->vertex[i] = (edge *) malloc(sizeof(edge*));
        g->vertex[i]->next = NULL;
    }
    return g;
}

void digraph_destroy(DIGRAPH *digraph)
{
    if(digraph)
    {
        if(digraph->vertex)
        {
            for(int j = 0; j < digraph->order; j++)
            {
                edge *first = digraph->vertex[j]->next;
                while(first)
                {
                    edge *temp = first;
                    first = first->next;
                    free(temp);
                }
            }
            free(digraph->vertex);
        }
        free(digraph);
    }
}

void digraph_add_edge(DIGRAPH *digraph, int u, int v)
{
    edge *new_edge = (edge *) malloc(sizeof(edge));
    new_edge->index = v;

    edge *aux = digraph->vertex[u]->next;

    while(aux != NULL && aux->next != NULL)
    {
        aux = aux->next;
    }
    if(aux == NULL)
    {
        digraph->vertex[u]->next = new_edge;
    }else
    {
        aux->next = new_edge;
    }
    new_edge->next = NULL;
}

bool digraph_has_edge(const DIGRAPH *digraph, int u, int v)
{
    if(digraph == NULL)
    {
        return false;
    }

    edge *temp = digraph->vertex[u]->next;
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

// Returns false if is not dag
static bool topological_sort_dfs(const DIGRAPH *digraph, STACK *stack)
{
    bool acicle = true;
    int *expl = (int *) malloc((digraph->order + 1) * sizeof(int));
    int *comp = (int *) malloc((digraph->order + 1) * sizeof(int));

    for(int i = 0; i <= digraph->order; i++)
    {
        expl[i] = 0;
        comp[i] = 0;
    }
    for(int v = 0; v < digraph->order; v++)
    {
        if(expl[v] == 0)
        {
            acicle = DFS(digraph, v, stack, expl, comp);
            if(acicle == false)
            {
                return false;
            }
        }
    }
    return true;
}

void topological_sort(const DIGRAPH *digraph)
{
    STACK *S = stack_create();
    bool dag = topological_sort_dfs(digraph, S);
    if(dag == true)
    {
        while(stack_isEmpty(S) == false)
        {
            int u = stack_top(S);
            stack_pop(S);
            printf("%d ", u);
        }
    }
    stack_destroy(S);
    printf("\n");
}

bool DFS(const DIGRAPH *digraph, int v, STACK *S, int *expl, int *comp)
{
    bool acicle = true;
    expl[v] = ++expl[digraph->order];
    edge *x = digraph->vertex[v]->next;
    while(x != NULL)
    {
        int u = x->index;
        if(expl[u] == 0)
        {
            acicle = DFS(digraph, u, S, expl, comp);
        }else if(expl[u] < expl[v] && comp[u] == 0)
        {
            acicle = false;
            break;
        }
        x = x->next;
    }
    comp[v] = ++comp[digraph->order];
    stack_push(S, v);
    return acicle;
}


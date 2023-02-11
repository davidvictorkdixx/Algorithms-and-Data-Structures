/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#define MAX 100

int main()
{
    int n = 0, id, p, deadline;
    atom_st v[MAX];

    while(scanf(" %d %d %d", &id, &p, &deadline) == 3)
    {
        v[n].id = id;
        v[n].p = p;
        v[n].deadline = deadline;
        n++;

    }

    heap_sort(v, n);
    int t_now = 0;

    for(int i = 0; i < n; i++)
    {
        t_now += v[i].p;
        if(t_now > v[i].deadline)
        {
            printf("safety => {t: %d, id: %d, proc_time: %d, deadline: %d}\n", t_now, v[i].id, v[i].p, v[i].deadline);
            break;
        }
    }
    return 0;
}

/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


int main() {
  GRAPH *graph = graph_read();
  //graph_print(graph);

  dijkstra(graph, 0);
  graph_destroy(graph);
}

/*********************************************/
/* Aluno: David Victor	  	             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


int main(){
  GRAPH *graph = graph_read();

  graph_pivot_points(graph);
  graph_destroy(graph);

  return 0;
}

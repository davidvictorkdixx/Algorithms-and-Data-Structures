/*********************************************/
/* Aluno: David Victor 		             */
/* CES-11: Algoritmos e Estruturas de dados  */
/* Turma T2                                  */
/*********************************************/


#include "digraph.h"

int main() {
  DIGRAPH *digraph = digraph_read();

  topological_sort(digraph);
  digraph_destroy(digraph);
}

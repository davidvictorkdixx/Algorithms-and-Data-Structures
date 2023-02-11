// LAB 2,1 - David Victor 

//    LINHA DE COMPILAÇÃO: gcc main.c -std=c11 -Wall -Wextra  -pedantic -v  -o main atomAdt.c -std=c11 -Wall -Wextra -pedantic -v -o atomAdt nodeAdt.c -std=c11 -Wall -Wextra  -pedantic -v  -o nodeAdt stackAdt.c -std=c11 -Wall -Wextra -pedantic -v -o stackAdt treeAdt.c -std=c11 -Wall -Wextra -pedantic -v -o treeAdt auxiliary.c -std=c11 -Wall -Wextra -pedantic -v -o lab

//                          BREVE DESCRIÇÃO

//           O arquivo princial é main.c; o executável lab.exe também 
// está incluído na pasta. Basta executá-lo. 


//           A linha de compilação e a saída gerada está no arquivo 
// output.txt; foi utilizado o próprio prompt de comando do windows. 


//           O arquivo input.txt possui um caso teste de expressão
// parentética. Na execução, o programa solicita: "Expression file:",
// bastando digitar input.txt e dar enter.


//           Os protótipos das funções de atomAdt.h foram alteradas 
// com o objetivo de se evitar o uso de variáveis globais.


//           Existe um arquivo .c adicional: auxiliary.c. Ele possui
// algumas funções auxiliares que foram utilizadas no programa. A seguir
// fornece-se uma breve descrição dessas funções:


//    getPolishList(parenthetical_t, int): realiza a leitura de um vetor
// de átomos e constrói uma lista encadeada para guardar a polonesa.

//    buildCell(bintree_node, atom_st *): constrói cada célula de uma
// árvore, dado o átomo correspondente a ser guardado na célula.

//    buildTree(list_t *, bintree_t *): constrói a árvore que guardará
// a polonesa a partir da lista encadeada que guarda a polonesa.

//    printList(list_t): imprime na tela a polonesa guardada na lista
// encadeada.

//    printTree(bintree_t): imprime em ordem central a árvore que guarda
// a polonesa. Assim, obtém-se a parentética inicial.

//   eval_expression(bintree_t): calcula o valor final da expressão.
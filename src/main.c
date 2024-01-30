#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

int main() {
    // Exemple d'utilisation
    struct graph* my_graph = create_graph(3);

    print_graph(my_graph);
    breadth_first_search(my_graph, 0);
    depth_first_search(my_graph, 0);
    
    //sousgrapheInduit(my_graph, tabIndice, nb_nodes); // A finir
    //sousgraphePartiel(my_graph, tabArcs, nb_arcs); // A finir
    //delete_graph(my_graph); // A finir
    return 0;
}
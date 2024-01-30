#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

int main() {
    // Exemple d'utilisation
    struct graph* my_graph = create_graph(3);

    print_graph(my_graph);
    
    //bfs(my_graph, 0); // A finir
    //depth_first_search(my-graph, 0);$
    
    //sousgraphe1(my_graph, tabIndice, nb_nodes); // A finir
    //sousgraphe2(my_graph, tabArcs, nb_arcs); // A finir
    //delete_graph(my_graph); // A finir
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

int main{
    // Exemple d'utilisation
    graph* my_graph = create_graph(3);

    add_arc(&my_graph -> nodes[0], &my_graph -> nodes[1], 5);
    add_arc(&my_graph -> nodes[0], &my_graph -> nodes[2], 10);
    add_arc(&my_graph -> nodes[1], &my_graph -> nodes[2], 2);

    //print_graph(my_graph);
    return 0;
}
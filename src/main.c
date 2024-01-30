#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

int main{
    // Exemple d'utilisation
    graph* my_graph = create_graph(3);

    add_arc(&my_graph -> nodes[0], &my_graph -> nodes[1], 5);
    add_arc(&my_graph -> nodes[0], &my_graph -> nodes[2], 10);
    add_arc(&my_graph -> nodes[1], &my_graph -> nodes[2], 2);

    print_graph(my_graph);
    
    bfs(my_graph, 0);
    dfs_init(my_graph, 0);    
    
    sousgraphe1(my_graph, int* tabIndice, int nb_nodes);//a modifier
    sousgraphe2(my_graph, int* tabArcs, int nb_arcs);//a modifier
    delete_graph(my_graph);
    return 0;
}
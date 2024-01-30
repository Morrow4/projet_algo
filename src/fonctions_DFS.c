// fonctions_DFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction de parcours en profondeur (DFS)

node* dfs_graph(graph* graph, int val) {
    if (graph -> nodes == NULL) {
        return NULL ;
    }
    node** node_array = graph -> nodes;
    int i = 0;
    while (node_array[i] != NULL) {
        if (node_array[i] -> data == val) {
            return node_array[i];
        }
        i++;    
    }
}
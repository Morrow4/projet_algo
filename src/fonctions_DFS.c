// fonctions_DFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

// Fonction de parcours en profondeur (DFS)
void dfs(graph* graph, int start_node_index, int* visited) {
    if (graph == NULL || start_node_index < 0 || start_node_index >= graph -> nb_nodes) {
        return;
    }
    printf("Visited Node: %d\n", graph -> nodes[start_node_index].data);
    visited[start_node_index] = 1;
    arc* current_arc = graph -> nodes[start_node_index].arcs;
    while (current_arc != NULL) {
        if (!visited[current_arc -> destination -> data]) {
            dfs(graph, current_arc -> destination -> data, visited);
        }
        current_arc = current_arc -> next;
    }
}

// Fonction d'initialisation pour le parcours en profondeur (DFS)
void dfs_traversal(graph* graph, int start_node_index) {
    if (graph == NULL || start_node_index < 0 || start_node_index >= graph -> nb_nodes) {
        return;
    }
    int* visited = (int*)calloc(graph -> nb_nodes, sizeof(int));
    if (visited == NULL) {
        return;
    }
    dfs(graph, start_node_index, visited);
    free(visited);
}

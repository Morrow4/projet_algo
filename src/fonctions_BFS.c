// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

// Fonction de parcours en largeur (BFS)
void bfs(graph* graph, int start_node_i) {
    if (graph == NULL || start_node_i < 0 || start_node_i >= graph->nb_nodes) {
        return;
    }

    queue* queue = create_queue();
    int* visited = (int*)calloc(graph->nb_nodes, sizeof(int));

    if (queue == NULL || visited == NULL) {
        return;
    }

    enqueue(queue, &(g->nodes[start_node_index]));
    visited[start_node_index] = 1;

    while (!is_queue_empty(queue)) {
        node* current_node = dequeue(queue);
        printf("Visited Node: %d\n", current_node->data);

        arc* current_arc = current_node->arcs;
        while (current_arc != NULL) {
            if (!visited[current_arc->destination->data]) {
                enqueue(queue, current_arc->destination);
                visited[current_arc->destination->data] = 1;
            }
            current_arc = current_arc->next;
        }
    }

    free(visited);
    free(q);
}

// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

/* Breadth-First Search (BFS) */

void bfs(graph* graph, int start_node_index) {
    // Initialisation
    int* visited = (int*)malloc(graph->nb_nodes * sizeof(int));
    for (int i = 0; i < graph->nb_nodes; ++i) {
        visited[i] = 0;
    }

    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->tete = NULL;
    enqueue(q, &graph->nodes[start_node_index]); // Enfiler le nœud initial
    visited[start_node_index] = 1; // Marquer le nœud initial comme visité

    // Boucle principale
    while (!is_empty(q)) {
        node* current_node = dequeue(q); // Défiler un nœud
        printf("%d ", current_node->data);

        arc* current_arc = current_node->arc; // Explorer les voisins du nœud actuel
        while (current_arc != NULL) {
            if (!visited[current_arc->destination->ID]) {
                // Enfiler les nœuds non visités
                enqueue(q, current_arc->destination);
                visited[current_arc->destination->ID] = 1;
            }
            current_arc = current_arc->next;
        }
    }
    free(visited);
    free(q);
}
// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction de parcours en largeur sur le graphe
void breadth_first_search(graph* graph, int source) {
    // Vérification des arguments
    if (graph == NULL || graph->head == NULL) {
        printf("Invalid graph!\n");
        return;
    }

    // Initialisation des nœuds visités
    int* visited = (int*)malloc(sizeof(int) * graph->nb_nodes);
    if (visited == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    // Création de la file pour stocker les nœuds à visiter
    queue* queue = (queue*)malloc(sizeof(queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        free(visited);
        return;
    }
    queue->head = NULL;

    // Ajouter le nœud source à la file
    enqueue(queue, graph->head);

    // Parcours en largeur
    while (!is_empty(queue)) {
        node* current = dequeue(queue);

        // Si le nœud n'a pas été visité
        if (!visited[current->ID]) {
            printf("Visited node: %d\n", current->ID);
            visited[current->ID] = 1; // Marquer le nœud comme visité

            // Ajouter tous les nœuds adjacents non visités à la file
            arc* arc = current->arc;
            while (arc != NULL) {
                if (!visited[arc->destination->ID]) {
                    enqueue(queue, arc->destination);
                }
                arc = arc->next;
            }
        }
    }

    // Libération de la mémoire
    free_queue(queue);
    free(visited);
}
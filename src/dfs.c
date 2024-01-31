#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction de parcours en profondeur sur le graphe
void depth_first_search(graph* graph, int source) {
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

    // Création de la pile pour stocker les nœuds à visiter
    stack* stack = NULL;

    // Empiler le nœud source
    push(&stack, graph->head);

    // Parcours en profondeur
    while (stack != NULL) {
        node* current = pop(&stack);

        // Si le nœud n'a pas été visité
        if (!visited[current->ID]) {
            printf("Visited node: %d\n", current->ID);
            visited[current->ID] = 1; // Marquer le nœud comme visité

            // Empiler tous les nœuds adjacents non visités
            arc* arc = current->arc;
            while (arc != NULL) {
                if (!visited[arc->destination->ID]) {
                    push(&stack, arc->destination);
                }
                arc = arc->next;
            }
        }
    }

    // Libération de la mémoire
    free(visited);
}
// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction de parcours en largeur sur le graphe
// Fonction de parcours en largeur sur le graphe en utilisant une file
void breadth_first_search(struct graph* graph, int source) {
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
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        free(visited);
        return;
    }
    q->head = NULL;

    // Enfiler le nœud source
    queue_push(q, graph->head);

    // Parcours en largeur
    while (q->head != NULL) {
        struct node* current = queue_pop(q);

        // Si le nœud n'a pas été visité
        if (!visited[current->ID]) {
            printf("Visited node: %d\n", current->ID);
            visited[current->ID] = 1; // Marquer le nœud comme visité

            // Enfiler tous les nœuds adjacents non visités
            struct arc* arc = current->arc;
            while (arc != NULL) {
                if (!visited[arc->destination->ID]) {
                    queue_push(q, arc->destination);
                }
                arc = arc->next;
            }
        }
    }

    // Libération de la mémoire
    free(visited);
    free(q);
}
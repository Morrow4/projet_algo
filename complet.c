#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// Fonction pour vérifier si un graphe est complet
int is_complete_graph(struct graph* graph) {
    int total_nodes = graph->nb_nodes;

    // Parcourez chaque paire de nœuds distincts
    for (int i = 0; i < total_nodes; i++) {
        for (int j = i + 1; j < total_nodes; j++) {
            struct arc* current_arc = graph->head[i].arc;

            // Vérifiez si le nœud j est dans les arcs du nœud i
            while (current_arc != NULL) {
                if (current_arc->destination->ID == j) {
                    break;
                }
                current_arc = current_arc->next;
            }

            // Si aucun arc n'est trouvé entre i et j, le graphe n'est pas complet
            if (current_arc == NULL) {
                return 0;
            }
        }
    }

    // Si toutes les paires de nœuds sont reliées par une arête, le graphe est complet
    return 1;
}

// Fonction pour récupérer l'ordre d'un graphe complet
int complete_graph_order(struct graph* graph) {
    return graph->nb_nodes;
}

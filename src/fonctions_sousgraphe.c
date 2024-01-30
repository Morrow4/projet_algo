//Fonction sous-graphe G' induit par un sous-ensemble de sommet
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// fonction sous-graphe induit à partir d'un sous-ensemble de sommets
graph* sousgrapheInduit(graph* graph, int* tabIndice, int nb_nodes) {
    if (graph == NULL || tabIndice == NULL || nb_nodes <= 0) {
        return NULL;
    }

    // Créer un nouveau graphe pour le sous-graphe induit
    graph* sousgrapheInduit = create_graph(nb_nodes);

    // Copier les nœuds du sous-ensemble dans le sous-graphe induit
    for (int i = 0; i < nb_nodes; i++) {
        int node_index = tabIndice[i];
        sousgrapheInduit->nodes[i].data = graph->nodes[node_index].data;

        // Copier les arcs du nœud correspondant dans le graphe original
        arc* current_arc = graph->nodes[node_index].arcs;
        while (current_arc != NULL) {
            int dest_node_index = current_arc->destination->data;
            for (int j = 0; j < nb_nodes; j++) {
                if (tabIndice[j] == dest_node_index) {
                    // Ajouter l'arc dans le sous-graphe induit
                    add_arc(&(sousgrapheInduit->nodes[i]), &(sousgrapheInduit->nodes[j]), current_arc->data);
                    break;
                }
            }
            current_arc = current_arc->next;
        }
    }

    return sousgrapheInduit;
}

// fonction pour créer un sous-graphe partiel défini par un sous-ensemble d'arcs à retirer
graph* sousgraphePartiel(graph* graph, int* tabArcs, int nb_arcs) {
    if (graph == NULL || tabArcs == NULL || nb_arcs <= 0) {
        return NULL;
    }
    
    // Créer un nouveau graphe pour le sous-graphe partiel
    graph* sousgraphePartiel = create_graph(graph->nb_nodes);
    
    // Copier les nœuds du graphe d'origine dans le sous-graphe partiel
    for (int i = 0; i < graph->nb_nodes; i++) {
        sousgraphePartiel->nodes[i].data = graph->nodes[i].data;

        // Copier les arcs du nœud correspondant dans le graphe original
        arc* current_arc = graph->nodes[i].arcs;
        while (current_arc != NULL) {
            int current_arc_data = current_arc->data;

            // Vérifier si l'arc doit être exclu du sous-graphe partiel
            int exclude_arc = 0;
            for (int j = 0; j < nb_arcs; j++) {
                if (tabArcs[j] == current_arc_data) {
                    exclude_arc = 1;
                    break;
                }
            }

            if (!exclude_arc) {
                // Ajouter l'arc dans le sous-graphe partiel
                add_arc(&(sousgraphePartiel->nodes[i]), current_arc->destination, current_arc_data);
            }
            current_arc = current_arc->next;
        }
    }

    return sousgraphePartiel;
}
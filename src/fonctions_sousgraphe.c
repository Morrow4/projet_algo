//Fonction sous-graphe G' induit par un sous-ensemble de sommet
// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

// fonction sous-graphe induit à partir d'un sous-ensemble de sommets
graph* sousgraphe1(graph* graph, int* tabIndice, int nb_nodes) {
    if (graph == NULL || tabIndice == NULL || nb_nodes <= 0) {
        return NULL;
    }

    // Créer un nouveau graphe pour le sous-graphe induit
    graph* sousgraphe1 = create_graph(nb_nodes);

    // Copier les nœuds du sous-ensemble dans le sous-graphe induit
    for (int i = 0; i < nb_nodes; i++) {
        int node_index = tabIndice[i];
        sousgraphe1->nodes[i].data = graph->nodes[node_index].data;

        // Copier les arcs du nœud correspondant dans le graphe original
        arc* current_arc = graph->nodes[node_index].arcs;
        while (current_arc != NULL) {
            int dest_node_index = current_arc->destination->data;
            for (int j = 0; j < nb_nodes; j++) {
                if (tabIndice[j] == dest_node_index) {
                    // Ajouter l'arc dans le sous-graphe induit
                    add_arc(&(sousgraphe1->nodes[i]), &(sousgraphe1->nodes[j]), current_arc->data);
                    break;
                }
            }
            current_arc = current_arc->next;
        }
    }

    return sousgraphe1;
}

//sous-graphe G'' defini par un sous-ensemble d'arcs à retirer de A
void sousgraphe2(graph* graph, int start_node_index){

}

















// fonction pour créer un sous-graphe partiel en retirant un ensemble d'arcs
void subgraph_partial(graph* graph, int* arcs_to_remove, int num_arcs_to_remove) {
    if (graph == NULL || arcs_to_remove == NULL || num_arcs_to_remove <= 0) {
        return;
    }

    // Parcourir chaque arc à retirer
    for (int i = 0; i < num_arcs_to_remove; i++) {
        int arc_index = arcs_to_remove[i];

        // Vérifier si l'indice de l'arc est valide
        if (arc_index >= 0 && arc_index < graph->nb_nodes) {
            // Retirer l'arc de la liste des arcs du nœud correspondant
            int source_node_index = arc_index / graph->nb_nodes;
            int dest_node_index = arc_index % graph->nb_nodes;

            node* source_node = &(graph->nodes[source_node_index]);
            arc* current_arc = source_node->arcs;
            arc* previous_arc = NULL;

            // Parcourir la liste des arcs pour trouver celui à retirer
            while (current_arc != NULL && current_arc->destination->data != dest_node_index) {
                previous_arc = current_arc;
                current_arc = current_arc->next;
            }

            // Retirer l'arc de la liste
            if (current_arc != NULL) {
                if (previous_arc != NULL) {
                    previous_arc->next = current_arc->next;
                } else {
                    source_node->arcs = current_arc->next;
                }
                free(current_arc);
            }
        }
    }
}
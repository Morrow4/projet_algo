#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonctions auxiliaires
struct node* get_node_by_index(struct graph* graph, int index);
void add_node_to_graph(struct graph* graph, struct node* new_node);

// Fonction sous-graphe induit à partir d'un sous-ensemble de sommets
struct graph* sousgrapheInduit(struct graph* graph, int* tabIndice, int nb_nodes) {
    if (graph == NULL || tabIndice == NULL || nb_nodes <= 0) {
        return NULL;
    }

    // Créer un nouveau graphe pour le sous-graphe induit
    struct graph* sousgrapheInduit = create_graph(nb_nodes);

    // Copier les nœuds du sous-ensemble dans le sous-graphe induit
    for (int i = 0; i < nb_nodes; i++) {
        int node_index = tabIndice[i];
        struct node* original_node = get_node_by_index(graph, node_index);

        // Créer un nouveau nœud pour le sous-graphe induit
        struct node* new_node = create_node(original_node->data, original_node->ID);
        add_node_to_graph(sousgrapheInduit, new_node);

        // Copier les arcs du nœud correspondant dans le graphe original
        struct arc* current_arc = original_node->arc;
        while (current_arc != NULL) {
            int dest_node_index = current_arc->destination->ID;
            for (int j = 0; j < nb_nodes; j++) {
                if (tabIndice[j] == dest_node_index) {
                    // Trouver le nœud correspondant dans le sous-graphe induit
                    struct node* dest_node = get_node_by_index(sousgrapheInduit, dest_node_index);

                    // Ajouter l'arc dans le sous-graphe induit
                    add_arc(new_node, dest_node, current_arc->data);
                    break;
                }
            }
            current_arc = current_arc->next;
        }
    }

    return sousgrapheInduit;
}

// Fonction pour créer un sous-graphe partiel défini par un sous-ensemble d'arcs à retirer
struct graph* sousgraphePartiel(struct graph* graph, int* tabArcs, int nb_arcs) {
    if (graph == NULL || tabArcs == NULL || nb_arcs <= 0) {
        return NULL;
    }

    // Créer un nouveau graphe pour le sous-graphe partiel
    struct graph* sousgraphePartiel = create_graph(graph->nb_nodes);

    // Copier les nœuds du graphe d'origine dans le sous-graphe partiel
    for (int i = 0; i < graph->nb_nodes; i++) {
        sousgraphePartiel->head[i].data = graph->head[i].data;

        // Copier les arcs du nœud correspondant dans le graphe original
        struct arc* current_arc = graph->head[i].arc;
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
                add_arc(&(sousgraphePartiel->head[i]), current_arc->destination, current_arc_data);
            }
            current_arc = current_arc->next;
        }
    }

    return sousgraphePartiel;
}

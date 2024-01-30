#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction pour récupérer un nœud par son index dans le graphe
struct node* get_node_by_index(struct graph* graph, int index) {
    if (graph == NULL || index < 0 || index >= graph->nb_nodes) {
        return NULL; // Index invalide
    }

    struct node* current_node = graph->head;
    while (current_node != NULL) {
        if (current_node->ID == index) {
            return current_node; // Nœud trouvé
        }
        current_node = current_node->arc ? current_node->arc->destination : NULL;
    }

    return NULL; // Nœud non trouvé
}

// Fonction pour ajouter un nœud au graphe
void add_node_to_graph(struct graph* graph, struct node* new_node) {
    if (graph == NULL || new_node == NULL) {
        return; // Graph ou nœud invalide
    }

    // Si le graphe est vide
    if (graph->head == NULL) {
        graph->head = new_node;
    } else {
        // Parcourir jusqu'à la fin pour ajouter le nouveau nœud
        struct node* current = graph->head;
        while (current->arc != NULL) {
            current = current->arc->destination;
        }
        current->arc = (struct arc*)malloc(sizeof(struct arc));
        if (current->arc == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        current->arc->destination = new_node;
        current->arc->data = 0; // Valeur d'arête par défaut
        current->arc->next = NULL;
    }

    graph->nb_nodes++;
}

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
                    add_arc(sousgrapheInduit, dest_node, current_arc->data);
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
                add_arc(sousgraphePartiel, &(sousgraphePartiel->head[i]), current_arc->destination, current_arc_data);
            }
            current_arc = current_arc->next;
        }
    }

    return sousgraphePartiel;
}

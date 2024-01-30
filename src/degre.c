#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonction de calcul du degré entrant d'un sommet
int in_degree(struct graph* graph, int node_id) {
    // Vérification des arguments
    if (graph == NULL || node_id < 0 || node_id >= graph->nb_nodes) {
        printf("Invalid arguments!\n");
        return -1; // Valeur de retour invalide pour indiquer une erreur
    }

    int in_degree = 0;
    // Parcourir tous les nœuds du graphe
    for (int i = 0; i < graph->nb_nodes; i++) {
        struct node* current_node = &(graph->head[i]);
        // Parcourir toutes les arêtes du nœud actuel
        struct arc* current_arc = current_node->arc;
        while (current_arc != NULL) {
            // Si la destination de l'arête est le nœud cible, incrémenter le degré entrant
            if (current_arc->destination->ID == node_id) {
                in_degree++;
            }
            current_arc = current_arc->next;
        }
    }
    return in_degree;
}


// Fonction pour calculer le degré sortant d'un sommet dans un graphe dirigé
int out_degree(struct graph* graph, int node_id) {
    // Vérification des arguments
    if (graph == NULL || node_id < 0 || node_id >= graph->nb_nodes) {
        printf("Invalid arguments!\n");
        return -1; // Valeur de retour invalide pour indiquer une erreur
    }

    // Accéder au nœud cible dans le graphe
    struct node* target_node = &(graph->head[node_id]);
    int out_degree = 0;

    // Parcourir toutes les arêtes du nœud cible et incrémenter le degré sortant
    struct arc* current_arc = target_node->arc;
    while (current_arc != NULL) {
        out_degree++;
        current_arc = current_arc->next;
    }
    return out_degree;
}


// Fonction pour calculer le degré total d'un sommet dans un graphe dirigé
int total_degree(struct graph* graph, int node_id) {
    // Vérification des arguments
    if (graph == NULL || node_id < 0 || node_id >= graph->nb_nodes) {
        printf("Invalid arguments!\n");
        return -1; // Valeur de retour invalide pour indiquer une erreur
    }

    // Calculer le degré entrant et le degré sortant, puis retourner la somme
    int in = in_degree(graph, node_id);
    int out = out_degree(graph, node_id);
    return (in != -1 && out != -1) ? (in + out) : -1; // Si une des fonctions a retourné une erreur, retourner -1
}

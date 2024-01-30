#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction pour inverser un graphe dirigé
struct graph* reverse_graph(struct graph* graph) {
    // Vérification des arguments
    if (graph == NULL || graph->head == NULL) {
        printf("Invalid graph!\n");
        return NULL;
    }

    // Création d'un nouveau graphe
    struct graph* reversed_graph = create_graph(graph->nb_nodes);
    if (reversed_graph == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Parcourir tous les nœuds du graphe original
    for (int i = 0; i < graph->nb_nodes; i++) {
        struct node* current_node = &(graph->head[i]);

        // Parcourir toutes les arêtes du nœud actuel
        struct arc* current_arc = current_node->arc;
        while (current_arc != NULL) {
            // Ajouter une arête inverse dans le graphe inversé
            add_arc(reversed_graph, current_arc->destination->ID, current_node->ID, current_arc->data);
            current_arc = current_arc->next;
        }
    }

    return reversed_graph;
}

// Fonction auxiliaire pour le parcours en profondeur (DFS)
void dfs_visit(struct graph* graph, int node_id, int* visited) {
    // Marquer le nœud actuel comme visité
    visited[node_id] = 1;

    // Afficher le nœud visité (ou effectuer toute autre opération nécessaire)
    printf("Visited node: %d\n", node_id);

    // Parcourir les nœuds adjacents non visités
    struct arc* current_arc = graph->head[node_id].arc;
    while (current_arc != NULL) {
        int neighbor_id = current_arc->destination->ID;
        if (!visited[neighbor_id]) {
            dfs_visit(graph, neighbor_id, visited);
        }
        current_arc = current_arc->next;
    }
}

// Fonction auxiliaire pour le parcours en profondeur (DFS) avec ordre de fin de visite
void dfs_visit_with_finish_order(struct graph* graph, int node_id, int* visited, struct stack** finish_order) {
    // Marquer le nœud actuel comme visité
    visited[node_id] = 1;

    // Parcourir les nœuds adjacents non visités
    struct arc* current_arc = graph->head[node_id].arc;
    while (current_arc != NULL) {
        int neighbor_id = current_arc->destination->ID;
        if (!visited[neighbor_id]) {
            dfs_visit_with_finish_order(graph, neighbor_id, visited, finish_order);
        }
        current_arc = current_arc->next;
    }

    // Empiler le nœud actuel pour l'ordre de fin de visite
    push(finish_order, &(graph->head[node_id]));
}

// Fonction pour afficher une composante connexe à partir d'un nœud donné (DFS)
void dfs_print_connected_component(struct graph* graph, int node_id, int* visited) {
    // Marquer le nœud actuel comme visité
    visited[node_id] = 1;

    // Afficher le nœud visité (ou effectuer toute autre opération nécessaire)
    printf("%d ", node_id);

    // Parcourir les nœuds adjacents non visités
    struct arc* current_arc = graph->head[node_id].arc;
    while (current_arc != NULL) {
        int neighbor_id = current_arc->destination->ID;
        if (!visited[neighbor_id]) {
            dfs_print_connected_component(graph, neighbor_id, visited);
        }
        current_arc = current_arc->next;
    }
}

// Fonction auxiliaire pour vérifier la connectivité forte en utilisant DFS
int dfs_strongly_connected(struct graph* graph, int node_id) {
    // Initialisation des nœuds visités
    int* visited = (int*)malloc(sizeof(int) * graph->nb_nodes);
    if (visited == NULL) {
        printf("Memory allocation failed!\n");
        return 0; // False, en cas d'échec d'allocation de mémoire
    }
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    // Parcourir tous les nœuds du graphe en utilisant DFS
    dfs_visit(graph, node_id, visited);

    // Vérifier si tous les nœuds ont été visités
    for (int i = 0; i < graph->nb_nodes; i++) {
        if (!visited[i]) {
            free(visited);
            return 0; // False, le graphe n'est pas fortement connexe
        }
    }

    free(visited);
    return 1; // True, le graphe est fortement connexe
}

// Fonction pour vérifier si un graphe orienté est fortement connexe
int is_strongly_connected(struct graph* graph) {
    // Vérification des arguments
    if (graph == NULL || graph->head == NULL) {
        printf("Invalid graph!\n");
        return 0; // False, car le graphe est invalide ou vide
    }

    // Vérifier si le graphe est connexe dans les deux directions
    if (dfs_strongly_connected(graph, 0) && dfs_strongly_connected(reverse_graph(graph), 0)) {
        return 1; // True, le graphe est fortement connexe
    }
    return 0; // False, le graphe n'est pas fortement connexe
}



// Fonction pour récupérer les composantes fortement connexes d'un graphe orienté
void get_strongly_connected_components(struct graph* graph) {
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

    // Pile pour stocker l'ordre de fin de visite des nœuds
    struct stack* finish_order = NULL;

    // Parcourir tous les nœuds du graphe en utilisant DFS et stocker l'ordre de fin de visite
    for (int i = 0; i < graph->nb_nodes; i++) {
        if (!visited[i]) {
            dfs_visit_with_finish_order(graph, i, visited, &finish_order);
        }
    }

    // Graphe transposé
    struct graph* transposed_graph = reverse_graph(graph);

    // Réinitialisation des nœuds visités
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    // Parcourir les nœuds du graphe transposé en utilisant l'ordre de fin de visite inverse
    while (finish_order != NULL) {
        int node_id = pop(&finish_order)->data->ID;
        if (!visited[node_id]) {
            printf("Composante fortement connexe : ");
            dfs_print_connected_component(transposed_graph, node_id, visited);
            printf("\n");
        }
    }

    // Libération de la mémoire
    delete_graph(transposed_graph);
    free(visited);
}

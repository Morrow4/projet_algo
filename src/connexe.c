#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

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

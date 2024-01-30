#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

/*------------CIRCUIT------------*/

// fonction detecter si chemin est un circuit
// Si un chemin (s_0-s_k) contient au moins un arc
// Fonction pour vérifier s'il y a au moins un arc dans le graphe

// Fonction pour détecter si un chemin est un circuit
int is_circuit_in_path(struct graph* graph, int* path, int path_length) {
    // Vérification des arguments
    if (graph == NULL || path == NULL || path_length < 2) {
        printf("Invalid arguments!\n");
        return 0; // False, car le chemin est invalide ou trop court pour former un circuit
    }

    // Vérifier si le premier et le dernier nœud du chemin sont les mêmes
    return (path[0] == path[path_length - 1]);
}

// Fonction pour détecter si un graphe contient un circuit en utilisant DFS
int contains_circuit(struct graph* graph) {
    // Vérification des arguments
    if (graph == NULL || graph->head == NULL) {
        printf("Invalid graph!\n");
        return 0; // False, car le graphe est invalide ou vide
    }

    // Initialisation des nœuds visités
    int* visited = (int*)malloc(sizeof(int) * graph->nb_nodes);
    if (visited == NULL) {
        printf("Memory allocation failed!\n");
        return 0; // False, en cas d'échec d'allocation de mémoire
    }
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    // Parcourir tous les nœuds du graphe et détecter les circuits en utilisant DFS
    for (int i = 0; i < graph->nb_nodes; i++) {
        if (!visited[i] && dfs_contains_circuit(graph, i, visited, -1)) {
            free(visited);
            return 1; // True, car un circuit a été détecté
        }
    }

    // Libération de la mémoire et retourner False, car aucun circuit n'a été trouvé
    free(visited);
    return 0;
}

// Fonction pour trouver un circuit dans un graphe en utilisant DFS
int* find_circuit(struct graph* graph) {
    // Vérification des arguments
    if (graph == NULL || graph->head == NULL) {
        printf("Invalid graph!\n");
        return NULL; // NULL, car le graphe est invalide ou vide
    }

    // Initialisation des nœuds visités
    int* visited = (int*)malloc(sizeof(int) * graph->nb_nodes);
    if (visited == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; // NULL, en cas d'échec d'allocation de mémoire
    }
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    int* circuit = NULL; // Tableau pour stocker les nœuds du circuit trouvé
    for (int i = 0; i < graph->nb_nodes; i++) {
        if (!visited[i] && dfs_find_circuit(graph, i, visited, -1, &circuit)) {
            free(visited);
            return circuit; // Retourner le circuit trouvé
        }
    }

    // Libération de la mémoire et retourner NULL, car aucun circuit n'a été trouvé
    free(visited);
    return NULL;
}
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

// Fonction auxiliaire pour détecter un circuit en utilisant DFS
int dfs_contains_circuit(struct graph* graph, int node_id, int* visited, int parent) {
    visited[node_id] = 1; // Marquer le nœud actuel comme visité

    // Parcourir toutes les arêtes du nœud actuel
    struct arc* current_arc = graph->head[node_id].arc;
    while (current_arc != NULL) {
        int dest_id = current_arc->destination->ID;
        if (!visited[dest_id]) {
            // Si le nœud destination n'a pas été visité, récursion DFS
            if (dfs_contains_circuit(graph, dest_id, visited, node_id)) {
                return 1; // True, un circuit a été trouvé
            }
        } else if (dest_id != parent) {
            return 1; // True, un circuit a été trouvé car un nœud visité est découvert
        }
        current_arc = current_arc->next;
    }
    return 0; // False, pas de circuit trouvé dans cette branche
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

// Fonction auxiliaire pour trouver un circuit en utilisant DFS
int dfs_find_circuit(struct graph* graph, int node_id, int* visited, int parent, int** circuit) {
    visited[node_id] = 1; // Marquer le nœud actuel comme visité

    // Parcourir toutes les arêtes du nœud actuel
    struct arc* current_arc = graph->head[node_id].arc;
    while (current_arc != NULL) {
        int dest_id = current_arc->destination->ID;
        if (!visited[dest_id]) {
            // Si le nœud destination n'a pas été visité, récursion DFS
            if (dfs_find_circuit(graph, dest_id, visited, node_id, circuit)) {
                if (*circuit == NULL) {
                    *circuit = (int*)malloc(sizeof(int) * (graph->nb_nodes + 1));
                    if (*circuit == NULL) {
                        printf("Memory allocation failed!\n");
                        return 0; // Échec d'allocation de mémoire
                    }
                    (*circuit)[0] = dest_id;
                } else if ((*circuit)[0] == dest_id) {
                    (*circuit)[++(*circuit)[0]] = node_id; // Ajouter le nœud au circuit
                    return 1; // True, le circuit est complet
                }
                if (*circuit != NULL) {
                    (*circuit)[++(*circuit)[0]] = node_id; // Ajouter le nœud au circuit
                }
                return 1; // True, un circuit a été trouvé
            }
        } else if (dest_id != parent) {
            // Si un nœud visité est découvert et n'est pas le parent, nous avons trouvé un cycle
            if (*circuit == NULL) {
                *circuit = (int*)malloc(sizeof(int) * (graph->nb_nodes + 1));
                if (*circuit == NULL) {
                    printf("Memory allocation failed!\n");
                    return 0; // Échec d'allocation de mémoire
                }
                (*circuit)[0] = dest_id;
            } else if ((*circuit)[0] == dest_id) {
                (*circuit)[++(*circuit)[0]] = node_id; // Ajouter le nœud au circuit
                return 1; // True, le circuit est complet
            }
            if (*circuit != NULL) {
                (*circuit)[++(*circuit)[0]] = node_id; // Ajouter le nœud au circuit
            }
            return 1; // True, un circuit a été trouvé
        }
        current_arc = current_arc->next;
    }
    return 0; // False, pas de circuit trouvé dans cette branche
}

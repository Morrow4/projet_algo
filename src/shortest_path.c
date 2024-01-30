#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "struct.h"

// Fonction pour initialiser le tableau des distances et des prédécesseurs
void initialize_single_source(struct graph* graph, int source, int* distance, int* predecessor) {
    for (int i = 0; i < graph->nb_nodes; i++) {
        distance[i] = INT_MAX; // Distance infinie initialement
        predecessor[i] = -1;   // Pas de prédécesseur
    }
    distance[source] = 0; // La distance de la source à elle-même est 0
}

// Fonction pour trouver le sommet avec la distance minimale non traitée
int min_distance_vertex(int* distance, int* visited, int nb_nodes) {
    int min_distance = INT_MAX;
    int min_vertex = -1;

    for (int i = 0; i < nb_nodes; i++) {
        if (!visited[i] && distance[i] < min_distance) {
            min_distance = distance[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}

// Fonction pour afficher le chemin le plus court entre la source et la destination
void print_shortest_path(int source, int destination, int* predecessor) {
    if (destination == source) {
        printf("%d ", source);
    } else if (predecessor[destination] == -1) {
        printf("Il n'y a pas de chemin de %d à %d\n", source, destination);
    } else {
        print_shortest_path(source, predecessor[destination], predecessor);
        printf("%d ", destination);
    }
}

// Fonction pour trouver le plus court chemin entre deux sommets
void shortest_path(struct graph* graph, int source, int destination) {
    int* distance = (int*)malloc(graph->nb_nodes * sizeof(int));
    int* predecessor = (int*)malloc(graph->nb_nodes * sizeof(int));
    int* visited = (int*)malloc(graph->nb_nodes * sizeof(int));

    // Initialisation
    initialize_single_source(graph, source, distance, predecessor);
    for (int i = 0; i < graph->nb_nodes; i++) {
        visited[i] = 0;
    }

    // Boucle principale
    for (int count = 0; count < graph->nb_nodes - 1; count++) {
        int u = min_distance_vertex(distance, visited, graph->nb_nodes);
        visited[u] = 1;

        struct arc* current_arc = graph->head[u].arc;
        while (current_arc != NULL) {
            int v = current_arc->destination->ID;
            int weight = current_arc->data;
            if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
            }
            current_arc = current_arc->next;
        }
    }

    // Affichage du chemin le plus court
    printf("Le plus court chemin entre %d et %d est : ", source, destination);
    print_shortest_path(source, destination, predecessor);

    free(distance);
    free(predecessor);
    free(visited);
}

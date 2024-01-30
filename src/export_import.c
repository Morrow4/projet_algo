#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction pour exporter un graphe vers un fichier
void export_graph(struct graph* graph, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing!\n");
        return;
    }

    // Écrire le nombre total de nœuds dans le graphe
    fprintf(file, "%d\n", graph->nb_nodes);

    // Parcourir tous les nœuds du graphe
    for (int i = 0; i < graph->nb_nodes; i++) {
        struct node* current_node = &(graph->head[i]);
        // Écrire les données du nœud
        fprintf(file, "%d %d\n", current_node->ID, current_node->data);
        // Parcourir toutes les arêtes du nœud et les écrire dans le fichier
        struct arc* current_arc = current_node->arc;
        while (current_arc != NULL) {
            fprintf(file, " -> %d %d", current_arc->destination->ID, current_arc->data);
            current_arc = current_arc->next;
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Fonction pour importer un graphe à partir d'un fichier
struct graph* import_graph(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading!\n");
        return NULL;
    }

    // Lire le nombre total de nœuds dans le graphe
    int nb_nodes;
    fscanf(file, "%d", &nb_nodes);

    // Créer un nouveau graphe avec le nombre total de nœuds
    struct graph* graph = create_graph(nb_nodes);

    // Parcourir le fichier pour récupérer les données des nœuds et des arêtes
    int node_id, node_data, arc_dest, arc_data;
    while (fscanf(file, "%d %d", &node_id, &node_data) == 2) {
        // Lire les données du nœud
        struct node* current_node = &(graph->head[node_id]);
        current_node->ID = node_id;
        current_node->data = node_data;

        // Lire les données des arêtes connectées au nœud
        while (fscanf(file, " -> %d %d", &arc_dest, &arc_data) == 2) {
            // Créer une nouvelle arête et la connecter au nœud actuel
            struct arc* new_arc = (struct arc*)malloc(sizeof(struct arc));
            if (new_arc == NULL) {
                printf("Memory allocation failed!\n");
                return NULL;
            }
            new_arc->destination = &(graph->head[arc_dest]);
            new_arc->data = arc_data;
            new_arc->next = current_node->arc;
            current_node->arc = new_arc;
        }
    }

    fclose(file);
    return graph;
}
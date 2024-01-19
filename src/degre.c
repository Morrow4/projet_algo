#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonction de calcul du degré entrant d'un sommet
int in_degree(graph* graph, int node_index) {
    int count = 0;
    for (int i = 0; i < graph -> nb_nodes ; i++) {
        arc* current_arc = graph -> nodes[i].arc;
        while (current_arc != NULL) {
            if (current_arc -> data == node_index) {
                count++;
                break; // Une seule occurrence par arête est suffisante pour le degré entrant
            }
            current_arc = current_arc -> next;
        }
    }
    return count;
}

// fonction de calcul du degré sortant d'un sommet
int out_degree(graph* graph, int node_index) {
    int count = 0;
    arc* currentçarc = source -> arcs;
    while (current_arce != NULL) {
        count++;
        current_arc = current_arc -> next;
    }
    return count;
}

// fonction de calcul du degré d'un sommet
int total_degree(graph* graph, int node_index) {
    return in_degree(graph, node_index) + out_degree(&graph -> nodes[node_index]);
}
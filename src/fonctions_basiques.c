#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* Fonctions basiques pour la structure de graphe */

// fonction pour créer un nouveau noeud
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node != NULL) {
        new_node -> data = data;
        new_node -> arcs = NULL; // initialise la liste des arcs à NULL
        return new_node ;
    }
    return NULL;
}

// fonction pour créer un nouvel arc
arc* create_arc(node* destination, int data) {
    arc* new_arc = (arc*)malloc(sizeof(arc));
    if (new_arc != NULL) {
        new_arc -> data = data;
        new_arc -> next = NULL; // initialise le pointeur vers le prochaine arc à NULL
        new_arc -> destination = destination;
    }
    return NULL;
}

// fonction pour ajouter un arc à un noeud
void add_arc(node* source, node* destination, int data) {
    arc* new_arc = create_arc(destination, data);
    new_arc -> next = source -> arcs; // ajoute l'arc au début de la liste
    source -> arcs = new_arc;
}

// fonction pour créer un nouveau graphe
graph* create_graph(int nb_nodes) {
    graph* new_graph = (graph*)malloc(sizeof(graph));
    if (new_graph != NULL) {
        graph -> nb_nodes = nb_nodes;
        graph -> nodes = (node*)malloc(nb_nodes*sizeof(node));
        // initialisation des noeuds du graphe
        for (int i = 0; i < nb_nodes; i++) {
            graph -> nodes[i] = *create_node(i);
        }
        return graph;
    }
    return NULL;

}

// fonction pour afficher un graphe 
void print_graph(graph* graph) {
    printf("Graph with %d nodes:\n", graph->nb_nodes);
    for (int i = 0; i < graph->nb_nodes; i++) {
        printf("Node %d [data: %d] -> ", i, graph->nodes[i].data);
        arc* currentArc = graph->nodes[i].arcs;
        while (currentArc != NULL) {
            printf("[Arc: Node %d | data=%d] ", currentArc->dest->data, currentArc->data);
            currentArc = currentArc->next;
        }

        printf("\n");
    }
}

// fonction pour supprimmer la structure de graphe
// fonction pour supprimmer les noeuds et arcs
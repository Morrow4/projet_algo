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
        return new_arc;
    }
    return NULL;
}

// fonction pour ajouter un arc à un noeud
arc* add_arc(node* source, node* destination, int data) {
    arc* new_arc = create_arc(destination, data);
    new_arc -> next = source -> arcs; // ajoute l'arc au début de la liste
    source -> arcs = new_arc;
    return new_arc;
}

// fonction pour créer un nouveau graphe
graph* create_graph(int nb_nodes) {
    graph* new_graph = (graph*)malloc(sizeof(graph));
    if (new_graph != NULL) {
        new_graph -> nb_nodes = nb_nodes;
        new_graph -> nodes = (node*)malloc(nb_nodes*sizeof(node));
        // initialisation des noeuds du graphe
        for (int i = 0; i < nb_nodes; i++) {
            new_graph -> nodes[i] = *create_node(i);
        }
        return new_graph;
    }
    return NULL;
}

// fonction pour afficher un graphe 
void print_graph(graph* graph) {
    printf("Graph with %d nodes:\n", graph -> nb_nodes);
    for (int i = 0; i < graph -> nb_nodes; i++) {
        printf("Node %d [data: %d] -> ", i, graph -> nodes[i].data);
        arc* current_arc = graph -> nodes[i].arcs;
        while (current_arc != NULL) {
            printf("[Arc: Node %d | data=%d] ", current_arc -> destination -> data, current_arc -> data);
            current_arc = current_arc -> next;
        }
        printf("\n");
    }
}

// fonction pour supprimmer le graphe
void delete_graph(graph* graph) {
    for (int i = 0 ; i graph -> nb_nodes; i++) {
        arc* current_arc = graph -> nodes[i].arcs; // libérer la mémoire de chaque arc connecté à un noeud
        while (current_arc != NULL) {
            arc* next_arc = current_arc -> next;
            free(current_arc);
            current_arc = next_arc;
        }
    }
    free(graph -> nodes); // libérer la mémoire des noeuds du graphe
    free(graph); // libérer la mémoire du graphe
}

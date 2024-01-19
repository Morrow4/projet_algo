#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* Fonctions basiques pour la structure de graphe */

// fonction pour créer un nouveau noeud
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = data;
    new_node -> arcs = NULL; // initialise la liste des arcs à NULL
    return new_node ;
}

// fonction pour créer un nouvel arc
arc* create_arc(node* destination, int data) {
}

// fonction pour ajouter un arc à un noeud
void add_arc(node* source, node* destination, int data) {
    arc* new_arc = create_arc(destination, data);
    new_arc -> next = source -> arcs; // ajoute l'arc au début de la liste
    source -> arcs = new_arc;
}

// fonction pour créer un nouveau graphe
graph* create_graph(int nb_nodes) {
    graph* new_graph = (graph*)malloc(sizeof(graph))
}

// fonction pour supprimmer la structure de graphe
// fonction pour supprimmer les noeuds et arcs
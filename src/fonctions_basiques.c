#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* Fonctions basiques pour la structure de graphe */

// fonction pour créer un nouveau noeud
node* create_node(int data) {
}

// fonction pour créer un nouvel arc
arc* create_arc(node* destination, int data) {
    arc* new_arc = (arc*)malloc(sizeof(arc));
    if (new_arc != NULL){
        new_arc->data=date;
        new_arc->next=NULL;
        new_arc->dest=destination;
    }
}

// fonction pour ajouter un arc à un noeud
void add_arc(node* source, node* destination, int data) {
}

// fonction pour créer un nouveau graphe
graph* create_graph(int nb_nodes) {
}

// fonction pour supprimmer la structure de graphe
// fonction pour supprimmer les noeuds et arcs
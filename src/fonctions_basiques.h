/* Déclarations des fonctions */

#IFNDEF FONCTIONS_BASIQUES_H
#DEFINE FONCTIONS_BASIQUES_H

#include <stdio.h>
#include <stdlib.h>

node* create_node(int data);
arc* create_arc(node* destination, int data);
void add_arc(node* source, node* destination, int data);
graphe* create_graph(int nb_nodes);

#ENDIF FONCTIONS_BASIQUES_H
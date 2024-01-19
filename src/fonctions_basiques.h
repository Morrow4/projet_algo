
/* Déclarations des fonctions */

#IFNDEF FONCTIONS_BASIQUES_H
#DEFINE FONCTIONS_BASIQUES_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

node* create_node(int data);
arc* create_arc(node* destination, int data);
void add_arc(node* source, node* destination, int data);
graph* create_graph(int nb_nodes);
void print_graph(graph* graph);
void delete_graph(graph* graph)

#ENDIF FONCTIONS_BASIQUES_H
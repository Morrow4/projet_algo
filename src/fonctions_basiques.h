
/* Déclarations des fonctions */

#IFNDEF FONCTIONS_BASIQUES_H
#DEFINE FONCTIONS_BASIQUES_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonctions basiques
node* create_node(int data);
arc* create_arc(node* destination, int data);
arc* add_arc(node* source, node* destination, int data);
graph* create_graph(int nb_nodes);
void print_graph(graph* graph);
void delete_graph(graph* graph)

// parcours

// degrée
int in_degree(graph* graph, int node_index);
int out_degree(graph* graph, int node_index);
int total_degree(graph* graph, int node_index);

#ENDIF FONCTIONS_BASIQUES_H
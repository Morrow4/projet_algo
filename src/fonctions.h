/* Déclarations des fonctions */

#ifndef FONCTIONS_BASIQUES_H
#define FONCTIONS_BASIQUES_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonctions basiques
node* create_node(int data, int ID);
arc* create_arc(node* destination, int data);
arc* add_arc(node* source, node* destination, int data);
graph* add_node(int data, graph* graph, int iD);
graph* create_graph(int nb_nodes);
void print_graph(graph* graph);
void delete_graph(graph* graph);

// parcours
void depth_first_search(graph* graph, int source)
void bfs(graph* graph, int start_node_index);

// degrée
int in_degree(graph* graph, int node_index);
int out_degree(graph* graph, int node_index);
int total_degree(graph* graph, int node_index);

//sousgraphe
graph* sousgraphe1(graph* graph, int* tabIndice, int nb_nodes);
graph* sousgraphe2(graph* graph, int* tabArcs, int nb_arcs);

// import export
char* export_graph(char* filename, graph* graph);
graph* import_graph(char* filename);

#endif FONCTIONS_BASIQUES_H
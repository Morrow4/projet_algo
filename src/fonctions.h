/* Déclarations des fonctions */

#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonctions basiques
struct node* create_node(int data, int ID);
struct arc* create_arc(node* destination, int data);
struct arc* add_arc(node* source, node* destination, int data);
struct graph* add_node(int data, graph* graph, int iD);
struct graph* create_graph(int nb_nodes);
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
struct graph* sousgrapheInduit(graph* graph, int* tabIndice, int nb_nodes);
struct graph* sousgraphePartiel(graph* graph, int* tabArcs, int nb_arcs);

// import export
char* export_graph(char* filename, graph* graph);
struct graph* import_graph(char* filename);

#endif FONCTIONS_H
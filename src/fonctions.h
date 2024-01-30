/* Déclarations des fonctions */

#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// fonctions basiques
struct node* create_node(int data, int ID);
struct arc* create_arc(struct node* destination, int data);
struct arc* add_arc(struct node* source,struct node* destination, int data);
struct graph* add_node(int data, struct graph* graph, int ID);
struct graph* create_graph(int nb_nodes);
void print_graph(struct graph* graph);
void delete_graph(struct graph* graph);
void push(struct stack** top,struct node* node);
struct node* pop(struct stack** top);

// parcours
void depth_first_search(struct graph* graph, int source);
void breadth_first_search(graph* graph, int source);

// degrée
int in_degree(struct graph* graph, int node_index);
int out_degree(struct graph* graph, int node_index);
int total_degree(struct graph* graph, int node_index);

//sousgraphe
struct graph* sousgrapheInduit(struct graph* graph, int* tabIndice, int nb_nodes);
struct graph* sousgraphePartiel(struct graph* graph, int* tabArcs, int nb_arcs);

// import export
char* export_graph(char* filename,struct graph* graph);
struct graph* import_graph(char* filename);

#endif //FONCTIONS_H
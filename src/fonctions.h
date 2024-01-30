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
void queue_push(struct queue* q, struct node* node);
struct node* queue_pop(struct queue* q);

// parcours
void depth_first_search(struct graph* graph, int source);
void breadth_first_search(graph* graph, int source);

// degrée
int in_degree(struct graph* graph, int node_id);
int out_degree(struct graph* graph, int node_id);
int total_degree(struct graph* graph, int node_id);

//sous_graphe
struct graph* sousgrapheInduit(struct graph* graph, int* tabIndice, int nb_nodes);
struct graph* sousgraphePartiel(struct graph* graph, int* tabArcs, int nb_arcs);

// import export
void export_graph(struct graph* graph, const char* filename);
struct graph* import_graph(const char* filename);

// circuit
int is_circuit_in_path(struct graph* graph, int* path, int path_length);
int contains_circuit(struct graph* graph);
int dfs_contains_circuit(struct graph* graph, int node_id, int* visited, int parent);
int* find_circuit(struct graph* graph);
int dfs_find_circuit(struct graph* graph, int node_id, int* visited, int parent, int** circuit);

// connexe
int is_strongly_connected(struct graph* graph);
void get_strongly_connected_components(struct graph* graph);

#endif
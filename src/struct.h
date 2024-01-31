/* Déclarations des structures */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

struct node; //redondant mais necessaire

// Structure de graphe
typedef struct graph {
    int nb_nodes; // nombre total de noeuds
    struct node* head; // tete du graphique
} graph;

// Structure d'arrête de graphe
typedef struct arc {
    struct node* destination; // pointeur vers le noeud de destination
    int data; // valeur de l'arrête
    struct arc* next; // pointeur vers la prochaine arête dans la liste
} arc;

// Structure de noeud de graphe
typedef struct node {
    int ID; // node ID
    int data; // valeur du noeud
    struct arc* arc; // liste des arêtes connectés à ce noeud
} node;

// Structure de file
typedef struct queue_element
{
    struct queue_element* p;
    struct queue_element* n;
    struct node* node;
} queue_element;

typedef struct queue 
{
    struct queue_element* head;
} queue;

// Structure de pile pour stocker les nœuds à visiter
typedef struct stack {
    struct node* data;
    struct stack* n;
} stack;

#endif
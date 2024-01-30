/* Déclarations des structures */

#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Structure de graphe
typedef struct graph {
    int nb_nodes; // nombre total de noeuds
    node *nodes; // liste qui pointe vers les noeuds du graphe
};

// Structure d'arrête de graphe
typedef struct arc {
    struct node* destination; // pointeur vers le noeud de destination
    int data; // valeur de l'arrête
    struct arc *next; // pointeur vers la prochaine arête dans la liste
};

// Structure de noeud de graphe
typedef struct node {
    int ID; // node ID
    int data; // valeur du noeud
    arc *arc; // liste des arêtes connectés à ce noeud
};

// Structure de file
typedef struct queue_element
{
    struct queue_element *p;
    struct queue_element *n;
    node* node;
};

typedef struct queue 
{
    queue_element* head;
};

// Structure de pile pour stocker les nœuds à visiter
typedef struct stack {
    node* data;
    struct stack* n;
};

#endif STRUCT_H
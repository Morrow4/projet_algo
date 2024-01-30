/* Déclarations des structures */

#IFNDEF STRUCT_H
#DEFINE STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Structure de graphe
typedef struct graph {
    int nb_nodes; // nombre total de noeuds
    node *nodes; // liste qui pointe vers les noeuds du graphe
};

// Structure d'arrête de graphe
typedef struct arc {
    node* destination; // pointeur vers le noeud de destination
    int data; // valeur de l'arrête
    struct arc *next; // pointeur vers la prochaine arête dans la liste
};

// Structure de noeud de graphe
typedef struct node {
    int ID; // node ID
    int data; // valeur du noeud
    struct arcs *arc; // liste des arêtes connectés à ce noeud
};

// Structure de file
typedef struct queue_element
{
    struct queue_element *p;
    struct queue_element *n;
    struct node* node;
};

typedef struct queue 
{
    struct queue_element* tete;
};

#ENDIF STRUCT_H
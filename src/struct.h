/* Déclarations des structures */

#IFNDEF STRUCT_H
#DEFINE STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Structure de graphe
typedef struct graph {
    int nb_nodes; // nombre total de noeuds
    node *nodes; // liste qui pointe vers les noeuds du graphe
} graph;

// Structure d'arrête de graphe
typedef struct arc {
    node* destination; // pointeur vers le noeud de destination
    int data; // valeur de l'arrête
    struct arc *next; // pointeur vers la prochaine arête dans la liste
} arc;

// Structure de noeud de graphe
typedef struct node {
    int ID; // node ID
    int data; // valeur du noeud
    struct arcs *arc; // liste des arêtes connectés à ce noeud
} node;

// Structure element
typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

// Structure file
typedef struct File {
    Element* tete;
    Element* queue;
} File;

#ENDIF STRUCT_H
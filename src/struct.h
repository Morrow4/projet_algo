/* Déclarations des structures */

#IFNDEF STRUCT_H
#DEFINE STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Structure de graphe
typedef struct graphe {
    int nb_nodes; // nombre total de noeuds
    node *nodes // liste qui pointe vers les noeuds du graphe
} graphe;

// Structure d'arrête de graphe
typedef struct edge {
    int data; // valeur de l'arrête
    struct edge *next // pointeur vers la prochaine arête dans la liste
} edge;

// Structure de noeud de graphe
typedef struct node {
    int data; // valeur du noeud
    struct edge *edges; // liste des arêtes connectés à ce noeud
} node;

#ENDIF STRUCT_H
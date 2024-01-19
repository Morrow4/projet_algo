/* Déclarations des structures */

#IFNDEF STRUCT_H
#DEFINE STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Structure de graphe
typedef struct graphe {
    int nb_nodes; // nombre total de noeuds
    node *nodes; // liste qui pointe vers les noeuds du graphe
} graphe;

// Structure d'arrête de graphe
typedef struct arc {
    int data; // valeur de l'arrête
    struct arc *next; // pointeur vers la prochaine arête dans la liste
} arc;

// Structure de noeud de graphe
typedef struct node {
    int data; // valeur du noeud
    struct arc *arc; // liste des arêtes connectés à ce noeud
} node;

#ENDIF STRUCT_H
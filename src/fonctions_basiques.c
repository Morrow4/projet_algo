#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* Fonctions basiques pour la structure de graphe */

// fonction pour créer un nouveau noeud
struct node* create_node(int data, int ID) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node -> data = data;
        new_node -> arc = NULL; // initialise la liste
        new_node -> ID = ID; // initialise l'ID du noeud
        return new_node ;
    }
    return NULL;
}

// fonction pour créer un nouvel arc
struct arc* create_arc(struct node* destination, int data) {
    struct arc* new_arc = (struct arc*)malloc(sizeof(struct arc));
    if (new_arc != NULL) {
        new_arc -> data = data;
        new_arc -> next = NULL; // initialise le pointeur vers le prochaine arc
        new_arc -> destination = destination;
        return new_arc;
    }
    return NULL;
}

// fonction pour ajouter un arc à un noeud
struct arc* add_arc(struct node* source,struct node* destination, int data) {
    struct arc* new_arc = create_arc(destination, data);
    new_arc -> next = source -> arc; // ajoute l'arc au début de la liste
    source -> arc = new_arc;
    return new_arc;
}

// fonction pour ajouter un noeud à un graphique
struct graph* add_node(int data,struct graph* graph, int ID) {
    struct node* new_node = create_node(data, ID);
    int i = 0;
    while(graph -> *nodes[i] != NULL) {
    i++;
    } 
    graph -> *nodes[i] = new_node;
    new_node -> ID = i;
    return graph;

}

// fonction pour créer un nouveau graphe
struct graph* create_graph(int nb_nodes) {
    struct graph* new_graph = (struct graph*)malloc(sizeof(graph));
    if (new_graph != NULL) {
        new_graph -> nb_nodes = nb_nodes;
        new_graph -> nodes = (struct node*)malloc(nb_nodes*sizeof(node));
        // initialisation des noeuds du graphe
        for (int i = 0; i < nb_nodes; i++) {
            new_graph -> nodes[i] = *create_node(i);
        }
        return new_graph;
    }
    return NULL;
}

// fonction pour afficher un graphe 
void print_graph(struct graph* graph) {
    printf("Graph with %d nodes:\n", graph -> nb_nodes);
    for (int i = 0; i < graph -> nb_nodes; i++) {
        printf("Node %d [data: %d] -> ", i, graph -> nodes[i].data);
        arc* current_arc = graph -> nodes[i].arcs;
        while (current_arc != NULL) {
            printf("[Arc: Node %d | data=%d] ", current_arc -> destination -> data, current_arc -> data);
            current_arc = current_arc -> next;
        }
        printf("\n");
    }
}

// fonction pour supprimmer le graphe
void delete_graph(struct graph* graph) {
    for (int i = 0 ; i graph -> nb_nodes; i++) {
        arc* current_arc = graph -> nodes[i].arcs; // libérer la mémoire de chaque arc connecté à un noeud
        while (current_arc != NULL) {
            arc* next_arc = current_arc -> next;
            free(current_arc);
            current_arc = next_arc;
        }
    }
    free(graph -> nodes); // libérer la mémoire des noeuds du graphe
    free(graph); // libérer la mémoire du graphe
}

// fonction pour empiler un noeud
void push(struct stack** top,struct node* node) {
    struct stack* new_node = (struct stack*)malloc(sizeof(stack));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = node;
    new_node->next = *top;
    *top = new_node;
}

// Fonction pour dépiler un nœud
struct node* pop(struct stack** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    node* node = (*top)->data;
    stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;
}
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

// Fonction pour ajouter un noeud à un graphe
struct graph* add_node(int data, struct graph* graph_ptr, int ID) {
    // Créer un nouveau nœud
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->ID = ID;
    new_node->arc = NULL;

    // Si le graphe est vide
    if (graph_ptr->head == NULL) {
        graph_ptr->head = new_node;
    } else {
        // Parcourir jusqu'à la fin pour ajouter le nouveau nœud
        struct node* current = graph_ptr->head;
        while (current->arc != NULL) {
            current = current->arc->destination;
        }
        current->arc = (struct arc*)malloc(sizeof(struct arc));
        if (current->arc == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        current->arc->destination = new_node;
        current->arc->data = 0; // Valeur d'arête par défaut
        current->arc->next = NULL;
    }
    graph_ptr->nb_nodes++;
    return graph_ptr;
}



// Fonction pour créer un nouveau graphe avec un nombre spécifié de nœuds
struct graph* create_graph(int nb_nodes) {
    // Allouer de la mémoire pour la structure de graphe
    struct graph* new_graph = (struct graph*)malloc(sizeof(struct graph));
    if (new_graph == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialiser le nombre de nœuds
    new_graph->nb_nodes = nb_nodes;
    new_graph->head = NULL; // Initialiser la tête du graphe à NULL

    return new_graph;
}

// Fonction pour afficher un graphe
void print_graph(struct graph* graph) {
    printf("Graph with %d nodes:\n", graph->nb_nodes);
    struct node* current_node = graph->head;
    while (current_node != NULL) {
        printf("Node %d [data: %d] -> ", current_node->ID, current_node->data);
        struct arc* current_arc = current_node->arc;
        while (current_arc != NULL) {
            printf("[Arc: Node %d | data=%d] ", current_arc->destination->data, current_arc->data);
            current_arc = current_arc->next;
        }
        printf("\n");
        current_node = current_node->arc ? current_node->arc->destination : NULL;
    }
}

// Fonction pour supprimer un graphe et libérer la mémoire associée
void delete_graph(struct graph* graph) {
    // Vérifier si le graphe existe
    if (graph == NULL) {
        printf("Invalid graph!\n");
        return;
    }

    // Libérer la mémoire des arcs et des nœuds du graphe
    struct node* current_node = graph->head;
    while (current_node != NULL) {
        struct arc* current_arc = current_node->arc;
        while (current_arc != NULL) {
            struct arc* temp_arc = current_arc;
            current_arc = current_arc->next;
            free(temp_arc);
        }
        struct node* temp_node = current_node;
        current_node = current_node->arc ? current_node->arc->destination : NULL;
        free(temp_node);
    }

    // Libérer la mémoire du graphe lui-même
    free(graph);
}

// fonction pour empiler un noeud
void push(struct stack** top,struct node* node) {
    struct stack* new_node = (struct stack*)malloc(sizeof(struct stack));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = node;
    new_node->n = *top;
    *top = new_node;
}

// Fonction pour dépiler un nœud
struct node* pop(struct stack** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    node* node = (*top)->data;
    struct stack* temp = *top;
    *top = (*top)->n;
    free(temp);
    return node;
}
// Ajoutez ceci en haut de votre fonction_BFS.c
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

// Fonction de parcours en largeur (BFS)
void bfs(graph* graph, int start_node_index) {
    if (graph == NULL || start_node_index < 0 || start_node_index >= graph -> nb_nodes) {
        return;
    }
    File* q = create_queue();
    int* visited = (int*)calloc(graph -> nb_nodes, sizeof(int));
    if (q == NULL || visited == NULL) {
        return;
    }
    enqueue(q, &(graph -> nodes[start_node_index]));
    visited[start_node_index] = 1;
    while (!is_queue_empty(q)) {
        node* current_node = dequeue(q);
        printf("Visited Node: %d\n", current_node -> data);

        arc* current_arc = current_node -> arcs;
        while (current_arc != NULL) {
            if (!visited[current_arc->destination -> data]) {
                enqueue(q, current_arc -> destination);
                visited[current_arc -> destination -> data] = 1;
            }
            current_arc = current_arc->next;
        }
    }
    free(visited);
    free(q);
}

/* Breadth-First Search (BFS) */

struct node* bfs_arbre(struct graph* arbre, int val) {
    struct queue q;
    q.tete = NULL;
    struct node* node;
    if (arbre -> racine == NULL) {
        return NULL ;
    } 
    if (arbre -> racine -> donnee == val) {
        printf("%d a été trouvé\n", val);
        return arbre -> racine ;
    }
    queue_push(&q, arbre -> racine); // Ajoute la racine à la file
    while (!is_empty(&q)) { // Tant que la file n'est pas vide
        tmp_noeud = queue_pop(&q); // Retire un sommet et ajouter les autres sommets connectés
        if (tmp_noeud -> l != NULL) {  // Test à gauche si le noeud existe
            if (tmp_noeud -> l -> donnee == val) { // Test à gauche si la valeur contenu dans le noeud est celle recherché
                printf("%d a été trouvé\n", val);
                return tmp_noeud -> l, tmp_noeud ;
            }
            queue_push(&q, tmp_noeud -> l); // Sinon ajoute le noeud à gauche à la file
        }
        if (tmp_noeud -> r != NULL) { // Test à droite si le noeud existe
            if (tmp_noeud -> r -> donnee == val) { // Test à droite si la valeur contenu dans le noeud est celle recherché
                printf("%d a été trouvé\n", val);
                return tmp_noeud -> r, tmp_noeud ;
            }
            queue_push(&q, tmp_noeud -> r); // Sinon ajoute le noeud à droite à la file
        }
    }
}

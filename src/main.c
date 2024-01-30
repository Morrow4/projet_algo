#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

int main() {

    // Création d'un graphe
    struct graph* my_graph = create_graph(6);

    // Ajout des nœuds au graphe
    for (int i = 0; i < 6; i++) {
        my_graph = add_node(0, my_graph, i);
    }
    /*
    // Ajout des arcs au graphe
    add_arc(my_graph, 0, 1, 4); // De A à B avec poids 4
    add_arc(my_graph, 0, 2, 3); // De A à C avec poids 3
    add_arc(my_graph, 1, 2, 1); // De B à C avec poids 1
    add_arc(my_graph, 1, 3, 2); // De B à D avec poids 2
    add_arc(my_graph, 2, 3, 4); // De C à D avec poids 4
    add_arc(my_graph, 2, 4, 3); // De C à E avec poids 3
    add_arc(my_graph, 3, 4, 2); // De D à E avec poids 2
    add_arc(my_graph, 3, 5, 1); // De D à F avec poids 1
    add_arc(my_graph, 4, 5, 5); // De E à F avec poids 5

    // Affichage du graphe
    print_graph(my_graph);
    breadth_first_search(my_graph, 5);
    depth_first_search(my_graph, 2);

    // Vérification si le graphe est connexe
    if (is_strongly_connected(my_graph)) {
        printf("Le graphe est fortement connexe.\n");
    } else {
        printf("Le graphe n'est pas fortement connexe.\n");
    }

    // Vérification si le graphe est complet
    if (is_complete_graph(my_graph)) {
        printf("Le graphe est complet.\n");
    } else {
        printf("Le graphe n'est pas complet.\n");
    }

    // Calcul de l'ordre du graphe
    int order = complete_graph_order(my_graph);
    printf("L'ordre du graphe est : %d\n", order);
    
    // Affichage du graphe induit et partiel
    //struct graph* my_graph_2 = sousgrapheInduit(my_graph, tabIndice, nb_nodes);
    //struct graph* my_graph_3 = sousgraphePartiel(my_graph, tabArcs, nb_arcs);
    //print_graph(my_graph_2);
    //print_graph(my_graph_3);

    // Recherche du plus court chemin entre deux sommets
    int source = 0;
    int destination = 5;
    shortest_path(my_graph, source, destination);
    */
    // Libération de la mémoire allouée pour le graphe
    delete_graph(my_graph);
    return 0;
}
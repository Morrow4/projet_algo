#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

int main() {

    //printf("Appuyez sur une touche pour continuer : debug 1...\n");
    //getchar();
    // Création d'un graphe
    struct graph* my_graph = create_graph(6);
    //printf("Appuyez sur une touche pour continuer : debug 2...\n");
    //getchar();
    // Ajout des nœuds au graphe
    my_graph = add_node(0, my_graph, 0);

    my_graph = add_node(1, my_graph, 1);
    //printf("Appuyez sur une touche pour continuer : debug 3...\n");
    //getchar();
    // Affichage du graphe (ajout de cette ligne)
    print_graph(my_graph);
    //printf("Appuyez sur une touche pour continuer : debug 4...\n");
    //getchar();

    // Libération de la mémoire allouée pour le graphe
    delete_graph(my_graph);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions.h"

//------------CIRCUIT

//fonction detecter si chemin est un circuit
//Si un chemin (s_0-s_k) contient au moins un arc
// Fonction pour vérifier s'il y a au moins un arc dans le graphe
int detect_arc(graph* graph) {
    if (graph == NULL) {
        return 0;
    }

    for (int i = 0; i < graph->nb_nodes; i++) {
        if (graph->nodes[i].arcs != NULL) {
            // Il y a au moins un arc dans le graphe
            return 1;
        }
    }

    // Aucun arc trouvé
    return 0;
}

int detect_circuit(graph* graph){
    if (detect_arc(graph)==1){
        printf("Le graphe est un circuit\n");
    }else{
        printf("Le graphe n'est pas un circuit\n")
    }
    return 0;
}
//Fonction qui retourne le circuit
int retour_circuit(graphe* graph){
    for (int i = 0; i < graph->nb_nodes; i++) {
        if (graph->nodes[i].arcs != NULL) {

            return 1;
        }
    }
}

//Parcours du graphe
int parcours_graphe{
    //Penser à marquer le chemin parcouru
    //Penser à marquer le chemin renvoyant un circuit
    return -1;
}

//retour du circuit


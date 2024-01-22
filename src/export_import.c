#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

void export_graph(char* filename, graph* graph) {
    FILE* input_file;
    char* buff;
    input_file = fopen(filename, "w");
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    for (int i = 0; i < graph -> nb_nodes; i++) {
        int node = graph -> nodes[i].data;
        sprintf(buff,"%d", node);
        fprintf(FILE* input_file, "buff\n");
        arc* current_arc = graph -> nodes[i].arcs;
        while (current_arc != NULL) {
            int arc = current_arc -> data;
            sprintf(buff,"%d", arc);
            fprintf(FILE* input_file, "buff\n");
            current_arc = current_arc -> next;
        }
        printf("\n"); // saut de ligne à la fin de chaque noeud
    }
    fclose(input_file);
}

void import_graph(char* filename) {
    FILE* input_file;
    input_file = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    fscanf()
    fclose(input_file);
}
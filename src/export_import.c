#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

char* export_graph(char* filename, graph* graph) {
    FILE *input_file;
    char *buff;
    int node, ID;
    input_file = fopen(filename, "w");
    
    int count = graph -> nb_nodes;
    sprintf(buff,"%d", count);
    fprintf(FILE* input_file, "count\n");

    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    for (int i = 0; i < graph -> nb_nodes; i++) {

        node = graph -> nodes[i].data;
        sprintf(buff, "%d", node);
        fprintf(FILE* input_file, "buff");

        ID = graph -> nodes[i].ID;
        sprintf(buff,"%d", ID);
        fprintf(FILE* input_file, "buff\n");
        arc *current_arc = graph -> nodes[i].arcs;

        while (current_arc != NULL) {

            ID = current_arc -> destination -> ID;
            sprintf(buff, "%d", ID);
            fprintf(FILE* input_file, "buff");

            node = current_arc -> destination -> data;
            sprintf(buff, "%d", node);
            fprintf(FILE* input_file, "buff");

            int arc = current_arc -> data;
            sprintf(buff,"%d", arc);
            fprintf(FILE* input_file, "buff\n");

            current_arc = current_arc -> next;
        }
        printf("\n"); // saut de ligne à la fin de chaque noeud
    }
    fclose(input_file);
    return filename;
}

graph* import_graph(char* filename) {
    FILE *input_file;
    input_file = fopen(filename, "r");
    char *buff;
    fget(buff, sizeof(buff), input_file);
    int count = stdlol(buff, NULL, 10);
    create_graph(count);
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    while (fgets(buff, sizeof(buff), input_file) != NULL) {
        add_node(buff);
        if (node_destination == NULL) {
            create_node(data_destination);
        }
        add_arc(source, destination, data);
    }
    fclose(input_file);
    return graph
}
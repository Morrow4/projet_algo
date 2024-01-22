#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "fonctions_basiques.h"

void export_graph(char* filename, char* path {
    FILE* input_file;
    input_file = fopen(filename, "w+");
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    // code 
    fclose(input_file);
}

void import_graph(char* filename) {
    FILE* input_file;
    input_file = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }
    // code 
    fclose(input_file);
}
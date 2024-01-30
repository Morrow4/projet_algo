# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC = degre.c export_import.c fonctions_basiques.c fonctions_BFS.c fonctions_DFS.c fonctions_sousgraphe.c main.c fonctions_partie2.c

# Object files
OBJECTS = degre.o export_import.o fonctions_basiques.o fonctions_BFS.o fonctions_DFS.o fonctions_sousgraphe.o main.o fonctions_partie2.c

# Target name
TARGET = projet_algo.exe

# Default target file
all: build

# Build target file
build: $(SRC)
	$(CC) $(SRC) -o $(TARGET) -lm

# Launch target file
launch:
	./$(TARGET)

# Clean object files
clean:
	rm -f $(OBJECTS)
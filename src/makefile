# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC = struct.c dfs.c bfs.c degre.c export_import.c circuit.c connexe.c complet.c shortest_path.c sous_graphe.c main.c

# Object files
OBJ = $(SRC:.c=.o)

# Target name
TARGET = projet_algo.exe

# Default target file
all: build

# Build target file
build: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) -lm

# Launch target file
launch:
	./$(TARGET)

# Clean object files
clean:
	rm -f $(OBJ) $(TARGET)

# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC =  fonctions_basiques.c main.c fonctions_DFS.c
# fonctions_BFS.c  degre.c fonctions_sousgraphe.c export_import.c

# Object files
OBJECTS = fonctions_basiques.o main.o fonctions_DFS.o

# fonctions_BFS.o degre.o fonctions_sousgraphe.o export_import.o 

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
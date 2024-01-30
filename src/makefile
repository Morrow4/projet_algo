# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC =  part_1.c main.c dfs.o bfs.c degre.c
# fonctions_sousgraphe.c export_import.c

# Object files
OBJECTS = part_2.o main.o dfs.o bfs.o degre.o
# fonctions_sousgraphe.o export_import.o 

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
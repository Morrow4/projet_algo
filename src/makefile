# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC =  struct.c main.c dfs.o bfs.c degre.c export_import.c circuit.c
# fonctions_sousgraphe.c 

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
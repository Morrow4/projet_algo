# Makefile

# Compiler and flags
CC = gcc

# Source files
SRC = fonctions_basiques.c main.c

# Object files
OBJECTS = fonctions_basiques.o main.o

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
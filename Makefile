# ===== Simple Makefile for your game =====

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = game

# Source files
SRC = main.cpp Cards.cpp CardList.cpp TripleDraft.cpp

# Default target
all: $(TARGET)

# Link all source files into executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -f $(TARGET)

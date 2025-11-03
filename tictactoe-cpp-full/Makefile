# Simple Makefile for Tic-Tac-Toe
CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/tictactoe.cpp
TARGET = tictactoe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

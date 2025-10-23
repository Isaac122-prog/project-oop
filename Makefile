CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = game

SRC = main.cpp Cards.cpp CardList.cpp TripleDraft.cpp DeckGrader.cpp Deck.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

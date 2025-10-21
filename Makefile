#// complie the game 
game: main.cpp Cards.cpp CardList.cpp TripleDraft.cpp
	g++ -std=c++11 main.cpp Cards.cpp CardList.cpp TripleDraft.cpp -o Game

# to run the complied game
run: all
	g++ -std=c++11 main.cpp Cards.cpp CardList.cpp TripleDraft.cpp -o game
	./game

# remove the game from explorer
clean:
	rm -f *.o game


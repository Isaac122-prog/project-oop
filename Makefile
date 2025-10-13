#// complie the game 
game: AppControler.cpp Buff_spell.cpp Building.cpp Cards.cpp Control_spell.cpp Damage_spell.cpp Deck.cpp Defensive_Building.cpp Melee_troop.cpp Ranged_troop.cpp Resource_building.cpp Spawner_building.cpp Spell.cpp Support_troop.cpp Tank_troop.cpp Troop.cpp
	g++ -std=c++11 AppControler.cpp Buff_spell.cpp Building.cpp Cards.cpp Control_spell.cpp Damage_spell.cpp Deck.cpp Defensive_Building.cpp Melee_troop.cpp Ranged_troop.cpp Resource_building.cpp Spawner_building.cpp Spell.cpp Support_troop.cpp Tank_troop.cpp Troop.cpp -o Game

# to run the complied game
run: all
	g++ -std=c++11 AppControler.cpp Buff_spell.cpp Building.cpp Cards.cpp Control_spell.cpp Damage_spell.cpp Deck.cpp Defensive_Building.cpp Melee_troop.cpp Ranged_troop.cpp Resource_building.cpp Spawner_building.cpp Spell.cpp Support_troop.cpp Tank_troop.cpp Troop.cpp -o Game
	./Game

# remove the game from explorer
clean:
	rm -f *.o Game

#upload to github
git:
	git pull
	git add .
	git commit -m "commit"
	git push
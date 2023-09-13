math: game.o GameCharacter.o
	c++ game.o GameCharacter.o -o game
Gamecharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp
game.o: game.cpp
	c++ -c game.cpp
clean:
	rm *.o game

math: game.o GameCharacter.o
	c++ game.o GameCharacter. -o math
Gamecharacter.o: GameCahracter.cpp
	c++ -c GameCharacter.cpp
game.o: game.cpp
	c++ -c game.cpp
clean:
	rm *.o math

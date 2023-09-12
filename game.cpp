/***************************************************************/
// Name : Christelle
//Course : CS 355
//Assigment 5
//date : sept 12 2023
//program description:This program manages characters with various attributes such as name,
//               max health, current health, attack points, and defense points.
//                 The program allows characters to engage in battles, take damage,
//                 and checks their living status.
//                 It also provides functionality to save and load character data
//                to and from text files.

//*****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "GameCharacter.h"
using namespace std;

int main(){
	GameCharacter character1("Christa", 100, 100, 45, 45, true);
	GameCharacter character2("Ange", 100, 100, 45, 45, true);
	GameCharacter char1("Name",0,0,0,0, true);
	GameCharacter char2("Name", 0,0,0,0, true)
	int damage;
		
		//simulate fight between all the fisrt 2 characters
	// Open a file stream for witting
	character1.saveToFile("Character1.txt");
	character1.saveToFile("Character1.txt");
	
	//simulate battle
	cout << "First attack of "<<character1.getName() << " to "<< character2.getName() << endl;
	damage = character1.attack(character2);
	cout << character1.getName() <<" dealt " << damage << " points of damage to " <<character2.getName()<< endl<< endl;
	
	cout << "Second attack of "<<character1.getName() << " to "<< character2.getName()<< endl;
	damage = character1.attack(character2);
	cout << character1.getName()  <<" dealt " << damage << " points of damage to " <<character2.getName()<< endl<< endl;  
	
	cout << "First attack of "<<character2.getName() << " to "<< character1.getName() << endl;
	damage = character2.attack(character1);
	cout << character2.getName() <<" dealt " << damage << " points of damage to " <<character1.getName()<< endl <<endl;
	 
	cout << "Third attack of "<<character1.getName() << " to "<< character2.getName() << endl;
	damage = character1.attack(character2);
	cout << character1.getName() <<" dealt " << damage << " points of damage to " <<character2.getName()<< endl <<endl;  
	     
	
	char1.loadFromFile("Character1.txt"); 
	char2.loadFromFile("Character2.txt"); 
	
	
	//character1.displayDateTimeOfLastSave();
	//character2.displayDateTimeOfLastSave(); 
		
	return 0;
}

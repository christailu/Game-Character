/***************************************************************/
// Name : Christelle
//Course : CS 355
//Assigment 5 

//date: Sept 7 2023
//program description:This program manages characters with various attributes such as name,
//               max health, current health, attack points, and defense points.
//                 The program allows characters to engage in battles, take damage,
//                 and checks their living status.
//                 It also provides functionality to save and load character data
//                to and from text files.

//*****************************************************************/
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>
#include <ctime>
using namespace std;

class GameCharacter{
	private: 
		string name;
		int maxHealth =0;
		int healthPoints =0;
		int attackPoints = 0;
		int defensePoints =0;
		bool isAlive;
	
	public:
		GameCharacter (string, int, int, int, int, bool);
		
		//getter method for each private member of the class
		string getName() const;
		int getMaxHealth() const;
		int getHealthPoints() const;
		int getAttackPoints() const;
		int getDefensePoints() const;
		bool getIsAlive() const;
		
		bool takeDamage(int);
		int attack(GameCharacter&);
		bool saveTofile(string&) const;
		void loadFromFile(string& );
		
		void displayTimeSinceLastSave();
		
		//overloaded functions
	    // Overloaded + operator to perform addition between  attributes
	    friend GameCharacter operator+(const GameCharacter&, const GameCharacter& ) ;

	
	    // Overloaded > operator to compare
	    friend bool operator>(const GameCharacter& , const GameCharacter& );
	
	    // Overloaded < operator to compare based on health
	    friend bool operator<(const GameCharacter& , const GameCharacter& );
	
	    // Overloaded << operator to display character's details
	    friend ostream& operator<<(ostream& , const GameCharacter&);		
			
		
		
				
		
};

#endif

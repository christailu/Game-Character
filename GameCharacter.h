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
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class GameCharacter{
	friend ostream& operator<<(ostream& os, const GameCharacter&  character);
	
	private:
		string name;
		int maxHealth;
		int healthPoints;
		int attackPoints;
		int defensePoints;
		bool isAlive;
		
		time_t lastSaveTime;
		
	public:	
	   //constructor
		GameCharacter(string Name, int maxH, int HealthP, int AttackP, int DefenseP, bool isAlv);
		
		//getters method
		string getName() const;
		int getMaxHealth() const;
		int getHealthPoints() const;
		int getAttackPoints() const;
		int getDefensePoints() const;
		bool getIsAlive() const;
		
		bool takeDamage(int damage);
		int attack(GameCharacter& target);
		
		//oveloaded operator

		GameCharacter operator+(const GameCharacter& character);
		bool operator<(const GameCharacter& character);
		bool operator>(const GameCharacter& character);
		
		void saveToFile(const string& filename) const;
		void loadFromFile(const string& filename);
		void displayDateTimeOfLastSave()const;
		
		
		
		
};

#endif

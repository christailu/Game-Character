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
#include <ctime>
#include "GameCharacter.h"
using namespace std;



	   //constructor
GameCharacter::GameCharacter(string Name, int maxH, int HealthP, int AttackP, int DefenseP, bool isAlv)
{
	name = Name;
	maxHealth = maxH;
	healthPoints = maxH;
	attackPoints = AttackP;
	defensePoints = DefenseP; 
	isAlv = true;
	
	lastSaveTime = time(0);
}
		
		//getters method
string GameCharacter::getName() const{
	return name;
}
int GameCharacter::getMaxHealth() const{
	return maxHealth;
}
int GameCharacter::getHealthPoints() const{
	return healthPoints;
	
}
int GameCharacter::getAttackPoints() const{
    return attackPoints;
    
}
int GameCharacter::getDefensePoints() const{
	return defensePoints;
	
}
bool GameCharacter::getIsAlive() const{
	return isAlive;
}
		
bool GameCharacter::takeDamage(int damage){
	healthPoints -= damage;
	
	if (healthPoints < 0){
		healthPoints =0;
		return isAlive = false;
	}
	return isAlive = true;
}

int GameCharacter::attack(GameCharacter& target){
	int actualDamage;
	
	actualDamage = attackPoints - target.defensePoints;
	if (actualDamage < 0){
		actualDamage = 0;
	}
	
	target.takeDamage(actualDamage);
	
	return actualDamage;
}

GameCharacter GameCharacter::operator+(const GameCharacter& character){
	GameCharacter temp("temp",0,0,0,0,true);
	temp.maxHealth = maxHealth + character.maxHealth;
	temp.healthPoints =( healthPoints + character.healthPoints)/2;
	temp.attackPoints = (attackPoints + character.attackPoints)/2;
	temp.defensePoints = (defensePoints + character.defensePoints)/2;
        
	
	
        return temp;
}

bool GameCharacter::operator<(const GameCharacter& character){
	return healthPoints < character.healthPoints;
	
}
bool GameCharacter::operator>(const GameCharacter& character){
	return healthPoints > character.healthPoints;
}

ostream& operator<<(ostream& os, const GameCharacter& character){
    os << "Character Name: " << character.name << endl;
    os << "Max Health: " << character.maxHealth << endl;
    os << "Health Points: " << character.healthPoints << endl;
    os << "Attack Points: " << character.attackPoints << endl;
    os << "Defense Points: " << character.defensePoints << endl;
    
    if (character.isAlive){
        os << "The Character is Alive ^_^" << endl;
    } 
	else {
        os << "The Character is DEAD ToT :(" << endl;
    }
    
    return os;	
}

void GameCharacter::saveToFile(const string& filename) const{
	ofstream outFile(filename);
	if (outFile.fail()){
		cout << "Cannot open the file." <<endl;
		exit(1);
	}
	
	outFile << "Charactere Name: " << name << endl;
	outFile <<  "Max Health: " << maxHealth <<endl;
	outFile << "Attack Points: " << attackPoints;
	outFile << "Defense Points: " << defensePoints << endl;
	
	if (isAlive){
		outFile << "The Character is Alive ^_^ !!"<<endl;
		
	}
	else{
		outFile << "The Charcater is DEAD ToT" << endl;
	}
}

void GameCharacter::loadFromFile(const string& filename){
	ifstream inFile(filename);
	if (inFile.fail()){
		cout << "Fail to open file for reading." << endl;
		exit(1);
	}
	while (getline(inFile, name)){
		inFile >> name;
		inFile >> maxHealth;
		inFile >> attackPoints;
		inFile >> defensePoints;
	}

}

// Method to display the date and time when the character was last saved.
void GameCharacter::displayDateTimeOfLastSave() const {
    // Use std::ctime to convert the saved time to a readable format
    cout << "Character " << name << " was last saved on: " << ctime(&lastSaveTime) << endl;
}

/***************************************************************/
// Name : Christelle
//Course : CS 355
//Assigment 5
//date : sept 7 2023
//program description:This program manages characters with various attributes such as name,
//               max health, current health, attack points, and defense points.
//                 The program allows characters to engage in battles, take damage,
//                 and checks their living status.
//                 It also provides functionality to save and load character data
//                to and from text files.

//*****************************************************************/
#include <iostream>
#include <fstream>
#include <ctime>
#include "GameCharacter.h"

using namespace std;


// Function name: GameCharacter (Constructor)
// Function description: Constructs a GameCharacter object with given attributes.
// Return Value: N/A (Constructor)
GameCharacter::GameCharacter (string Name, int MaxH, int AttackP,int HealthP, int DefenseP, bool IsAlv)
{
	name = Name;
	maxHealth =  MaxH;
	healthPoints = MaxH;
	attackPoints = AttackP;
	defensePoints = DefenseP;
	isAlive = true;
	time(lastSaveTime);
}
		
		//getter method for each private member of the class
		
// Function name: getName
// Function description: Retrieves the name of the GameCharacter.
// Return Value: string (Name of the character)		
string GameCharacter::getName() const
{
	return name;
}

// Function name: getMaxHealth
// Function description: Retrieves the maximum health of the GameCharacter.
// Return Value: int (Maximum health)
int GameCharacter::getMaxHealth() const
{
	return maxHealth;
}

// Function name: getHealthPoints
// Function description: Retrieves the current health points of the GameCharacter.
// Return Value: int (Current health points)
int GameCharacter::getHealthPoints() const
{
	return healthPoints;
}

// Function name: getAttackPoints
// Function description: Retrieves the attack points of the GameCharacter.
// Return Value: int (Attack points)
int GameCharacter::getAttackPoints() const
{
	return attackPoints;
}

// Function name: getDefensePoints
// Function description: Retrieves the defense points of the GameCharacter.
// Return Value: int (Defense points)
int GameCharacter::getDefensePoints() const
{
	return defensePoints;
}

// Function name: getIsAlive
// Function description: Checks if the GameCharacter is alive.
// Return Value: bool 
bool GameCharacter::getIsAlive() const
{
	return isAlive;
}

// Function name: takeDamage
// Function description: Subtracts the incoming damage from the character's health points.
// Return Value: bool 
bool GameCharacter::takeDamage(int damage)
{
	//
	if(healthPoints <= 0)
	{
		isAlive = false;
	}
	
	else //
	{
		healthPoints -= damage;
		if (healthPoints <= 0)
		{
			isAlive = false;
			//to make sure the healthpointss never go bellow 0
			healthPoints = 0;
		}
	}
	
	return isAlive;
}

// Function name: attack
// Function description: Makes the character attack a target character.
// Return Value: int
int GameCharacter::attack( GameCharacter& target)
{
	int actualDamage;
	actualDamage = attackPoints - target.defensePoints;
	
	//if damage is negative it will ajust it to o, avoiding nagative number
	if(actualDamage < 0)
	{
		actualDamage =0;
	}
	
	// apply the damage to the target
	target.takeDamage(actualDamage);
	
	return actualDamage;
}

// Function name: saveTofile
// Function description: Saves character attributes to a file.
// Return Value: bool 
bool GameCharacter::saveTofile(string& filename) const
{
	ofstream outFile(filename);
	
	if(outFile.fail())
	{
		cout << "Cannot find the file to open" <<endl;
		return false;
		
	}
    outFile << "Character Name: " << name << endl;
    outFile << "Max Health: " << maxHealth << endl;
    outFile << "Health Points: " << healthPoints << endl;
    outFile << "Attack Points: " << attackPoints << endl;
    outFile << "Defense Points: " << defensePoints << endl;
    
    if (isAlive)
    {
    	outFile << "The Character is Alive ^_^ "  << endl;
	}
	else
	{
		outFile << "The Character is DEAD ToT : "  << endl;
	}
	
	outFile.close();
	cout << "Details saved in " << filename <<endl;
	return true;
	
}

// Function name: loadFromFile
// Function description: Loads character attributes from a file.
// Return Value: void
void GameCharacter::loadFromFile(string& filename )
{
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            // Get the attribute name and value
            string attribute;
			string value;
            int pos = line.find(" ");
            if (pos == -1) {
                // The line does not contain a space, so the attribute is the entire line
                attribute = line;
                value = "";
            } else {
                // The line contains a space, so the attribute is the part of the line before the space
                attribute = line.substr(0, pos);
                // The value is the part of the line after the space
                value = line.substr(pos + 1);
            }

            if (attribute == "Character") {
                name = value;
            } else if (attribute == "Max") {
                maxHealth = stoi(value);
            } else if (attribute == "Health") {
                healthPoints = stoi(value);
            } else if (attribute == "Attack") {
                attackPoints = stoi(value);
            } else if (attribute == "Defense") {
                defensePoints = stoi(value);
            } else if (attribute == "Is") {
                isAlive = (value == "Alive");
            }
        }
        inFile.close();
        cout << "Character details loaded from " << filename << endl;
        //return true;
    } else {
        cout << "Cannot find the file to open" << endl;
        //return false;
    }	
}


//
void GameCharater::displayDateTimeOfLastSave()
{
	cout << "Last Saved ON  "<< ctime(&lastSaveTime);	
}

// Function name: operator+
// Function description: Adds two GameCharacter objects and returns a new GameCharacter.
// Return Value: GameCharacter
GameCharacter operator+(const GameCharacter& char1, const GameCharacter& char2)
{
    // Combine attributes and calculate averages
    string newName = char1.name + "_" + char2.name;
    int newMaxHealth = char1.maxHealth + char2.maxHealth;
    int newAttackPoints = (char1.attackPoints + char2.attackPoints) / 2;
    int newHealthPoints = (char1.healthPoints + char2.healthPoints) / 2;
    int newDefensePoints = (char1.defensePoints + char2.defensePoints) / 2;
    bool newIsAlive = char1.isAlive && char2.isAlive;

    return GameCharacter(newName, newMaxHealth, newAttackPoints, newHealthPoints, newDefensePoints, newIsAlive);
}

// Function name: operator>
// Function description: Compares the health of two GameCharacters.
// Return Value: bool
bool operator>(const GameCharacter& char1, const GameCharacter& char2)
{
    return char1.healthPoints > char2.healthPoints;
}

// Function name: operator<
// Function description: Compares the health of two GameCharacters.
// Return Value: bool 
bool operator<(const GameCharacter& char1, const GameCharacter& char2)
{
    return char1.healthPoints < char2.healthPoints;
}

// Function name: operator<<
// Function description: Outputs the attributes of a GameCharacter to an ostream.
// Return Value: ostream& 
ostream& operator<<(ostream& os, const GameCharacter& character)
{
    os << "Character Name: " << character.name << endl;
    os << "Max Health: " << character.maxHealth << endl;
    os << "Health Points: " << character.healthPoints << endl;
    os << "Attack Points: " << character.attackPoints << endl;
    os << "Defense Points: " << character.defensePoints << endl;
    
    if (character.isAlive) {
        os << "The Character is Alive ^_^" << endl;
    } else {
        os << "The Character is DEAD ToT :(" << endl;
    }
    
    return os;
}

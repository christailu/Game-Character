/***************************************************************/
// Name : Christelle
//Course : CS 355
//Assigment 3
//date : sept 1 2023
//program description:This program manages characters with various attributes such as name,
//               max health, current health, attack points, and defense points.
//                 The program allows characters to engage in battles, take damage,
//                 and checks their living status.
//                 It also provides functionality to save and load character data
//                to and from text files.

//*****************************************************************/
#include <iostream>
#include <fstream>
#include "GameCharacter.h"

using namespace std;

int main() {
    // Create instances of GameCharacter
    GameCharacter character1("Christa", 100, 30, 20, 10, true);
    GameCharacter character2("Ange", 60, 25, 15, 15, true);
    GameCharacter character3("Maria", 80, 35, 25, 5, true);

    // Open a file stream for writing
    ofstream outFile("GameCharacters.txt");

    // start of the game
    cout << "Start of the Game:" << endl;
    cout << character1 << endl;
    cout << character2 << endl;
    cout << character3 << endl;

    // Save characters to file
    if (outFile.is_open()) {
        outFile << "Start of the Game:" << endl;
        outFile << character1 << endl;
        outFile << character2 << endl;
        outFile << character3 << endl;
    }

    // Simulate battles
    cout << "First attack of "<<character1.get_name() << " to "<< character2.get_name()  << endl;
    int damage = character1.attack(character2);
    cout << character1.get_name() <<" dealt " << damage << " points of damage to " <<character2.get_name()  << endl <<endl;
    cout << "Second attack of "<<character1.get_name() << " to "<< character2.get_name() << endl;
    damage = character1.attack(character2);
    cout << character1.get_name()  <<" dealt " << damage << " points of damage to " <<character2.get_name()   << endl <<endl;   

    cout << "First attack of "<<character2.get_name() << " to "<< character1.get_name() << endl;
    damage = character2.attack(character1);
    cout << character2.get_name() <<" dealt " << damage << " points of damage to " <<character1.get_name()  << endl <<endl;
    cout << "First attack of "<<character3.get_name() << " to "<< character2.get_name() << endl;
    damage = character3.attack(character2);
    cout << character3.get_name() <<" dealt " << damage << " points of damage to " <<character2.get_name()  << endl <<endl;  
    
    cout << "First attack of "<<character1.get_name() << " to "<< character3.get_name() << endl;
    damage = character1.attack(character3);
    cout << character1.get_name() <<" dealt " << damage << " points of damage to " <<character3.get_name()  << endl <<endl;
    cout << "Second attack of "<<character1 << " to "<< character3 << endl;
    damage = character1.attack(character3);
    cout << character1.get_name() <<" dealt " << damage << " points of damage to " <<character3.get_name()  << endl <<endl;      

    // Save battle simulation to file
    if (outFile.is_open()) {
        outFile << "Simulating battle between all three charaters" << endl;
        outFile  << character1.get_name() <<" dealt " << damage << " points of damage to " <<character2.get_name()  << endl;
        outFile  << character1.get_name() <<" dealt " << damage << " points of damage to " <<character3.get_name()  << endl;
        outFile  << character2.get_name() <<" dealt " << damage << " points of damage to " <<character1.get_name()  << endl;
        outFile  << character3.get_name() <<" dealt " << damage << " points of damage to " <<character3.get_name()  << endl;
    }

    cout << "Character details after the attack:" << endl;
    cout << character1 << endl;
    cout << character2 << endl;
    cout << character3 << endl;    

    // Save post-battle character details to file
    if (outFile.is_open()) {
        outFile << "Character details after the attack:" << endl;
        outFile << character1 << endl;
        outFile << character2 << endl;
        outFile << character3 << endl;
    }

    // Compare character health
    cout << "Comparing character health:" << endl;
    if (character1 > character2) {
        cout << "Christa has more health than Ange." << endl;
    } else {
        cout << "Ange has more health than Christa." << endl;
    }

    // Save health comparison to file
    if (outFile.is_open()) {
        outFile << "Comparing character health:" << endl;
        if (character1 > character2) {
            outFile << "Christa has more health than Ange." << endl;
        } else {
            outFile << "Ange has more health than Christa." << endl;
        }
    }

    // Close the file 
    if (outFile.is_open()) {
        outFile.close();
    }

    return 0;
}


#include "Pet.h"

/*
	is Digits checks is a sting is numeric.
	string str - is a sting to be checked.
*/
bool isDigits(string str);
/*
	readFile reads in the csv, and poplates a vector of Pet objects.
	ifStream inFile - The csv to be read.
	ofStream errFile - The file errors are output to.
	vector allPets the vector of Pets that will be filled.
*/
void readFile(ifstream& inFile, ofstream& errFile, vector<Pet>& allPets);
/*
	displayMenu displays the menu and gets user input.
*/
char displayMenu();
/*
	listAdoption finds all animals adpoted in a specific month and year.
	ofStream outFile - the file ouput is sent to.
	vector allPets - the unmodified vector of pets.
*/
void listAdoption(ofstream& outFile, vector<Pet>& allPets);/*
	findPet finds a pet using a user specified name
	ofStream outFile - the file ouput is sent to.
	vector allPets - the unmodified vector of pets.
*/
void findPet(ofstream& outFile, vector<Pet>& allPets);
/*
	listAdoption finds all adoptable animals and displays them.
	ofStream outFile - the file ouput is sent to.
	vector allPets - the unmodified vector of pets.
*/
void petsAvailable(ofstream& outFile, vector<Pet>& allPets);
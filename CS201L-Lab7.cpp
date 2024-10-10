// CS201L-Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name - David Boatright 
// 10/9/24
#include "Functions.h"

int main()
{
    ifstream inFile;
    ofstream outFile, errFile;

    inFile.open("PPShelter.csv");
    outFile.open("report.txt");
    errFile.open("error.txt");

    if (!inFile.good() || !outFile.good() || !errFile.good()) {
        cout << "Error opening files\n";
        return -1;
    }

    vector<Pet> allPets;
    try {
        readFile(inFile, errFile, allPets);
    }
    catch (invalid_argument &err) {
        cout << err.what();
    }

    char choice;
    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);
    choice = displayMenu();
    while (choice != 'q') {
        switch (choice) {
        case 'a':
            petsAvailable(outFile, allPets);
            break;
        case 'b':
            findPet(outFile, allPets);
            break;
        case 'c':
            listAdoption(outFile, allPets);
            break;
        }
        choice = displayMenu();
    }
    inFile.close();
    outFile.close();
    errFile.close();
}
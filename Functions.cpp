#include "Functions.h"

bool isDigits(string str) {
    return (str.find_first_not_of("0123456789") == string::npos);
}

char displayMenu() {
    char choice = 'q';
    cout << "Choices avaiable: " << endl;
    cout << "a) Adoptable pets" << endl;
    cout << "b) Find a pet" << endl;
    cout << "c) Adopted pets" << endl;
    cout << "q) Quit" << endl;
    cin >> choice;
    return choice;
}


void readFile(ifstream& inFile, ofstream &err, vector<Pet>& allPets) {
    string line, item, year, month;
    stringstream inss, datess;
    Pet tempPet;
    int birthYr, inYr,inMon, count = 0;
    double oAge;
    getline(inFile, line);
    while (getline(inFile, line)) {
        inss.str(line);
        getline(inss, item, ',');
        tempPet.setID(item);
        //Name
        getline(inss, item, ',');
        if (item.length()) {
            tempPet.setName(item);
        }
        else {
            tempPet.setName(tempPet.getID());
        }
        //Datetime
        getline(inss, item, ',');
        datess.clear();
        datess.str(item);
        getline(datess, year, ' ');
        month = year.substr(0, year.find_first_of('/'));
        year = year.substr(year.length() - 4);
        try {
            inYr = stoi(year);
            inMon = stoi(month);
        }
        catch (invalid_argument &err) {
            count++;
            continue;
        }
        tempPet.setIntake(inMon, inYr);
        //MonthYear
        getline(inss, item, ',');
        //DOB
        getline(inss, item, ',');
        year = item.substr(item.length() - 4);
        try {
            birthYr = stoi(year);
        }
        catch (invalid_argument& err) {
            count++;
            continue;
        }
        tempPet.setAgeIntake(inYr - birthYr);
        tempPet.setAgeCurrent(2024 - birthYr);
        //outcome type
        getline(inss, item, ',');
        tempPet.setOutcome(item);
        //outcome subtype
        getline(inss, item, ',');
        //animal type
        getline(inss, item, ',');
        tempPet.setType(item);
        //Sex
        getline(inss, item, ',');
        tempPet.setSex(item);
        //age on outcome
        getline(inss, item, ',');
        datess.clear();
        datess.str(item);
        getline(datess, year, ' ');
        try {
            oAge = stoi(year);
        }
        catch (invalid_argument) {
            count++;
            continue;
        }
        datess >> year;
        if (year == "years" || year == "year") {
            tempPet.setAgeOutcome(oAge);
        }
        else if (year == "months" || year == "month") {
            tempPet.setAgeOutcome(oAge / 12);
        }
        else {
            tempPet.setAgeOutcome(oAge / 52);
        }
        //breed
        getline(inss, item, ',');
        tempPet.setBreed(item);
        //color
        //getline(inss, item, ',');
        
        count++;
        allPets.push_back(tempPet);
    }
}

// Bubble sort function
// adpated from https://www.geeksforgeeks.org/bubble-sort-algorithm/
/*
    bubbleSort is a simple bubble sort algorithm.
    vector vec - is the vecotr to be sorted.
    char option - chooses what to sort by: t = type, i = age at intake.
*/
void bubbleSort(vector<Pet>& vec, char option) {
    bool swapped;
    if (option == 't') {
        for (int i = 0; i < vec.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < vec.size() - i - 1; j++) {
                if (vec.at(j).getType() > vec.at(j + 1).getType()) {
                    swap(vec.at(j), vec.at(j + 1));
                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }
    }
    else if (option == 'i') {
        for (int i = 0; i < vec.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < vec.size() - i - 1; j++) {
                if (vec.at(j).getAgeIntake() > vec.at(j + 1).getAgeIntake()) {
                    swap(vec.at(j), vec.at(j + 1));
                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }
    }
}

 
void petsAvailable(ofstream& outFile, vector<Pet>& allPets) { 
    vector<Pet> availPets;
    // Finds all specified animals.
    for (int i = 0; i < allPets.size(); ++i) {
        if (allPets.at(i).getOutcome() == "") {
            availPets.push_back(allPets.at(i));
        }
    }
    bubbleSort(availPets, 't');
    // All the folowing is just formatted output.
    outFile << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    cout << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    for (int i = 0; i < availPets.size(); ++i) {
        outFile << setw(25) << availPets.at(i).getName() << setw(10) << availPets.at(i).getType() << setw(35) << availPets.at(i).getBreed()
            << setw(20) << availPets.at(i).getSex() << setw(10) << availPets.at(i).getAgeIntake() << setw(10)
            << availPets.at(i).getAgeCurrent() << endl;
        cout << setw(25) << availPets.at(i).getName() << setw(10) << availPets.at(i).getType() << setw(35) << availPets.at(i).getBreed() 
             << setw(20) << availPets.at(i).getSex() << setw(10) << availPets.at(i).getAgeIntake() << setw(10) 
             << availPets.at(i).getAgeCurrent() << endl;
    }
    outFile << "\n\n" << endl;
}


void listAdoption(ofstream& outFile, vector<Pet>& allPets) {
    int mon, yr;
    vector<Pet> adoptPets;
    cout << "Month / Year: " << endl;
    cin >> mon >> yr;
    // Finds all specified animals.
    for (int i = 0; i < allPets.size(); ++i) {
        if (allPets.at(i).getOutcome() == "Adoption" && allPets.at(i).getInMon() == mon && allPets.at(i).getInYr() == yr) {
            adoptPets.push_back(allPets.at(i));
        }
    }
    // Bubble sort algo crashes with an empty vector so must check if empty, the if also allows reporting an unsuccsessful search to user. 
    if (adoptPets.size()) {
        bubbleSort(adoptPets, 't');
    }
    else {
        cout << "No animals found." << endl;
        return;
    }
    // All the folowing is just formatted output.
    outFile << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    cout << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    for (int i = 0; i < adoptPets.size(); ++i) {
        outFile << setw(25) << adoptPets.at(i).getName() << setw(10) << adoptPets.at(i).getType() << setw(35) << adoptPets.at(i).getBreed()
            << setw(20) << adoptPets.at(i).getSex() << setw(10) << adoptPets.at(i).getAgeIntake() << setw(10)
            << adoptPets.at(i).getAgeCurrent() << endl;
        cout << setw(25) << adoptPets.at(i).getName() << setw(10) << adoptPets.at(i).getType() << setw(35) << adoptPets.at(i).getBreed()
            << setw(20) << adoptPets.at(i).getSex() << setw(10) << adoptPets.at(i).getAgeIntake() << setw(10)
            << adoptPets.at(i).getAgeCurrent() << endl;
    }
    outFile << "\n\n" << endl;
}

void findPet(ofstream& outFile, vector<Pet>& allPets) {
    vector<Pet> namePets;
    string name, type;
    cout << "Enter name and type: " << endl;
    cin >> name >> type;
    // Finds all specified animals.
    for (int i = 0; i < allPets.size(); ++i) {
        if (allPets.at(i).getName() == name && allPets.at(i).getType() == type) {
            namePets.push_back(allPets.at(i));
        }
    }
    // Bubble sort algo crashes with an empty vector so must check if empty, the if also allows reporting an unsuccsessful search to user. 
    if (namePets.size()) {
        bubbleSort(namePets, 'i');
    }
    else {
        cout << "No animals found." << endl;
        return;
    }
    // All the folowing is just formatted output.
    outFile << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    cout << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(35) << "BREED" << setw(20) << "SEX" << setw(10) << "IN AGE"
        << setw(10) << "CURR AGE" << endl;
    for (int i = 0; i < namePets.size(); ++i) {
        outFile << setw(25) << namePets.at(i).getName() << setw(10) << namePets.at(i).getType() << setw(35) << namePets.at(i).getBreed()
            << setw(20) << namePets.at(i).getSex() << setw(10) << namePets.at(i).getAgeIntake() << setw(10)
            << namePets.at(i).getAgeCurrent() << endl;
        cout << setw(25) << namePets.at(i).getName() << setw(10) << namePets.at(i).getType() << setw(35) << namePets.at(i).getBreed()
            << setw(20) << namePets.at(i).getSex() << setw(10) << namePets.at(i).getAgeIntake() << setw(10)
            << namePets.at(i).getAgeCurrent() << endl;
    }
    outFile << "\n\n" << endl;
}

 
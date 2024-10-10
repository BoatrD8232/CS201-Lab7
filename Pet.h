#pragma once 
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Pet {
	string id;
	string name;
	double ageIntake;
	double ageOutcome;
	double ageCurrent;
	int inMon;
	int inYr;
	string outcomeType;
	string type;
	string breed;
	string sex;

	public:
		Pet();
		Pet(string id, string name, string inDate, string outcomeType, string type, string sex, string breed);
		string getID();
		string getName();
		string getOutcome();
		string getType();
		string getBreed();
		string getSex();
		double getAgeIntake();
		double getAgeOutcome();
		double getAgeCurrent();
		int getInMon();
		int getInYr();
		void printPetInfo();
		void setID(string id);
		void setName(string name);
		void setOutcome(string out);
		void setType(string type);
		void setBreed(string breed);
		void setSex(string inSex);
		void setAgeIntake(double ageI);
		void setAgeOutcome(double ageO);
		void setAgeCurrent(double ageC);
		void setIntake(int mon, int year);

};
#include "Pet.h"

Pet::Pet() {

}
Pet::Pet(string id, string name, string inDate, string outcomeType, string type, string sex, string breed) {
}
string Pet::getID() {
	return id;
}
string Pet::getName() {
	return name;
}
string Pet::getOutcome() {
	return outcomeType;
}
string Pet::getType() {
	return type;
}
string Pet::getBreed() {
	return breed;
}
string Pet::getSex() {
	return sex;
}
double Pet::getAgeIntake() {
	return ageIntake;
}
double Pet::getAgeOutcome() {
	return ageOutcome;
}
double Pet::getAgeCurrent() {
	return ageCurrent;
}
int Pet::getInMon() {
	return inMon;
}
int Pet::getInYr() {
	return inYr;
}
void Pet::printPetInfo() {
	cout << "ID: " << getID() << "   Name: " << getName() <<"   Outcome: " << getOutcome() << "    Type: " << getType() 
		 << "   Sex: " << getSex() << " Out Age: " << getAgeOutcome() << "   Breed: " << getBreed() 
		 <<"   InMon: " << getInMon() << "   InYr: " << getInYr() << endl;
}
void Pet::setID(string inid) {
	id = inid;
}
void Pet::setName(string inName) {
	name = inName;
}
void Pet::setOutcome(string out) {
	outcomeType = out;
}
void Pet::setType(string inType) {
	type = inType;
}
void Pet::setBreed(string inBreed) {
	breed = inBreed;
}
void Pet::setSex(string inSex) {
	sex = inSex;
}
void Pet::setAgeIntake(double ageI) {
	ageIntake = ageI;
}
void Pet::setAgeOutcome(double ageO) {
	ageOutcome = ageO;
}
void Pet::setAgeCurrent(double ageC) {
	ageCurrent = ageC;
}
void Pet::setIntake(int mon, int year) {
	inMon = mon;
	inYr = year;
}
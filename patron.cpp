#ifndef PATRON_CPP
#define PATRON_CPP

#include "patron.h"

//Constructor definitions
Patron::Patron() {

	name = "none";
	IDNumber = 000000;
	fineBalance = 0.00;
	currentBooks = 0;

}

Patron::Patron(std::string name, int IDNumber, double fineBalance, int currentBooks) {

	this->name = name;
	this->IDNumber = IDNumber;
	this->fineBalance = fineBalance;
	this->currentBooks = currentBooks;

}

//Get function definitions
std::string Patron::GetName() {

	return name;

}

int Patron::GetIDNumber() {

	return IDNumber;

}

double Patron::GetFineBalance() {

	return fineBalance;

}

int Patron::GetCurrentBooks() {

	return currentBooks;

}

//Set function definitions
void Patron::SetName(std::string name) {

	this->name = name;

}

void Patron::SetIDNumber(int IDNumber) {

	this->IDNumber = IDNumber;

}

void Patron::SetFineBalance(double fineBalance) {

	this->fineBalance = fineBalance;

}

void Patron::SetCurrentBooks(int currentBooks) {

	this->currentBooks = currentBooks;

}


void Patron::PrintInfo() {

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "                Patron Info!           " << std::endl << std::endl;
	std::cout << "Patron Name: " << GetName() << std::endl;
	std::cout << "Patron ID Number: " << GetIDNumber() << std::endl;
	std::cout << "Patron Fine Balance: " << GetFineBalance() << std::endl;
	std::cout << "Patron has " << GetCurrentBooks() << " books out." << std::endl;

}

#endif

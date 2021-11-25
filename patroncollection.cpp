#ifndef PATRONCOLLECTION_CPP
#define PATRONCOLLECTION_CPP

#include "patroncollection.h"

PatronCollection patrons;

//Constructor definition
PatronCollection::PatronCollection() {

	count = 0;

}

//Add patron function
void PatronCollection::AddPatron() {

	//Temp variables to assign to patron object
	std::string tempName;
	int tempIDNumber;
	double tempFineBalance;
	int tempBooksOut;

	//Get info for the patron
	std::cout << "Enter the patrons name: ";
	getline(std::cin, tempName);
	std::cout << std::endl;

	std::cout << "Enter the patrons ID Number: ";
	std::cin >> tempIDNumber;
	std::cin.ignore();
	std::cout << std::endl;

	//Create and populate book object with parameterized constructor, add obj to vector
	Patron patron(tempName, tempIDNumber, 0, 0);
	patronList.push_back(patron);

}

//Print patron function
void PatronCollection::PrintPatron() {

	int tempID;

	std::cout << "Enter the ID of the patron to print: ";
	std::cin >> tempID;
	std::cin.ignore();

	SearchPatron(tempID).PrintInfo();

}

//Save patron info to a text file
void PatronCollection::SavePatrons() {

	std::ofstream fout;
	fout.open("patrons.dat");

	fout << patronList.size() << std::endl;

	//Output patrons info to a line
	for (int i = 0; i < patronList.size(); i++) {

		fout << patronList.at(i).GetIDNumber() << " " <<
			patronList.at(i).GetFineBalance() << " " <<
			patronList.at(i).GetCurrentBooks() << " " <<
			patronList.at(i).GetName() << "," << std::endl;

	}

	fout.close();

}

//Load patron info from a text file
void PatronCollection::LoadPatrons() {

	//fstream variables
	std::ifstream fin;
	int patronCount;

	//temp variables
	int tempID;
	int tempFineBalance;
	int tempCurrentBooks;
	std::string tempName;

	fin.open("patrons.dat");

	fin >> patronCount;
	fin.ignore();

	for (int i = 0; i < patronCount; i++) {

		fin >> tempID >> tempFineBalance >> tempCurrentBooks;
		std::getline(fin, tempName, ',');

		//Pass temp vars to parameterized constructor, then push to vector
		Patron patron(tempName, tempID, tempFineBalance, tempCurrentBooks);
		patronList.push_back(patron);

	}

	//Close the file
	fin.close();

}

//Edit a patron object
void PatronCollection::EditPatron() {

	int tempID;
	int choice;

	std::cout << "Enter the ID of the patron to edit: ";
	std::cin >> tempID;
	std::cin.ignore();

	for (int i = 0; i < patronList.size(); i++) {

		if (patronList.at(i).GetIDNumber() == tempID) {

			patronList.at(i).PrintInfo();

			std::cout << std::endl;
			std::cout << "Which field would you like to edit: " << std::endl;
			std::cout << "1. ID Number" << std::endl;
			std::cout << "2. Name " << std::endl;
			std::cout << "Other fields can be edited through loan management!" << std::endl;
			std::cout << "Enter choice: ";
			std::cin >> choice;
			std::cin.ignore();

			//ID Number
			if (choice == 1) {

				int tempryID;
				std::cout << "New ID: " << std::endl;
				std::cin >> tempryID;
				std::cin.ignore();

				patronList.at(i).SetIDNumber(tempryID);

			}

			//Name
			else if (choice == 2) {

				std::string tempName;
				std::cout << std::endl;
				std::cout << "New name: " << std::endl;
				getline(std::cin, tempName);

				patronList.at(i).SetName(tempName);

			}

			//Invalid
			else {

				std::cout << "Invalid choice..." << std::endl;

			}

		}

	}

}

//Delete a patron object
void PatronCollection::DeletePatron() {

	int tempID;

	std::cout << "Enter the ID of the patron to delete: ";
	std::cin >> tempID;
	std::cin.ignore();

	//Search for the patron and delete it
	for (int i = 0; i < patronList.size(); i++) {

		if (patronList.at(i).GetIDNumber() == tempID) {

			patronList.erase(patronList.begin() + i);

		}

	}

}

//Search for a patron
Patron PatronCollection::SearchPatron(int ID) {

	for (int i = 0; i < patronList.size(); i++) {

		if (patronList.at(i).GetIDNumber() == ID) {

			return patronList.at(i);

		}

	}

}

//Print all patrons info
void PatronCollection::PrintPatronList() {

	for (int i = 0; i < patronList.size(); i++) {

		patronList.at(i).PrintInfo();

	}

}

//Set patron vector
void PatronCollection::SetPatronVec(std::vector<Patron> patronList){

	this->patronList = patronList;

}

//Get patron vector
std::vector<Patron> PatronCollection::GetPatronVec() {

	return patronList;

}

//Pay fines - decrease fine amount by amount paid
void PatronCollection::PayFines() {

	int tempID;
	double paymentAmount;

	std::cout << "Enter patron ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	std::cout << "Enter payment amount: " << std::endl;
	std::cin >> paymentAmount;
	std::cin.ignore();

	//Reduce fine balance by payment amount
	for (int i = 0; i < patronList.size(); i++) {

		if (patronList.at(i).GetIDNumber() == tempID) {

			double currentFines = patronList.at(i).GetFineBalance();
			patronList.at(i).SetFineBalance(currentFines - paymentAmount);

		}

	}


}

void PatronCollection::CleanUp() {

	patronList.clear();

}



#endif
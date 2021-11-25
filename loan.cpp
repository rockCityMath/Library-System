#ifndef LOAN_CPP
#define LOAN_CPP

#include "loan.h"
#include "patroncollection.h"
#include "bookcollection.h"

extern PatronCollection patrons;
extern BookCollection collection;

//Constructor definitions
Loan::Loan() {

	IDNumber = 0;
	custID = 0;
	bookID = 0;
	dueTime = 0;

}

Loan::Loan(int IDNumber, int custID, int bookID, time_t dueTime) {

	this->IDNumber = IDNumber;
	this->custID = custID;
	this->bookID = bookID;
	this->dueTime = dueTime;

}

//Get function declarations
int Loan::GetIDNumber() {

	return IDNumber;

}

int Loan::GetCustID() {

	return custID;

}

int Loan::GetBookID() {

	return bookID;

}

bool Loan::GetLoanOverdue() {

	return loanOverdue;

}

time_t Loan::GetDueTime() {

	return dueTime;

}

//Set function definitions
void Loan::SetIDNumber(int IDNumber) {

	this->IDNumber = IDNumber;

}

void Loan::SetCustID(int custID) {

	this->custID = custID;

}

void Loan::SetBookID(int bookID) {

	this->bookID = bookID;

}

void Loan::SetDueTime(time_t dueTime) {

	this->dueTime = dueTime;

}

void Loan::SetLoanOverdue(bool loanOverdue) {

	this->loanOverdue = loanOverdue;

}

//Print function definition
void Loan::PrintInfo() {

	//loan ID, customer name, book name

	std::string name;
	std::string bookName;

	//Local vector to use in finding names
	std::vector<Patron> tempPatronList = patrons.GetPatronVec();
	std::vector<Book> tempBookList = collection.GetBookVec();

	//Find customer name
	for(int i = 0; i < tempPatronList.size(); i++) {
	
		if (tempPatronList.at(i).GetIDNumber() == GetCustID()) {

			name = tempPatronList.at(i).GetName();

		}
	
	}

	//Find book name
	for (int i = 0; i < tempBookList.size(); i++) {

		if (tempBookList.at(i).GetIDNumber() == GetBookID()) {

			bookName = tempBookList.at(i).GetTitle();

		}

	}

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "                Loan Info!           " << std::endl << std::endl;
	std::cout << "Loan ID: " << GetIDNumber() << std::endl;
	std::cout << "Customer: " << name << std::endl;
	std::cout << "Book: " << bookName << std::endl;
	std::cout << std::endl;

}

#endif
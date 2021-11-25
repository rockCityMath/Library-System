#ifndef LOANCOLLECTION_CPP
#define LOANCOLLECTION_CPP

#include "loancollection.h"
#include "bookcollection.h"
#include "patroncollection.h"

LoanCollection loans;
extern BookCollection collection;
extern PatronCollection patrons;

//Constructor definition
LoanCollection::LoanCollection() {

	count = 0;

}

//Save patron data to file
void LoanCollection::SaveLoans() {

	std::ofstream fout;
	fout.open("loans.dat");

	fout << loanList.size() << std::endl;

	//Output loan info to a line
	for (int i = 0; i < loanList.size(); i++) {

		fout << loanList.at(i).GetIDNumber() << " " <<
			loanList.at(i).GetCustID() << " " <<
			loanList.at(i).GetBookID() << " " <<
			loanList.at(i).GetDueTime() << " " << std::endl;

	}

	fout.close();

}

//Load data from file(dat)
void LoanCollection::LoadLoans() {

	//fstream variables
	std::ifstream fin;

	//temp variables
	int loanCount;
	int tempID;
	int tempCustID;
	int tempBookID;
	time_t tempDueTime;

	fin.open("loans.dat");

	fin >> loanCount;
	fin.ignore();

	for (int i = 0; i < loanCount; i++) {

		fin >> tempID >> tempCustID >> tempBookID >> tempDueTime;

		Loan loan(tempID, tempCustID, tempBookID, tempDueTime);
		loanList.push_back(loan);

	}

	fin.close();

}

//Check out a book - add a loan
void LoanCollection::CheckOut() {

	//Temp variables to assign to loan object
	int IDNumber;
	int custID;
	int bookID;
	bool canCheckOut;

	//Get info from user
	std::cout << "Enter the new loan ID: ";
	std::cin >> IDNumber;
	std::cin.ignore();

	std::cout << "Enter the existing customers ID: ";
	std::cin >> custID;
	std::cin.ignore();

	std::cout << "Enter the book ID: ";
	std::cin >> bookID;
	std::cin.ignore();

	//Local copy of book vector to operate on
	std::vector<Book> tempBookList = collection.GetBookVec();

	//Local copy of the patron vector to operate on
	std::vector<Patron> tempPatronList = patrons.GetPatronVec();

	//Check if they have under 6 books out
	for (int i = 0; i < tempPatronList.size(); i++) {

		if (tempPatronList.at(i).GetCurrentBooks() < 6) {

			canCheckOut = true;

		}

	}

	//If they can check out
	if (canCheckOut == true) {

		//Get current time and use it to calculate due date
		time_t now, dueTime;
		time(&now);

		dueTime = now + (60 * 60 * 24 * 10);  //60 seconds in an minute, 60 minutes in an hour, 24 hours in a day, 10 days in a period

		std::cout << "Book will be due at " << ctime(&dueTime);

		//Set book status to out (in tempBookList vector)
		for (int i = 0; i < tempBookList.size(); i++) {

			if (tempBookList.at(i).GetIDNumber() == bookID) {

				tempBookList.at(i).SetStatus("Out");

			}

		}

		//Replace other vector with the local copy that has been operated on
		collection.SetBookVec(tempBookList);

		//Increase patron's number of books by one (in tempPatronList vector)
		for (int i = 0; i < tempPatronList.size(); i++) {

			if (tempPatronList.at(i).GetIDNumber() == custID) {

				int booksOut = tempPatronList.at(i).GetCurrentBooks();
				tempPatronList.at(i).SetCurrentBooks(booksOut + 1);

			}

		}

		//Replace other vector with the local copy that has been operated on
		patrons.SetPatronVec(tempPatronList);

		//Pass to constructor, push object to loanList vector
		Loan loan(IDNumber, custID, bookID, dueTime);
		loanList.push_back(loan);

	}
}

//Check in a book - delete a loan CHECK OVERDUE
void LoanCollection::CheckIn() {

	int tempID;
	int tempPatronID;
	int tempBookID;
	int secondsPastDue;
	int daysPastDue;
	double amountOwed = 0.00;

	std::cout << "Enter loan ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	//Decrease books out, set book status, erase loan, check fines

	//Local copy of book vector to operate on
	std::vector<Book> tempBookList = collection.GetBookVec();
	std::vector<Patron> tempPatronList = patrons.GetPatronVec();

	//Check if the patron owes fines on this book
	//Get current time
	time_t now;
	time(&now);

	//See if this book is overdue, if so add fine
	for (int i = 0; i < loanList.size(); i++) {
				
		if (loanList.at(i).GetIDNumber() == tempID) {

			//Get how many seconds past due
			secondsPastDue = now - loanList.at(i).GetDueTime();
			
			bool overdue;
			if(secondsPastDue > 86400) { overdue = true; }
			else {overdue = false; }

			if(overdue == false) { std::cout << "Not overdue" << std::endl; }
			

			//See if its overdue enough to charge a fine
			if (overdue == true) {

				//Calculate how many days those seconds make up
				daysPastDue = secondsPastDue / 86400;

				std::cout << "Days past due: " << daysPastDue << std::endl;

				//Set the amount the customer owes
				amountOwed = daysPastDue * 0.25;

			}
		
		}

	}


	//Get the patron ID from the loan vector
	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == tempID) {

			tempPatronID = loanList.at(i).GetCustID();
			tempBookID = loanList.at(i).GetBookID();

		}
	
	}

	//Set book status to in (in tempBookList vector)
	for (int i = 0; i < tempBookList.size(); i++) {

		if (tempBookList.at(i).GetIDNumber() == tempBookID) {

			tempBookList.at(i).SetStatus("In");

		}

	}
	
	//Decrese books out and add amount owed(in tempPatronList vector)
	for (int i = 0; i < tempPatronList.size(); i++) {

		if (tempPatronList.at(i).GetIDNumber() == tempPatronID) {

			int booksOut = tempPatronList.at(i).GetCurrentBooks();
			tempPatronList.at(i).SetCurrentBooks(booksOut - 1);

			//Add amount owed to current amount
			double currentFines = tempPatronList.at(i).GetFineBalance();
			tempPatronList.at(i).SetFineBalance(currentFines + amountOwed);

			std::cout << "New amount owed: " << tempPatronList.at(i).GetFineBalance();

		}
	
	}

	//Erase loan
	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == tempID) {

			loanList.erase(loanList.begin() + i);

		}

	}

	//Replace vectors with local copy that has been operated on
	collection.SetBookVec(tempBookList);
	patrons.SetPatronVec(tempPatronList);

}

//Search for and print info for all overdue loans
void LoanCollection::ListOverdue() {

	std::cout << "--------Overdue Loans-----------" << std::endl;

	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetLoanOverdue() == true) {

			loanList.at(i).PrintInfo();

		}

	}

}

//Print a single loan's info
void LoanCollection::LoanInfo() {

	int tempID;

	std::cout << "Enter loan ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetBookID() == tempID) {

			loanList.at(i).PrintInfo();

		}

	}

}

//Check if loans are overdue and update their bool value
void LoanCollection::UpdateLoans() {
	
	//Get current time
	time_t now, dueTime;
	time(&now);

	//std::cout << "Current: " << std::endl;
	//std::cout << std::endl << ctime(&now);

	 //Look through loans and see which are overdue, assign them a loanOverdue of true;
	for (int i = 0; i < loanList.size(); i++) {

		//std::cout << "Due: " << std::endl;
		//dueTime = loanList.at(i).GetDueTime();
		//std::cout << ctime(&dueTime);
		//std::cout << std::endl;

		if (loanList.at(i).GetDueTime() < now) {
			
			loanList.at(i).SetLoanOverdue(true);

		}

	}


}

//List all books for a certain patron
void LoanCollection::ListPatronBooks() {

	std::vector<Book> tempBookList = collection.GetBookVec();

	int tempID;

	std::cout << "Enter the patrons ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	std::cout << std::endl << "--------Current Books Out-----------" << std::endl;

	//Search for this patron's ID in the loan vector
	for (int i = 0; i < loanList.size(); i++) {

		//When patron ID is found
		if (loanList.at(i).GetCustID() == tempID) {

			int location = i;

			for (int i = 0; i < tempBookList.size(); i++) {

				if (tempBookList.at(i).GetIDNumber() == loanList.at(location).GetBookID()) {

					std::cout << tempBookList.at(i).GetTitle();

				}

				std::cout << std::endl;

			}

		}


	}

}

//Recheck a book for 10 more days
void LoanCollection::RecheckBook() {

	int tempID;

	std::cout << "Enter loan ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == tempID) {

			time_t currentDueTime, newDueTime;
			currentDueTime = loanList.at(i).GetDueTime();

			//Add ten more days to due time
			newDueTime = currentDueTime + (60 * 60 * 24 * 10);
			
			std::cout << "New due time: " << std::endl;
			std::cout << ctime(&newDueTime) << std::endl;

		}

	}

}

void LoanCollection::ReportLost() {

	//Local copy of vectors
	std::vector<Book> tempBookList = collection.GetBookVec();
	std::vector<Patron> tempPatronList = patrons.GetPatronVec();

	int tempID;
	int bookID;
	int patronID;
	double bookCost;
	int amountOwed;
	int currentFines;

	std::cout << "Enter Loan ID: ";
	std::cin >> tempID;
	std::cin.ignore();

	//Set book to lost, charge patron the fine, remove the loan, decrease books out

	//Find book ID and Patron ID
	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == tempID) {

			bookID = loanList.at(i).GetBookID();
			patronID = loanList.at(i).GetCustID();

		}

	}


	//Set book status to lost, get cost of book, get patron ID(in tempBookList)
	for (int i = 0; i < tempBookList.size(); i++) {

		if (tempBookList.at(i).GetIDNumber() == bookID) {

			tempBookList.at(i).SetStatus("Lost");
			bookCost = tempBookList.at(i).GetCost();

		}

	}
	
	//Charge the patron the cost of the book
	for (int i = 0; i < tempPatronList.size(); i++) {

		if (tempPatronList.at(i).GetIDNumber() == patronID) {

			amountOwed = tempPatronList.at(i).GetFineBalance();
			tempPatronList.at(i).SetFineBalance(amountOwed + bookCost);
			int currentBooks = tempPatronList.at(i).GetCurrentBooks();
			tempPatronList.at(i).SetCurrentBooks(currentBooks - 1);

		}

	}

	//Erase loan
	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == tempID) {

			loanList.erase(loanList.begin() + i);

		}

	}

	//Replace bookList with local copy	
	collection.SetBookVec(tempBookList);
	patrons.SetPatronVec(tempPatronList);

}

//Search for loan based on ID and return object
Loan LoanCollection::SearchLoan(int ID) {

	for (int i = 0; i < loanList.size(); i++) {

		if (loanList.at(i).GetIDNumber() == ID) {

			return loanList.at(i);

		}

	}

}

void LoanCollection::CleanUp() {

	loanList.clear();

}

#endif
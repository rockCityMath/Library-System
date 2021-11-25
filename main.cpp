// Zachary Carpenter
//UNT Engineering CSCE 1040
//10-11-20
#include <iostream>

#include "book.h"
#include "bookcollection.h"
#include "patroncollection.h"
#include "loancollection.h"


int main() {

	//Submenu option chars
	char  menuOption;
	char subMenuOption1;
	char subMenuOption2;
	char subMenuOption3;

	//Submenu loop bools
	bool quit = false;
	bool quitSubMenu1 = false;
	bool quitSubMenu2 = false;
	bool quitSubMenu3 = false;

	//Populate collections with dat files
	extern BookCollection collection;
	extern PatronCollection patrons;
	extern LoanCollection loans;

	collection.LoadBooks();
	patrons.LoadPatrons();
	loans.LoadLoans(); 

	//Main program loop
	while (quit != true) {
			
		quit = false;
		quitSubMenu1 = false;
		quitSubMenu2 = false;
		quitSubMenu3 = false;


		//Main menu options
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Welcome to the Library Management System!" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Please choose an option..." << std::endl;
		std::cout << "1. Manage Books" << std::endl;
		std::cout << "2. Manage Patrons" << std::endl;
		std::cout << "3. Manage Loans" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << "Option: ";

		std::cin >> menuOption;
		std::cin.ignore();

		//Case manage books
		if (menuOption == '1') {

			//Book managemnt loop
			while (quitSubMenu1 != true) {
				
				std::cout << std::endl << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "          Manage Books!             " << std::endl << std::endl;
				std::cout << "Please choose an option..." << std::endl;
				std::cout << "1. Add Book" << std::endl;
				std::cout << "2. Edit Book" << std::endl;
				std::cout << "3. Delete Book" << std::endl;
				std::cout << "4. Print a Book's details" << std::endl;   //Print single book details?
				std::cout << "5. Print all Book Details" << std::endl;
				std::cout << "6. Go Back to Main Menu" << std::endl;
				std::cout << "Option: ";

				std::cin >> subMenuOption1;
				std::cin.ignore();

				//Add book
				if (subMenuOption1 == '1') {

					collection.AddBook();

				}

				//Edit book
				else if (subMenuOption1 == '2') {

					collection.EditBook();

				}

				//Delete book
				else if (subMenuOption1 == '3') {

					collection.DeleteBook();

				}

				//Print single book
				else if (subMenuOption1 == '4') {

					collection.PrintBook();

				}

				//Print all books
				else if (subMenuOption1 == '5') {

					collection.PrintBookList();

				}

				//Quit menu
				else if (subMenuOption1 == '6') {

					quitSubMenu1 = true;

				}

				//Invalid 
				else {

					std::cout << std::endl;
					std::cout << "Invalid, try again..." << std::endl;
					std::cout << std::endl;

				}

			}

		}

		//Case manage patrons
		else if (menuOption == '2') {
			
			//Patron management loop
			while (quitSubMenu2 != true) {

				std::cout << std::endl << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "          Manage Patrons!             " << std::endl << std::endl;
				std::cout << "Please choose an option..." << std::endl;
				std::cout << "1. Add Patron" << std::endl;
				std::cout << "2. Edit Patron" << std::endl;
				std::cout << "3. Delete Patron" << std::endl;
				std::cout << "4. Print a patrons details" << std::endl;
				std::cout << "5. Print all Patron Details" << std::endl;
				std::cout << "6. Pay Patron Fines" << std::endl;
				std::cout << "7. Go Back to Main Menu" << std::endl;
				std::cout << "Option: ";

				std::cin >> subMenuOption2;
				std::cin.ignore();

				//Add patron
				if (subMenuOption2 == '1') {

					patrons.AddPatron();
					patrons.SavePatrons();

				}

				//Edit patron
				else if (subMenuOption2 == '2') {

					patrons.EditPatron();
					patrons.SavePatrons();

				}

				//Delete patron
				else if (subMenuOption2 == '3') {

					patrons.DeletePatron();
					patrons.SavePatrons();

				}

				//Print single patrons
				else if (subMenuOption2 == '4') {

					patrons.PrintPatron();

				}

				//Print all patrons
				else if (subMenuOption2 == '5') {

					patrons.PrintPatronList();

				}

				//Pay patron fines
				else if (subMenuOption2 == '6') {

					patrons.PayFines();

				}

				//Quit menu
				else if (subMenuOption2 == '7') {

					quitSubMenu2 = true;

				}

				//Invalid choice
				else {

					//Formatting?
					std::cout << std::endl;
					std::cout << "Invalid, try again..." << std::endl;
					std::cout << std::endl;

				}


			}

		}

		//Case manage loans
		else if (menuOption == '3') {

		//Loan management loop
			while (quitSubMenu3 != true) {

				std::cout << std::endl << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << "          Manage Loans!             " << std::endl << std::endl;
				std::cout << "Please choose an option..." << std::endl;
				std::cout << "1. Check out a Book" << std::endl;
				std::cout << "2. Check in a Book" << std::endl;
				std::cout << "3. List all Overdue Books (Must update loans first) " << std::endl;
				std::cout << "4. List all of a Patrons Current Books" << std::endl;
				std::cout << "5. Update Loan Status'" << std::endl; 
				std::cout << "6. Re-Check a Book" << std::endl;
				std::cout << "7. Report a Book Lost" << std::endl;
				std::cout << "8. Go Back to Main Menu" << std::endl;
				std::cout << "Option: ";

				std::cin >> subMenuOption3;
				std::cin.ignore();

				if (subMenuOption3 == '1') {

					loans.CheckOut();

				}

				else if (subMenuOption3 == '2') {

					loans.CheckIn();

				}

				else if (subMenuOption3 == '3') {

					loans.ListOverdue();

				}

				else if (subMenuOption3 == '4') {

					loans.ListPatronBooks();

				}

				else if (subMenuOption3 == '5') {

					loans.UpdateLoans();

				}

				else if (subMenuOption3 == '6') {

					loans.RecheckBook();

				}

				else if (subMenuOption3 == '7') {

					loans.ReportLost();

				}

				else if (subMenuOption3 == '8') {

					quitSubMenu3 = true;

				}

				else {

					std::cout << std::endl;
					std::cout << "Invalid, try again..." << std::endl;
					std::cout << std::endl;

				}
			}


		}

		//Case quit menu
		else if (menuOption == '4') {

			quit = true;

			//Save all data to .dat files
			loans.SaveLoans();
			collection.SaveBooks();
			patrons.SavePatrons();

			//Clear vectors
			loans.CleanUp();
			collection.CleanUp();
			patrons.CleanUp();
			

		}

	}





	return 0;

}
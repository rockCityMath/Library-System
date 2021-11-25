#ifndef BOOKCOLLECTION_CPP
#define BOOKCOLLECTION_CPP

#include "bookcollection.h"

BookCollection collection;

//Constructor definitions - vestigial ?
BookCollection::BookCollection() {

	count = 0;

}

//Add book function
void BookCollection::AddBook() {

	int tempID;
	std::string tempAuthor;
	std::string tempTitle;
	int tempISBN;
	double tempCost;
	std::string tempStatus;

	//Get info for the customers
	std::cout << "Enter the book ID: ";
	std::cin >> tempID;
	std::cin.ignore();
	std::cout << std::endl;

	std::cout << "Enter the author: ";
	std::getline(std::cin, tempAuthor);
	std::cout << std::endl;

	std::cout << "Enter the title: ";
	std::getline(std::cin, tempTitle);
	std::cout << std::endl;

	std::cout << "Enter the ISBN: ";
	std::cin >> tempISBN;
	std::cin.ignore();
	std::cout << std::endl;

	std::cout << "Enter the cost: ";
	std::cin >> tempCost;
	std::cin.ignore();
	std::cout << std::endl;

	std::cout << "Enter the status (in, out, lost, repair): ";
	std::getline(std::cin, tempStatus);
	std::cout << std::endl;

	//Create and populate book object with parameterized constructor, then add that object to the vector (bookList) of books
	Book book(tempAuthor, tempTitle, tempISBN, tempID, tempCost, tempStatus);
	bookList.push_back(book);

}

//Print single book function
void BookCollection::PrintBook() {
	
	int tempID;

	std::cout << "Enter the ID of the book to print: ";
	std::cin >> tempID;

	for (int i = 0; i < bookList.size(); i++) {

		if (bookList.at(i).GetIDNumber() == tempID) {

			bookList.at(i).PrintInfo();

		}

	}

}

//Print list of books function
void BookCollection::PrintBookList() {

	for (int i = 0; i < bookList.size(); i++) {

		bookList.at(i).PrintInfo();
			
	}

}

//Delete book function
void BookCollection::DeleteBook() {

	int tempID;

	std::cout << "Enter the ID of the book to delete: ";
	std::cin >> tempID;
	std::cin.ignore();

	//Search for the book and delete it
	for (int i = 0; i < bookList.size(); i++) {

		if (bookList.at(i).GetIDNumber() == tempID) {

			bookList.erase(bookList.begin() + i);

		}

	}

}

//Edit book function
void BookCollection::EditBook() {

	int tempID;
	int choice;

	std::cout << "Enter the ID of the book to edit: ";
	std::cin >> tempID;

	for (int i = 0; i < bookList.size(); i++) {

		if (bookList.at(i).GetIDNumber() == tempID) {

			bookList.at(i).PrintInfo();

			std::cout << std::endl;
			std::cout << "Which field would you like to edit: " << std::endl;
			std::cout << "1. Author" << std::endl;
			std::cout << "2. Title" << std::endl;
			std::cout << "3. ISBN" << std::endl;
			std::cout << "4. ID Number" << std::endl;
			std::cout << "5. Cost" << std::endl;
			std::cout << "6. Status" << std::endl;
			std::cout << "Enter choice: ";
			std::cin >> choice;
			std::cin.ignore();

			//Author
			if (choice == 1) {

				std::string tempAuthor;
				std::cout << std::endl;
				std::cout << "New author name: ";
				getline(std::cin, tempAuthor);

				bookList.at(i).SetAuthor(tempAuthor);

			}

			//Title 
			else if (choice == 2) {

				std::string tempTitle;
				std::cout << std::endl;
				std::cout << "New title: ";
				getline(std::cin, tempTitle);

				bookList.at(i).SetTitle(tempTitle);

			}

			//ISBN
			else if (choice == 3) {

				int tempISBN;
				std::cout << std::endl;
				std::cout << "New ISBN: ";
				std::cin >> tempISBN;
				std::cin.ignore();

				bookList.at(i).SetISBN(tempISBN);

			}

			//ID Number
			else if (choice == 4) {

				int tempID;
				std::cout << std::endl;
				std::cout << "New ID: ";
				std::cin >> tempID;
				std::cin.ignore();

				bookList.at(i).SetIDNumber(tempID);

			}

			//Cost
			else if (choice == 5) {

				double tempCost;
				std::cout << std::endl;
				std::cout << "New cost: ";
				std::cin >> tempCost;
				std::cin.ignore();

				bookList.at(i).SetCost(tempCost);

			}

			//Status
			else if (choice == 6) {

				std::string tempStatus;
				std::cout << std::endl;
				std::cout << "New status: ";
				getline(std::cin, tempStatus);

				bookList.at(i).SetStatus(tempStatus);

			}

			//Invalid
			else {

				std::cout << "Invalid choice..." << std::endl;

			}


		}

	}
		
}

//Search function
Book BookCollection::SearchBook(int ID) {

	for (int i = 0; i < bookList.size(); i++) {

		if (bookList.at(i).GetIDNumber() == ID) {

			return bookList.at(i);

		}

	}

}

//Save book info from a text file
void BookCollection::LoadBooks() {

	//fstream variables
	std::ifstream fin;
	int bookCount;

	//Temp variables
	int tempID;
	std::string tempAuthor;
	std::string tempTitle;
	int tempISBN;
	double tempCost;
	std::string tempStatus;

	//Open data file
	fin.open("books.dat");

	//Read amt of books from data file
	fin >> bookCount;
	fin.ignore();

	for (int i = 0; i < bookCount; i++) {

		//Read in the variables from the file line
		fin >> tempID;
		std::getline(fin, tempAuthor, ',');
		std::getline(fin, tempTitle, ',');
		fin >> tempISBN >> tempCost >> tempStatus;

		//Create book object with temp variables
		Book book(tempAuthor, tempTitle, tempISBN, tempID, tempCost, tempStatus);
		bookList.push_back(book);

	}

	//Close the file
	fin.close();
	
}

//Function to save books to data file
void BookCollection::SaveBooks() {

	std::ofstream fout;
	fout.open("books.dat");
	
	fout << bookList.size() << std::endl;

	//Output books info to a line
	for (int i = 0; i < bookList.size(); i++) {

		fout << bookList.at(i).GetIDNumber() << " " <<
			bookList.at(i).GetAuthor() << "," <<
			bookList.at(i).GetTitle() << "," <<
			bookList.at(i).GetISBN() << " " <<
			bookList.at(i).GetCost() << " " <<
			bookList.at(i).GetStatus() << " " << std::endl;

	}

	fout.close();

}

//Get book vector
std::vector<Book> BookCollection::GetBookVec() {

	return bookList;

}

void BookCollection::SetBookVec(std::vector<Book> bookList) {

	this->bookList = bookList;

}

void BookCollection::CleanUp() {

	bookList.clear();

}

#endif
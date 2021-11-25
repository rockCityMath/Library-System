#ifndef PATRON_H
#define PATRON_H

#include <string> 
#include <iostream>
#include <vector>

#include "book.h"

class Patron {

	private:
		
		//Private data variables (patron)
		std::string name;
		int IDNumber;
		double fineBalance;
		int currentBooks;
		//std::vector<Book> booksOut;

	public:

		//Default and parameterized constructor
		Patron();
		Patron(std::string name, int IDNumber, double fineBalance, int currentBooks);

		//Get function declarations
		std::string GetName();
		int GetIDNumber();
		double GetFineBalance();
		int GetCurrentBooks();
		//std::vector<Book> GetBooksOut();

		//Set function declarations
		void SetName(std::string name);
		void SetIDNumber(int IDNumber);
		void SetFineBalance(double fineBalance);
		void SetCurrentBooks(int currentBooks);
		//void SetBooksOut(std::vector<Book> booksOut);

		//other function declaration
		void PrintInfo();



};

#endif
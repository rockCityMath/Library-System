#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {

	private:

		//Private data variables
		std::string author;
		std::string title;
		int ISBN;
		int IDNumber;
		double cost;
		std::string status;

	public:

		//Default and parameterized constructors
		Book();
		Book(std::string author, std::string title, int ISBN, int IDNumber, double cost, std::string status);

		//Get function declarations
		std::string GetAuthor();
		std::string GetTitle();
		int GetISBN();
		int GetIDNumber();
		double GetCost();
		std::string GetStatus();

		//Set function declarations
		void SetAuthor(std::string author);
		void SetTitle(std::string title);
		void SetISBN(int ISBN);
		void SetCost(double GetCost);
		void SetStatus(std::string status);
		void SetIDNumber(int IDNumber);

		//Print function declaration
		void PrintInfo();

};

#endif
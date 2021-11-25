#ifndef BOOKCOLLECTION_H
#define BOOKCOLLECTION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "book.h"

class BookCollection {

	private:

		//Private data variables
		int count;
		std::vector<Book> bookList;      //Vector of book objects 

	public:

		//Default and parameterized constructors
		BookCollection();

		//Functions on book object
		void AddBook();
		void EditBook();
		void DeleteBook();
		void PrintBookList();
		void PrintBook();

		//Save/Load functions
		void SaveBooks();
		void LoadBooks();

		//Other functions
		Book SearchBook(int ID);
		std::vector<Book> GetBookVec();
		void SetBookVec(std::vector<Book> bookList);
		void CleanUp();

};

#endif
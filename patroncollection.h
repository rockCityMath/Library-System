#ifndef PATRONCOLLECTION_H
#define PATRONCOLLECTION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "patron.h"

class PatronCollection {

	private:

		//Private data variables
		int count;
		std::vector<Patron> patronList;

	public:

		//Default constructor
		PatronCollection();

		//Functions on a patron object
		void AddPatron();
		void EditPatron();
		void DeletePatron();
		void PrintPatronList();
		void PrintPatron();

		//Save/Load functions
		void SavePatrons();
		void LoadPatrons();

		//Other function
		Patron SearchPatron(int ID);
		void SetPatronVec(std::vector<Patron> patronList);
		std::vector<Patron> GetPatronVec();
		void PayFines();
		void CleanUp();
		
};

#endif
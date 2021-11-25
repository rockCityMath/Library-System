#ifndef LOANCOLLECTION_H
#define LOANCOLLECTION_H

#include <iostream>
#include <vector>
#include <fstream>

#include "loan.h"

class LoanCollection {

	private:

		//Private data variables
		int count;
		std::vector<Loan> loanList;

	public:

		//Default constructor
		LoanCollection();

		//Functions on a loan object
		void CheckOut();
		void CheckIn();
		void ListOverdue();
		void ListPatronBooks();
		void UpdateLoans();
		void RecheckBook();
		void ReportLost();
		void LoanInfo();

		//Save/Load functions
		void SaveLoans();
		void LoadLoans();

		//Other functions
		Loan SearchLoan(int ID);
		void CleanUp();

};

#endif
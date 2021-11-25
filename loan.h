#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <string>
#include <time.h>

class Loan {

	private:
		
		//Private data variables
		int IDNumber;
		int custID;
		int bookID;
		time_t dueTime;
		bool loanOverdue;

	public:

		//Default and parameterized constructor
		Loan();
		Loan(int IDNumber, int custID, int bookID, time_t dueTime);

		//Get function declaration
		int GetIDNumber();
		int GetCustID();
		int GetBookID();
		bool GetLoanOverdue();
		time_t GetDueTime();

		//Set function declaration
		void SetIDNumber(int IDNumber);
		void SetCustID(int custID);
		void SetBookID(int bookID);
		void SetDueTime(time_t dueTime);
		void SetLoanOverdue(bool loanOverdue);

		//Print function declaration
		void PrintInfo();

};


#endif
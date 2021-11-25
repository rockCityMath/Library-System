#ifndef BOOK_CPP
#define BOOK_CPP

#include "book.h"

//Constructor definitions
Book::Book() {

	author = "none";
	title = "none";
	ISBN = 00000000;
	IDNumber = 000000;
	cost = 0.00;
	status = "none";

}

Book::Book(std::string author, std::string title, int ISBN, int IDNumber, double cost, std::string status) {

	this->author = author;
	this->title = title;
	this->ISBN = ISBN;
	this->IDNumber = IDNumber;
	this->cost = cost;
	this->status = status;

}

//Get function definitions
std::string Book::GetAuthor() {

	return author;

}

std::string Book::GetTitle() {

	return title;

}

int Book::GetISBN() {

	return ISBN;

}

int Book::GetIDNumber() {

	return IDNumber;

}

double Book::GetCost() {

	return cost;

}

std::string Book::GetStatus() {

	return status;

}

//Set function definitions
void Book::SetAuthor(std::string author) {

	this->author = author;

}

void Book::SetTitle(std::string title) {

	this->title = title;

}

void Book::SetISBN(int ISBN) {

	this->ISBN = ISBN;

}

void Book::SetCost(double cost) {

	this->cost = cost;

}

void Book::SetStatus(std::string status) {

	this->status = status;

}

void Book::SetIDNumber(int IDNumber) {

	this->IDNumber = IDNumber;

}

//Print function definitions
void Book::PrintInfo() {

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "                Book Info!           " << std::endl << std::endl;
	std::cout << "Book Title: " << GetTitle() << std::endl;
	std::cout << "Book Author: " << GetAuthor() << std::endl;
	std::cout << "Book ISBN Number: " << GetISBN() << std::endl;
	std::cout << "Book ID Number: " << GetIDNumber() << std::endl;
	std::cout << "Book Cost: " << GetCost() << std::endl;
	std::cout << "Book Status: " << GetStatus() << std::endl;

}

#endif
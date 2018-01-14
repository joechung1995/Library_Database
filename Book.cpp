/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: class functions for Book.hpp
*********************************************************************/
#include "Book.hpp"

using namespace std;

Book::Book(std::string idc, std::string t, std::string a) : LibraryItem(idc, t), author(a) {}

string Book::getAuthor() 
{
	return author;
}

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}


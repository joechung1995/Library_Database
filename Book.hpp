/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: Header file for Book
*********************************************************************/
#ifndef BOOK_HPP
#define BOOK_HPP

#include "LibraryItem.hpp"

using namespace std;

class Book : public LibraryItem
{
	private:
		string author;
	public:
		static const int CHECK_OUT_LENGTH = 21;

		Book(string idc, string t, string a);
		string getAuthor();
		int getCheckOutLength();
};

#endif

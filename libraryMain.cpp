/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: main for Library
*********************************************************************/
#include <iostream>
#include "Library.hpp"

using namespace std;

int main()
{
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Library lib;
	lib.addLibraryItem(&b1);
	lib.addLibraryItem(&b2);
	lib.addLibraryItem(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	cout << lib.checkOutLibraryItem("bcd", "234") << endl;
	for (int i = 0; i < 7; i++)
		lib.incrementCurrentDate();
	cout << lib.checkOutLibraryItem("bcd", "123") << endl;
	cout << lib.checkOutLibraryItem("abc", "345") << endl;
	for (int i = 0; i < 24; i++)
		lib.incrementCurrentDate();
	lib.payFine("bcd", 0.4);
	double p1Fine = p1.getFineAmount();
	double p2Fine = p2.getFineAmount();

	system("PAUSE");
	return 0;
}

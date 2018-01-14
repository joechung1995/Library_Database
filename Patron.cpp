/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: class functions for Patron.hpp
*********************************************************************/
#include <algorithm>
#include "Patron.hpp"

using namespace std;

Patron::Patron(string idn, string n) : idNum(idn), name(n), fineAmount(0.) {}

string Patron::getIdNum() 
{
	return idNum;
}

string Patron::getName() 
{
	return name;
}

vector<LibraryItem*> Patron::getCheckedOutItems() 
{
	return checkedOutItems;
}

void Patron::addLibraryItem(LibraryItem* b) 
{
	// add library item to the end of the vector
	checkedOutItems.push_back(b);
}

void Patron::removeLibraryItem(LibraryItem* b) 
{
	// search for library item
	vector<LibraryItem*>::iterator i = find(checkedOutItems.begin(), checkedOutItems.end(), b);
	
	// not found
	if (i != checkedOutItems.end())
		checkedOutItems.erase(i);
}

double Patron::getFineAmount() 
{
	return fineAmount;
}

void Patron::amendFine(double amount) 
{
	fineAmount = fineAmount + amount;
}

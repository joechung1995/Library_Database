/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: class functions for Library.hpp
*********************************************************************/
#include "Library.hpp"

using namespace std;

// initial date is 0
Library::Library() : currentDate(0) {}

// adds library item to the end of the vector
void Library::addLibraryItem(LibraryItem *li)
{
	holdings.push_back(li);
}

// adds patrong to the end of the vector
void Library::addPatron(Patron *p) 
{
	members.push_back(p);
}

// checks out library item
string Library::checkOutLibraryItem(string patronID, string ItemID) 
{
	// try to get library item by id
	LibraryItem *li = getLibraryItem(ItemID);
	if (!li)
		return "item not found";

	// try to get patron by id
	Patron *p = getPatron(patronID);
	if (!p)
		return "patron not found";

	// check if item is checked out
	if (li->getCheckedOutBy())
		return "item already checked out";

	// check if item is on hold
	Patron *p1 = li->getRequestedBy();
	if (p1 && p1 != p)
		return "item on hold by other patron";

	// check out item
	li->setCheckedOutBy(p);
	li->setDateCheckedOut(currentDate);
	li->setLocation(CHECKED_OUT);

	// remove requested by
	if (p1)
		li->setRequestedBy(NULL);

	// add library item to the patron's vector
	p->addLibraryItem(li);

	return "check out successful";
}

// returns checked out livrary item
string Library::returnLibraryItem(std::string ItemID) 
{
	// try to get library item by id
	LibraryItem *li = getLibraryItem(ItemID);
	if (!li)
		return "item not found";

	// try to get patron by id
	Patron *p = li->getCheckedOutBy();
	if (!p)
		return "item already in library";

	// remove item from patron's vector
	p->removeLibraryItem(li);
	li->setCheckedOutBy(NULL);

	// give item to the patron, who requested it
	p = li->getRequestedBy();
	if (p) 
	{
		li->setRequestedBy(NULL);
		li->setCheckedOutBy(p);
		p->addLibraryItem(li);
	}

	// change item location
	if (li->getLocation() == ON_SHELF)
		li->setLocation(ON_HOLD_SHELF);

	return "return successful";
}

// requests library item
string Library::requestLibraryItem(string patronID, string ItemID) 
{
	// try to get library item by id
	LibraryItem *li = getLibraryItem(ItemID);
	if (!li)
		return "item no found";

	// try to get patron by id
	Patron *p = getPatron(patronID);
	if (!p)
		return "patron not found";

	// check if item is already requested
	if (li->getRequestedBy())
		return "item already on hold";

	// request item
	li->setRequestedBy(p);
	if (li->getLocation() == ON_SHELF)
		li->setLocation(ON_HOLD_SHELF);

	return "request successful";
}

string Library::payFine(string patronID, double payment) 
{
	// try to get patron by id
	Patron *p = getPatron(patronID);
	if (!p)
		return "patron not found";

	p->amendFine(-payment);

	return "payment successful";
}

void Library::incrementCurrentDate() 
{
	// increment current date
	currentDate++;

	// amend fine for each patron
	int size1 = members.size();
	for (int i = 0; i < size1; ++i) 
	{
		Patron *p = members[i];
		vector<LibraryItem*> items = p->getCheckedOutItems();
		int size2 = items.size();

		for (int j = 0; j < size2; ++j) 
		{
			LibraryItem *li = items[j];
			if (currentDate - li->getDateCheckedOut() > li->getCheckOutLength()) 
			{
				p->amendFine(.1f);
			}
		}
	}
}

Patron* Library::getPatron(string patronID) 
{
	// searche for patron
	int size = members.size();
	for (int i = 0; i < size; ++i) 
	{
		if (members[i]->getIdNum() == patronID)
			return members[i];
	}

	// not found
	return NULL;
}

LibraryItem* Library::getLibraryItem(string ItemID) 
{
	// search for library item
	int size = holdings.size();
	for (int i = 0; i < size; ++i) 
	{
		if (holdings[i]->getIdCode() == ItemID)
			return holdings[i];
	}

	// not found
	return NULL;
}
